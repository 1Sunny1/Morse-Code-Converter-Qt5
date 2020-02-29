#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MorseCodeConverter.h"
#include "PushButtonHover.h"

#include <QString>
#include <QKeyEvent>
#include <QIcon>
#include <QPixmap>
#include <QtSvg/QtSvg>

namespace {
    const QString PLACEHOLDER_TEXT{"Type your message..."};

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->userText->setPlaceholderText(PLACEHOLDER_TEXT);
    ui->convertedText->setReadOnly(true);

    keyboard = std::make_unique<Keyboard>(ui->userText);
    keyboard->setStackedWidget(ui->stackedWidget);
    connectAllButtons();

    QIcon icon;
    QPixmap qxm;
    if(qxm.load(":/img/img/arrow.svg")) {
        icon.addPixmap(qxm);
        ui->pushButton->setIcon(icon);
        ui->pushButton->setIconSize(QSize(60, 60));
    }
    else
        ui->pushButton->setText("nope");

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_userText_textChanged() {
   ui->convertedText->clear();
   ui->convertedText->insertPlainText(MorseCodeConverter::TextToCode(Filter::ExcludeSpecialCharacters(ui->userText->toPlainText().toStdString())));
}
