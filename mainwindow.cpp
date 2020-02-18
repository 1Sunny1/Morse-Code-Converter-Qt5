#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <memory>
#include <cctype>

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

void MainWindow::on_pushButton_1_clicked()
{
    ui->textEdit->insertPlainText("1");
    ui->textEdit_2->insertPlainText(morseCodes['1']);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->insertPlainText("2");
    ui->textEdit_2->insertPlainText(morseCodes['2']);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->insertPlainText("3");
    ui->textEdit_2->insertPlainText(morseCodes['3']);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->insertPlainText("4");
    ui->textEdit_2->insertPlainText(morseCodes['4']);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->insertPlainText("5");
    ui->textEdit_2->insertPlainText(morseCodes['5']);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->textEdit->insertPlainText("6");
    ui->textEdit_2->insertPlainText(morseCodes['6']);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->textEdit->insertPlainText("7");
    ui->textEdit_2->insertPlainText(morseCodes['7']);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->textEdit->insertPlainText("8");
    ui->textEdit_2->insertPlainText(morseCodes['8']);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->textEdit->insertPlainText("9");
    ui->textEdit_2->insertPlainText(morseCodes['9']);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->textEdit->insertPlainText("0");
    ui->textEdit_2->insertPlainText(morseCodes['0']);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->textEdit->insertPlainText("Q");
    ui->textEdit_2->insertPlainText(morseCodes['Q']);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->textEdit->insertPlainText("W");
    ui->textEdit_2->insertPlainText(morseCodes['W']);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->textEdit->insertPlainText("E");
    ui->textEdit_2->insertPlainText(morseCodes['E']);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->textEdit->insertPlainText("R");
    ui->textEdit_2->insertPlainText(morseCodes['R']);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->textEdit->insertPlainText("T");
    ui->textEdit_2->insertPlainText(morseCodes['T']);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->textEdit->insertPlainText("Y");
    ui->textEdit_2->insertPlainText(morseCodes['Y']);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->textEdit->insertPlainText("U");
    ui->textEdit_2->insertPlainText(morseCodes['U']);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->textEdit->insertPlainText("I");
    ui->textEdit_2->insertPlainText(morseCodes['I']);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->textEdit->insertPlainText("O");
    ui->textEdit_2->insertPlainText(morseCodes['O']);
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->textEdit->insertPlainText("P");
    ui->textEdit_2->insertPlainText(morseCodes['P']);
}

void MainWindow::on_textEdit_textChanged()
{
    std::string stdText = ui->textEdit->toPlainText().toStdString();
    if (!stdText.empty()) {
        char lastCharacter = stdText[stdText.length() - 1];
        if (isspace(lastCharacter))
            ui->textEdit_2->insertPlainText("     ");

        ui->textEdit_2->insertPlainText(morseCodes[toupper(lastCharacter)] + "  "); //nothing important is being lost due to implicit conversion!
    }
}
