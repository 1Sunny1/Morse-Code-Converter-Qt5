#include "ConverterControlButton.h"
#include "ButtonAppearance.h"

#include <QString>

ConverterControlButton::ConverterControlButton(bool *_toText, std::pair<PushButtonHover *, PushButtonHover *> &controlButtons, QObject *parent)
    : QObject(parent)
    , toText(_toText)
    , toCodeButton(controlButtons.first)
    , toTextButton(controlButtons.second) { }

void ConverterControlButton::connectButton(QPushButton *controlButton) {
    connect(controlButton, &QPushButton::clicked, this, &ConverterControlButton::onClick);
}

void ConverterControlButton::onClick() {
    auto button = qobject_cast<PushButtonHover *>(sender());

    if (button == toTextButton)
       handleToTextButton(button);

    else
       handleToCodeButton(button);
}

void ConverterControlButton::swapContent() {
    QString userTextContent = userText->toPlainText();
    QString convertedTextContent = convertedText->toPlainText();
    userText->setPlainText(convertedTextContent);
    convertedText->setPlainText(userTextContent);
}

void ConverterControlButton::handleToTextButton(QPushButton *button) {
    *toText = true;
    ButtonLook::Standard::Pressed(button);
    isToTextButtonPressed = true;
    if (isToCodeButtonPressed) {
        ButtonLook::Standard::Default(toCodeButton);
        isToCodeButtonPressed = false;
        swapContent();
    }
}

void ConverterControlButton::handleToCodeButton(QPushButton *button) {
    *toText = false;
    ButtonLook::Standard::Pressed(button);
    isToCodeButtonPressed = true;
    if (isToTextButtonPressed) {
        ButtonLook::Standard::Default(toTextButton);
        isToTextButtonPressed = false;
        swapContent();
    }
}

void ConverterControlButton::passPlainTextEdits(std::pair<QPlainTextEdit *, QPlainTextEdit *> &plainTextEdits) {
    userText = plainTextEdits.first;
    convertedText = plainTextEdits.second;
}
