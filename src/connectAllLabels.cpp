#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::connectAllLabels() {
    animatedBG->connectAnimation(AnimatedBackground::createAnimation(ui->label));
    animatedBG->connectAnimation(AnimatedBackground::createAnimation(ui->label_3));
    animatedBG->connectAnimation(AnimatedBackground::createAnimation(ui->label_4));
    animatedBG->connectAnimation(AnimatedBackground::createAnimation(ui->label_5));
    animatedBG->connectAnimation(AnimatedBackground::createAnimation(ui->label_6));
}
