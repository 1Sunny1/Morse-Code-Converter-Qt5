#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFontDatabase::addApplicationFont(":/font/font/QuiteMagicalRegular-8VA2.ttf");
    QApplication::setFont(QFont("Quite Magical", 24, 1));

    w.show();
    return a.exec();
}
