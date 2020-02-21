#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MorseCodeConverter.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->convertedText->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_userText_textChanged() {
   ui->convertedText->clear();
   ui->convertedText->insertPlainText(MorseCodeConverter::TextToCode(MorseCodeConverter::ExcludeSpecialCharacters(ui->userText->toPlainText().toStdString())));
}
