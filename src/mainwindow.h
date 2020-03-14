#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Keyboard.h"
#include "AnimatedBackground.h"
#include "HelpButtons.h"

#include <QMainWindow>
#include <memory>

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
    void                                    on_pushButton_73_clicked();
    void                                    on_pushButton_71_clicked();
    void                                    on_keyboardControlButton_clicked();
    void                                    on_helpButton_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_clicked();

private:
    void                                    connectAllButtons();
    void                                    connectAllLabels();
    void                                    scrollToTheBottom();
    void                                    swapContent();
    void                                    hideScrollbars();

private:
    Ui::MainWindow *ui;
    Keyboard *                              keyboard;
    AnimatedBackground *                    animatedBG;
    HelpButtons *                           helpButtons;
    bool                                    toText{false};
    bool                                    isPushButton_73_pressed{false};
    bool                                    isPushButton_71_pressed{false};
};

#endif // MAINWINDOW_H
