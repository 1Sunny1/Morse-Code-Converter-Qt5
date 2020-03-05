#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QObject>
#include <QPushButton>
#include <QTextEdit>
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
    explicit                Keyboard(QTextEdit *);
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
    std::unique_ptr<QTextEdit>                          textEdit;
    std::unique_ptr<QStackedWidget>                     stackedWidget;
    std::unordered_map<SpecialButtons, QString>         specialButtons;

};

#endif // KEYBOARD_H
