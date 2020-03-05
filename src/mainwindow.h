#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include "Keyboard.h"
#include "AnimatedBackground.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
                                            MainWindow(QWidget *parent = nullptr);
                                            ~MainWindow();

private slots:
    void                                    on_userText_textChanged();


private:
    void                                    connectAllButtons();
    void                                    connectAllLabels();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Keyboard>               keyboard;
    std::unique_ptr<AnimatedBackground>     animatedBG;
};

#endif // MAINWINDOW_H
