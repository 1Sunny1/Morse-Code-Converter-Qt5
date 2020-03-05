#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::connectAllLabels() {
    std::pair<int, int> windowDimensions(this->height(), this->width());
    animatedBG->connectAnimation(AnimatedBackground::createAnimation(ui->label, windowDimensions));
}
