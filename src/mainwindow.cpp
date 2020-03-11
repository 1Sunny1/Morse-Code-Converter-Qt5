#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MorseCodeConverter.h"
#include "PushButtonHover.h"

#include <QGraphicsView>
#include <QSize>

namespace {
    const QString PLACEHOLDER_TEXT{"Type your message..."};
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setFixedSize(QSize(1280, 720));
    ui->label_2->setGeometry(0,0, 1280, 720);

    ui->userText->setPlaceholderText(PLACEHOLDER_TEXT);
    ui->convertedText->setReadOnly(true);

    ui->userText->ensureCursorVisible();
    ui->userText->setCenterOnScroll(true);

    ui->convertedText->verticalScrollBar()->hide();
    ui->userText->verticalScrollBar()->hide();

    keyboard = std::make_unique<Keyboard>(ui->userText);
    keyboard->setStackedWidget(ui->stackedWidget);
    connectAllButtons();

    animatedBG = std::make_unique<AnimatedBackground>();
    connectAllLabels();

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

void MainWindow::on_pushButton_73_clicked() {
    toText = true;
    //do some visual changes
}

void MainWindow::on_pushButton_71_clicked() {
    toText = false;
    //do some visual changes
}

void MainWindow::on_keyboardControlButton_clicked()
{
   if(ui->stackedWidget->currentIndex() != 2) {
       ui->stackedWidget->setCurrentIndex(2); //hide
       ui->keyboardControlButton->setText("Show keyboard");
   }
   else {
       ui->stackedWidget->setCurrentIndex(0); //show
       ui->keyboardControlButton->setText("Hide Keyboard");
   }
}
