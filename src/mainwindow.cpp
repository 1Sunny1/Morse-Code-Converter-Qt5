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
    ui->userText->insertPlainText("1");
    ui->convertedText->insertPlainText(morseCodes['1']);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->userText->insertPlainText("2");
    ui->convertedText->insertPlainText(morseCodes['2']);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->userText->insertPlainText("3");
    ui->convertedText->insertPlainText(morseCodes['3']);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->userText->insertPlainText("4");
    ui->convertedText->insertPlainText(morseCodes['4']);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->userText->insertPlainText("5");
    ui->convertedText->insertPlainText(morseCodes['5']);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->userText->insertPlainText("6");
    ui->convertedText->insertPlainText(morseCodes['6']);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->userText->insertPlainText("7");
    ui->convertedText->insertPlainText(morseCodes['7']);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->userText->insertPlainText("8");
    ui->convertedText->insertPlainText(morseCodes['8']);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->userText->insertPlainText("9");
    ui->convertedText->insertPlainText(morseCodes['9']);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->userText->insertPlainText("0");
    ui->convertedText->insertPlainText(morseCodes['0']);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->userText->insertPlainText("Q");
    ui->convertedText->insertPlainText(morseCodes['Q']);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->userText->insertPlainText("W");
    ui->convertedText->insertPlainText(morseCodes['W']);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->userText->insertPlainText("E");
    ui->convertedText->insertPlainText(morseCodes['E']);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->userText->insertPlainText("R");
    ui->convertedText->insertPlainText(morseCodes['R']);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->userText->insertPlainText("T");
    ui->convertedText->insertPlainText(morseCodes['T']);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->userText->insertPlainText("Y");
    ui->convertedText->insertPlainText(morseCodes['Y']);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->userText->insertPlainText("U");
    ui->convertedText->insertPlainText(morseCodes['U']);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->userText->insertPlainText("I");
    ui->convertedText->insertPlainText(morseCodes['I']);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->userText->insertPlainText("O");
    ui->convertedText->insertPlainText(morseCodes['O']);
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->userText->insertPlainText("P");
    ui->convertedText->insertPlainText(morseCodes['P']);
}

void MainWindow::on_userText_textChanged()
{
    convertToMorseCode();
}

void MainWindow::convertToMorseCode() {
    ui->convertedText->clear();
    std::string stdText = ui->userText->toPlainText().toStdString();
    for (const auto &character : stdText) {
        if (auto found = std::find_if(
                morseCodes.begin(), morseCodes.end(),
                [&character](const auto &value) { return toupper(character) == value.first; });
            found != morseCodes.end())
            ui->convertedText->insertPlainText((found->second) + "  ");
    }
}
