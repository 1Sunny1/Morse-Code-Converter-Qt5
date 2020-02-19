#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MorseCodeConverter.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked() {
    ui->userText->insertPlainText("1");
}

void MainWindow::on_pushButton_2_clicked() {
    ui->userText->insertPlainText("2");
}

void MainWindow::on_pushButton_3_clicked() {
    ui->userText->insertPlainText("3");
}

void MainWindow::on_pushButton_4_clicked() {
    ui->userText->insertPlainText("4");
}

void MainWindow::on_pushButton_5_clicked() {
    ui->userText->insertPlainText("5");
}

void MainWindow::on_pushButton_6_clicked() {
    ui->userText->insertPlainText("6");
}

void MainWindow::on_pushButton_7_clicked() {
    ui->userText->insertPlainText("7");
}

void MainWindow::on_pushButton_8_clicked() {
    ui->userText->insertPlainText("8");
}

void MainWindow::on_pushButton_9_clicked() {
    ui->userText->insertPlainText("9");
}

void MainWindow::on_pushButton_10_clicked() {
    ui->userText->insertPlainText("0");
}

void MainWindow::on_pushButton_11_clicked() {
    ui->userText->insertPlainText("Q");
}

void MainWindow::on_pushButton_12_clicked() {
    ui->userText->insertPlainText("W");
}

void MainWindow::on_pushButton_13_clicked() {
    ui->userText->insertPlainText("E");
}
void MainWindow::on_pushButton_14_clicked() {
    ui->userText->insertPlainText("R");
}

void MainWindow::on_pushButton_15_clicked() {
    ui->userText->insertPlainText("T");
}

void MainWindow::on_pushButton_16_clicked() {
    ui->userText->insertPlainText("Y");
}

void MainWindow::on_pushButton_17_clicked() {
    ui->userText->insertPlainText("U");
}

void MainWindow::on_pushButton_18_clicked() {
    ui->userText->insertPlainText("I");
}

void MainWindow::on_pushButton_19_clicked() {
    ui->userText->insertPlainText("O");
}

void MainWindow::on_pushButton_20_clicked() {
    ui->userText->insertPlainText("P");
}

void MainWindow::on_userText_textChanged() {
   ui->convertedText->clear();
   ui->convertedText->insertPlainText(MorseCodeConverter::TextToCode(ui->userText->toPlainText()));
}

