#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QObject>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QStackedWidget>
#include <unordered_map>

class Keyboard final : public QObject {
    Q_OBJECT
public:
    enum class SpecialButtons {
        SPACE, DEL, SPECIALCHARACTERS, KEYBOARD, NONE
    };

public:
    explicit                Keyboard() = default;
    explicit                Keyboard(QPlainTextEdit *tE, QObject *parent = nullptr);
    void                    connectButton(QPushButton *);
    void                    setStackedWidget(QStackedWidget *);

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
