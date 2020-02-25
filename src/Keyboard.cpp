#include "Keyboard.h"

#include <QString>

Keyboard::Keyboard(QTextEdit *te) : textEdit(te) { }

void Keyboard::connectButton(QPushButton *button) {
    connect(button, &QPushButton::clicked, this, &Keyboard::onButtonClick);
}

void Keyboard::onButtonClick() {
    auto clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton->text() == "Space")
        textEdit->insertPlainText(" ");

    else if(clickedButton->text() == "Del")
        deletePreviousCharacter();

    else
        textEdit->insertPlainText(clickedButton->text());
}

void Keyboard::deletePreviousCharacter() {
    if (auto text = textEdit->toPlainText(); !text.isEmpty()) {
           text.chop(1);
           textEdit->clear();
           textEdit->insertPlainText(text);
       }
}
