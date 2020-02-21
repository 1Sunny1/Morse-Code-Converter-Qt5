#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

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

void MainWindow::on_pushButton_21_clicked() {
    ui->userText->insertPlainText("A");
}

void MainWindow::on_pushButton_22_clicked() {
    ui->userText->insertPlainText("S");
}

void MainWindow::on_pushButton_23_clicked() {
    ui->userText->insertPlainText("D");
}

void MainWindow::on_pushButton_24_clicked() {
    ui->userText->insertPlainText("F");
}

void MainWindow::on_pushButton_25_clicked() {
    ui->userText->insertPlainText("G");
}

void MainWindow::on_pushButton_26_clicked() {
    ui->userText->insertPlainText("H");
}

void MainWindow::on_pushButton_27_clicked() {
    ui->userText->insertPlainText("J");
}

void MainWindow::on_pushButton_28_clicked() {
    ui->userText->insertPlainText("K");
}

void MainWindow::on_pushButton_29_clicked() {
    ui->userText->insertPlainText("L");
}

void MainWindow::on_pushButton_36_clicked() {
    ui->userText->insertPlainText("Z");
}

void MainWindow::on_pushButton_35_clicked() {
    ui->userText->insertPlainText("X");
}

void MainWindow::on_pushButton_34_clicked() {
    ui->userText->insertPlainText("C");
}

void MainWindow::on_pushButton_33_clicked() {
    ui->userText->insertPlainText("V");
}

void MainWindow::on_pushButton_32_clicked() {
    ui->userText->insertPlainText("B");
}

void MainWindow::on_pushButton_31_clicked() {
    ui->userText->insertPlainText("N");
}

void MainWindow::on_pushButton_30_clicked() {
    ui->userText->insertPlainText("M");
}

void MainWindow::on_pushButton_43_clicked() {
    if (auto text = ui->userText->toPlainText(); !text.isEmpty()) {
        text.chop(1);
        ui->userText->clear();
        ui->userText->insertPlainText(text);
    }
}

void MainWindow::on_pushButton_38_clicked() {
    ui->userText->insertPlainText(" ");
}

void MainWindow::on_pushButton_40_clicked() {
    ui->userText->insertPlainText(".");
}

void MainWindow::on_pushButton_41_clicked() {
    ui->userText->insertPlainText("?");
}

void MainWindow::on_pushButton_37_clicked() {
    ui->userText->insertPlainText("/");
}

void MainWindow::on_pushButton_39_clicked() {
    ui->userText->insertPlainText(",");
}

void MainWindow::on_pushButton_42_clicked() {
   //new page that contains more characters
}
