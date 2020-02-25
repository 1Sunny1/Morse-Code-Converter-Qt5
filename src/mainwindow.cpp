#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MorseCodeConverter.h"

#include <QString>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->convertedText->setReadOnly(true);

    connectAllButtons();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_userText_textChanged() {
   ui->convertedText->clear();
   ui->convertedText->insertPlainText(MorseCodeConverter::TextToCode(Filter::ExcludeSpecialCharacters(ui->userText->toPlainText().toStdString())));
}

void MainWindow::connectAllButtons() {
    keyboard = std::make_unique<Keyboard>(ui->userText);
    keyboard->connectButton(ui->pushButton_1);
    keyboard->connectButton(ui->pushButton_2);
    keyboard->connectButton(ui->pushButton_3);
    keyboard->connectButton(ui->pushButton_4);
    keyboard->connectButton(ui->pushButton_5);
    keyboard->connectButton(ui->pushButton_6);
    keyboard->connectButton(ui->pushButton_7);
    keyboard->connectButton(ui->pushButton_8);
    keyboard->connectButton(ui->pushButton_9);
    keyboard->connectButton(ui->pushButton_10);
    keyboard->connectButton(ui->pushButton_11);
    keyboard->connectButton(ui->pushButton_12);
    keyboard->connectButton(ui->pushButton_13);
    keyboard->connectButton(ui->pushButton_14);
    keyboard->connectButton(ui->pushButton_15);
    keyboard->connectButton(ui->pushButton_16);
    keyboard->connectButton(ui->pushButton_17);
    keyboard->connectButton(ui->pushButton_18);
    keyboard->connectButton(ui->pushButton_19);
    keyboard->connectButton(ui->pushButton_20);
    keyboard->connectButton(ui->pushButton_21);
    keyboard->connectButton(ui->pushButton_22);
    keyboard->connectButton(ui->pushButton_23);
    keyboard->connectButton(ui->pushButton_24);
    keyboard->connectButton(ui->pushButton_25);
    keyboard->connectButton(ui->pushButton_26);
    keyboard->connectButton(ui->pushButton_27);
    keyboard->connectButton(ui->pushButton_28);
    keyboard->connectButton(ui->pushButton_29);
    keyboard->connectButton(ui->pushButton_30);
    keyboard->connectButton(ui->pushButton_31);
    keyboard->connectButton(ui->pushButton_32);
    keyboard->connectButton(ui->pushButton_33);
    keyboard->connectButton(ui->pushButton_34);
    keyboard->connectButton(ui->pushButton_35);
    keyboard->connectButton(ui->pushButton_36);
    keyboard->connectButton(ui->pushButton_37);
    keyboard->connectButton(ui->pushButton_38);
    keyboard->connectButton(ui->pushButton_39);
    keyboard->connectButton(ui->pushButton_40);
    keyboard->connectButton(ui->pushButton_41);
    keyboard->connectButton(ui->pushButton_42);
    keyboard->connectButton(ui->pushButton_43);
}
