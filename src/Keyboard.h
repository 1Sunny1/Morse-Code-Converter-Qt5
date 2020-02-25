#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QObject>
#include <QPushButton>
#include <QTextEdit>

class Keyboard final : public QObject {
    Q_OBJECT
public:
    explicit Keyboard() = default;
    explicit Keyboard(QTextEdit *);
    void connectButton(QPushButton *);

private slots:
    void onButtonClick();

private:
    void deletePreviousCharacter();

private:
    std::unique_ptr<QTextEdit> textEdit;
};

#endif // KEYBOARD_H
