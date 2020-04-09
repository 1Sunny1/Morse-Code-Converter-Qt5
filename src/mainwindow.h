#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Keyboard.h"
#include "AnimatedBackground.h"
#include "HelpButton.h"
#include "AboutButton.h"
#include "ConverterControlButton.h"
#include "Sound.h"
#include "SoundButton.h"

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

private:
    void                                    connectAllButtons();
    void                                    connectAllLabels();
    void                                    setupControlButtons();
    void                                    setupAboutTab();
    void                                    setupHelpTab();
    void                                    setupAnimatedBackground();
    void                                    setupSoundButtons();

private:
    Ui::MainWindow *                        ui;
    Keyboard *                              keyboard;
    AnimatedBackground *                    animatedBG;
    HelpButton *                            helpButton;
    AboutButton *                           aboutButton;
    ConverterControlButton *                converterControlButton;
    SoundButton *                           soundButton;

    bool *                                  toText;
    bool                                    isToTextButtonPressed{false};
    bool                                    isToCodeButtonPressed{true};
};

#endif // MAINWINDOW_H
