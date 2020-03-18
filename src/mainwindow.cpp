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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->setFixedSize(QSize(1280, 720));
    ui->label_2->setGeometry(0,0, 1280, 720);
    ui->groupBox->hide();
    ui->aboutBox->hide();
    ui->userText->setPlaceholderText(PLACEHOLDER_TEXT);
    ui->convertedText->setReadOnly(true);
    hideScrollbars();
    ButtonLook::Standard::Pressed(ui->toCodePushButton);

    //makeAnimatedBackground();
    animatedBG = new AnimatedBackground(this);
    connectAllLabels();
    //makeKeyboard();
    keyboard = new Keyboard(ui->userText, ui->stackedWidget, this);
    //makeHelpTab();
    helpButton = new HelpButton(ui->userText, ui->groupBox, this);
    helpButton->passHelpButton(ui->helpButton);
    //makeAboutTab();
    aboutButton = new AboutButton(ui->about,ui->aboutBox, this);
    std::vector<QPushButton*> aboutButtons {ui->aboutButton_1, ui->aboutButton_2, ui->aboutButton_3};
    aboutButton->passAboutButtons(aboutButtons);

    connectAllButtons();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_userText_textChanged() {
   ui->convertedText->clear();
   if (toText)
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

void MainWindow::swapContent() {
    QString userTextContent = ui->userText->toPlainText();
    QString convertedTextContent = ui->convertedText->toPlainText();
    ui->userText->setPlainText(convertedTextContent);
    ui->convertedText->setPlainText(userTextContent.toUpper());
}

void MainWindow::hideScrollbars() {
    ui->userText->ensureCursorVisible();
    ui->userText->setCenterOnScroll(true);

    ui->convertedText->verticalScrollBar()->hide();
    ui->userText->verticalScrollBar()->hide();

    ui->about->verticalScrollBar()->hide();
}

void MainWindow::on_toTextPushButton_clicked() {
    toText = true;
    ButtonLook::Standard::Pressed(ui->toTextPushButton);
    isToTextButtonPressed = true;
    if (isToCodeButtonPressed) {
        ButtonLook::Standard::Default(ui->toCodePushButton);
        isToCodeButtonPressed = false;
        swapContent();
    }
}

void MainWindow::on_toCodePushButton_clicked() {
    toText = false;
    ButtonLook::Standard::Pressed(ui->toCodePushButton);
    isToCodeButtonPressed = true;
    if (isToTextButtonPressed) {
        ButtonLook::Standard::Default(ui->toTextPushButton);
        isToTextButtonPressed = false;
        swapContent();
    }
}

void MainWindow::on_keyboardControlButton_clicked()
{
   if(ui->stackedWidget->currentIndex() != 2) {
       ui->stackedWidget->setCurrentIndex(2);
       ui->keyboardControlButton->setText("Show keyboard");
   }
   else {
       ui->stackedWidget->setCurrentIndex(0);
       ui->keyboardControlButton->setText("Hide Keyboard");
   }
}

void MainWindow::on_helpButton_clicked() {
    ui->groupBox->show();
    ButtonLook::Standard::Pressed(ui->helpButton);
}
