#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Keyboard.h"
#include "AnimatedBackground.h"
#include "HelpButton.h"
#include "AboutButton.h"

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
    void                                    on_toTextPushButton_clicked();
    void                                    on_toCodePushButton_clicked();
    void                                    on_keyboardControlButton_clicked();
    void                                    on_helpButton_clicked();

private:
    void                                    connectAllButtons();
    void                                    connectAllLabels();
    void                                    scrollToTheBottom();
    void                                    swapContent();
    void                                    hideScrollbars();

private:
    Ui::MainWindow                          *ui;
    Keyboard *                              keyboard;
    AnimatedBackground *                    animatedBG;
    HelpButton *                            helpButton;
    AboutButton *                           aboutButton;

    bool                                    toText{false};
    bool                                    isToTextButtonPressed{false};
    bool                                    isToCodeButtonPressed{true};
};

#endif // MAINWINDOW_H
