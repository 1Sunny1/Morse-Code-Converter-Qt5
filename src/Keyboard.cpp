#include "Keyboard.h"

#include <QString>

Keyboard::Keyboard(QPlainTextEdit *te, QStackedWidget *sW, QObject *parent)
    : QObject(parent)
    , textEdit(te)
    , stackedWidget(sW) {
    initializeSpecialButtonsMap();
}

void Keyboard::connectButton(QPushButton *button) {
    connect(button, &QPushButton::clicked, this, &Keyboard::onButtonClick);
}

void Keyboard::onButtonClick() {
    auto clickedButton = qobject_cast<QPushButton*>(sender());

    switch(manageButtonValue(clickedButton)) {
        case SpecialButtons::DEL:
            deletePreviousCharacter();
            break;
        case SpecialButtons::SPACE:
            textEdit->insertPlainText(" ");
            break;
        case SpecialButtons::SPECIALCHARACTERS:
            [[fallthrough]];
        case SpecialButtons::KEYBOARD:
            triggerOtherSideOfKeyboard();
            break;
        case SpecialButtons::NONE:
            textEdit->insertPlainText(clickedButton->text());
    }
}

void Keyboard::deletePreviousCharacter() {
    if (auto text = textEdit->toPlainText(); !text.isEmpty()) {
           text.chop(1);
           textEdit->clear();
           textEdit->insertPlainText(text);
       }
}

void Keyboard::triggerOtherSideOfKeyboard() {
    if (stackedWidget->currentIndex() == 1)
        stackedWidget->setCurrentIndex(0);
    else
        stackedWidget->setCurrentIndex(1);
}

void Keyboard::initializeSpecialButtonsMap() {
    specialButtons.insert(std::make_pair(SpecialButtons::DEL,                   "DEL"));
    specialButtons.insert(std::make_pair(SpecialButtons::SPACE,                 "SPACE"));
    specialButtons.insert(std::make_pair(SpecialButtons::KEYBOARD,              "ABC"));
    specialButtons.insert(std::make_pair(SpecialButtons::SPECIALCHARACTERS,     "!#1"));
}

Keyboard::SpecialButtons Keyboard::manageButtonValue(QPushButton *pushButton) {
    if (auto buttonCommand =
            std::find_if(specialButtons.begin(), specialButtons.end(),
                         [=](const auto &value) {
                           return pushButton->text().toUpper() == value.second;
                         });
            buttonCommand != specialButtons.end())
        return buttonCommand->first;

    else
        return SpecialButtons::NONE;
}
