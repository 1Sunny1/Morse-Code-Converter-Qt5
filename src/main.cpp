#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFontDatabase::addApplicationFont(":/font/font/QuiteMagicalRegular-8VA2.ttf");
    QApplication::setFont(QFont("Quite Magical", 24, 1));
    a.setWindowIcon(QIcon(":/img/img/mc_icon.png"));
    w.setWindowTitle("This lil converter ain't much, but honest work C:");
    w.show();
    return a.exec();
}
