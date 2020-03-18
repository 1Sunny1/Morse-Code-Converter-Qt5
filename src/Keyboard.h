#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "IConnectButton.h"

#include <QObject>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QStackedWidget>
#include <unordered_map>

class Keyboard final : public QObject, public IConnectButton {
    Q_OBJECT
public:
    enum class SpecialButtons {
        SPACE, DEL, SPECIALCHARACTERS, KEYBOARD, NONE
    };

public:
    explicit                Keyboard() = default;
    explicit                Keyboard(QPlainTextEdit *tE, QStackedWidget * sW, QObject *parent = nullptr);
    void                    connectButton(QPushButton *) override;

private slots:
    void                    onButtonClick();

private:
    void                    deletePreviousCharacter();
    void                    triggerOtherSideOfKeyboard();
    void                    initializeSpecialButtonsMap();
    SpecialButtons          manageButtonValue(QPushButton *);

private:
    QPlainTextEdit *                                    textEdit;
    QStackedWidget *                                    stackedWidget;
    std::unordered_map<SpecialButtons, QString>         specialButtons;
};

#endif // KEYBOARD_H
