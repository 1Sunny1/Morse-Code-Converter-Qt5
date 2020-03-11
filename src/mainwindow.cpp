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

void leaveButtonLookLikePressed(PushButtonHover *button) {
    button->setStyleSheet("QPushButton { border: 2px solid #ff6666; border-radius: 11px; background-color: #f5f5dc; font-size: 20px; } QPushButton:hover { background-color: #f5f5dc; border: 2px solid #ff6666; } QPushButton:pressed { border: 2px solid #ff6666; }");
}

void leaveButtonLookDefault(PushButtonHover *button) {
    button->setStyleSheet("QPushButton { border: 1px solid #f0eeee; border-radius: 11px; background-color: #f0eeee; font-size: 20px; } QPushButton:hover { background-color: #f5f5dc; border: 2px solid #f5f5dc; } QPushButton:pressed { border: 2px solid #ff6666; }");
}

void MainWindow::swapContent() {
    QString userTextContent = ui->userText->toPlainText();
    QString convertedTextContent = ui->convertedText->toPlainText();
    ui->userText->setPlainText(convertedTextContent);
    ui->convertedText->setPlainText(userTextContent.toUpper());
}

void MainWindow::on_pushButton_73_clicked() {
    toText = true;
    leaveButtonLookLikePressed(ui->pushButton_73);
    isPushButton_73_pressed = true;
    if (isPushButton_71_pressed) {
        leaveButtonLookDefault(ui->pushButton_71);
        isPushButton_71_pressed = false;
        swapContent();
    }
}

void MainWindow::on_pushButton_71_clicked() {
    toText = false;
    leaveButtonLookLikePressed(ui->pushButton_71);
    isPushButton_71_pressed = true;
    if (isPushButton_73_pressed) {
        leaveButtonLookDefault(ui->pushButton_73);
        isPushButton_73_pressed = false;
        swapContent();
    }
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
