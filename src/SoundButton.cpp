#include "SoundButton.h"
#include "ButtonAppearance.h"

SoundButton::SoundButton(std::vector<QPushButton *> &_buttons, QPlainTextEdit *tE, QObject *parent)
    : QObject(parent)
    , convertedText(tE) {
    std::copy(_buttons.begin(), _buttons.end(), std::back_inserter(buttons));
    sound = new Sound(convertedText, parent);
}

void SoundButton::connectButton(QPushButton *button) {
    connect(button, &QPushButton::clicked, this, &SoundButton::onButtonClick);
}

void SoundButton::onButtonClick() {
    auto button = qobject_cast<QPushButton *>(sender());
    ButtonLook::Standard::Pressed(button);
    setButtonsDefaultWithExceptionOf(button);

    if (button->text() == "Play")
        sound->play();

    else if (button->text() == "Pause")
        sound->stop();

    else
        sound->pause();
}

void SoundButton::setButtonsDefaultWithExceptionOf(QPushButton *exceptionalButton) {
    for(auto button : buttons) {
        if (button != exceptionalButton)
            ButtonLook::Standard::Default(button);
    }
}
