#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MorseCodeConverter.h"
#include "PushButtonHover.h"
#include "ButtonAppearance.h"

#include <QGraphicsView>
#include <QSize>
#include <QPushButton>

namespace {
    const QString PLACEHOLDER_TEXT{"Type your message..."};
}

void hideScrollBars(std::pair<QPlainTextEdit *, QPlainTextEdit *> textEdits, QTextBrowser *browser); //move to some namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    toText = new bool(false);
    this->setFixedSize(QSize(1280, 720));
    ui->label_2->setGeometry(0,0, 1280, 720);
    ui->groupBox->hide();
    ui->aboutBox->hide();
    ui->userText->setPlaceholderText(PLACEHOLDER_TEXT);
    ui->convertedText->setReadOnly(true);

    hideScrollBars(std::make_pair(ui->userText, ui->convertedText), ui->about);

    ButtonLook::Standard::Pressed(ui->toCodePushButton);

    //makeAnimatedBackground();
    animatedBG = new AnimatedBackground(this);
    connectAllLabels();

    keyboard = new Keyboard(ui->userText, ui->stackedWidget, this);

    setupHelpTab();

    setupAboutTab();

    setupControlButtons();

    connectAllButtons();
}

MainWindow::~MainWindow() {
    delete ui;
    delete toText;
}

void MainWindow::on_userText_textChanged() {
   ui->convertedText->clear();
   if (*toText)
       ui->convertedText->insertPlainText(MorseCodeConverter::CodeToText(ui->userText->toPlainText().toStdString()));
   else
       ui->convertedText->insertPlainText(MorseCodeConverter::TextToCode(Filter::ExcludeSpecialCharacters(ui->userText->toPlainText().toStdString())));

   scrollToTheBottom();
}

void MainWindow::scrollToTheBottom() {
    QScrollBar *scrollbar = ui->convertedText->verticalScrollBar();
    bool scrollbarAtBottom  = (scrollbar->value() >= (scrollbar->maximum() - 4));
    ui->convertedText->moveCursor(QTextCursor::End);
    if (scrollbarAtBottom)
        ui->convertedText->ensureCursorVisible();
}

void MainWindow::setupControlButtons() {
    auto controlButtons = std::make_pair(ui->toCodePushButton, ui->toTextPushButton);
    converterControlButton = new ConverterControlButton(toText, controlButtons, this);
    auto plainTextEdits = std::pair(ui->userText, ui->convertedText);
    converterControlButton->passPlainTextEdits(plainTextEdits);
}

void MainWindow::setupAboutTab() {
    aboutButton = new AboutButton(ui->about,ui->aboutBox, this);
    std::vector<QPushButton*> aboutButtons {ui->aboutButton_1, ui->aboutButton_2, ui->aboutButton_3};
    aboutButton->passAboutButtons(aboutButtons);
}

void MainWindow::setupHelpTab() {
    helpButton = new HelpButton(ui->userText, ui->groupBox, this);
    helpButton->passHelpButton(ui->helpButton);
}

void hideScrollBars(std::pair<QPlainTextEdit *, QPlainTextEdit *> textEdits, QTextBrowser *aboutBrowser) {
    textEdits.first->ensureCursorVisible();
    textEdits.first->setCenterOnScroll(true);

    textEdits.second->verticalScrollBar()->hide();
    textEdits.first->verticalScrollBar()->hide();

    aboutBrowser->verticalScrollBar()->hide();
}
