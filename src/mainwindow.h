#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Keyboard.h"
#include "AnimatedBackground.h"

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

private:
    void                                    connectAllButtons();
    void                                    connectAllLabels();
    void                                    scrollToTheBottom();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Keyboard>               keyboard;
    std::unique_ptr<AnimatedBackground>     animatedBG;
    bool                                    toText{false};

};

#endif // MAINWINDOW_H
