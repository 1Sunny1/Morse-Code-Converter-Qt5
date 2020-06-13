#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PushButtonHover.h"
#include "ButtonAppearance.h"
#include "Visuals.h"

#include <QGraphicsView>
#include <QSize>
#include <QPushButton>
#include <algorithm>

namespace {
    const QString PLACEHOLDER_TEXT{"Type your message..."};
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    toText =        new bool(false);
    keyboard =      new Keyboard(ui->userText, ui->stackedWidget, this);
    Converter =     new MorseCodeConverter(this);
    highlighter =   new Highlighter(toText, ui->userText->document());

    connect(ui->userText, &QPlainTextEdit::textChanged, this, &MainWindow::unrecognized_characters_notify);

    this->setFixedSize(QSize(1280, 720));
    ui->label_2->setGeometry(0,0, 1280, 720);
    ui->groupBox->hide();
    ui->aboutBox->hide();
    ui->unrecognized_characters_widget->hide();
    ui->userText->setPlaceholderText(PLACEHOLDER_TEXT);
    ui->convertedText->setReadOnly(true);

    Visuals::hideScrollBars(std::make_pair(ui->userText, ui->convertedText), ui->about);
    ButtonLook::Standard::Pressed(ui->toCodePushButton);
    ButtonLook::Standard::Pressed(ui->stopPushButton);

    setupAnimatedBackground();
    setupHelpTab();
    setupAboutTab();
    setupControlButtons();
    setupSoundButtons();

    connectAllButtons();
}

MainWindow::~MainWindow() {
    delete ui;
    delete toText;
}

void MainWindow::on_userText_textChanged() {
   ui->convertedText->clear();
   if (*toText)
       ui->convertedText->insertPlainText(Converter->CodeToText(ui->userText->toPlainText().toStdString()));
   else
       ui->convertedText->insertPlainText(Converter->TextToCode(Filter::ExcludeSpecialCharacters(ui->userText->toPlainText().toStdString())));

   Visuals::scrollToTheBottom(ui->convertedText);
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

void MainWindow::setupAnimatedBackground() {
    animatedBG = new AnimatedBackground(this);
    connectAllLabels();
}

void MainWindow::setupSoundButtons() {
    std::vector<QPushButton*> buttons{ ui->playPushButton, ui->pausePushButton, ui->stopPushButton };
    soundButton = new SoundButton(buttons, ui->convertedText, ui->userText, toText, this);
}

QString identify_characters_fill(std::string const& content) {
    using namespace std::string_literals;
    auto const codeCharacters{"._ /"s};
    std::size_t iterations = 0;
    QString unrecognized{""};

    for(auto const& character : content) {
        if (!std::any_of(codeCharacters.begin(), codeCharacters.end(), [&character](auto const& code){ return character == code; })) {
            if(iterations % 25 == 0)
                unrecognized += "\n";

            unrecognized += character;
            ++iterations;
        }
    }

    return unrecognized;
}

void MainWindow::unrecognized_characters_notify() {
    if (*toText) {
        auto const content = ui->userText->toPlainText().toStdString();
        QString unrecognizedCharsStr = identify_characters_fill(content);

        if (!unrecognizedCharsStr.isEmpty()) {
            ui->unrecognized_characters_widget->show();
            if (unrecognizedCharsStr.size() < 100)
                ui->label_67->setText(unrecognizedCharsStr);
        }
        else
            ui->unrecognized_characters_widget->hide();
    }
    else
        ui->unrecognized_characters_widget->hide();
}
