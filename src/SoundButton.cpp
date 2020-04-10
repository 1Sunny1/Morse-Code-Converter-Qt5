#include "SoundButton.h"
#include "ButtonAppearance.h"

SoundButton::SoundButton(std::vector<QPushButton *> &_buttons, QPlainTextEdit *tE, QObject *parent)
    : QObject(parent)
    , convertedText(tE) {
    std::copy(_buttons.begin(), _buttons.end(), std::back_inserter(buttons));
    sound = new Sound(convertedText, parent);
    //connect with QMediaPlayer inside Sound class
    connect(sound, &QMediaPlayer::stateChanged, this, &SoundButton::setStopButtonPressed);
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
        sound->pause();

    else
        sound->stop();
}

void SoundButton::setButtonsDefaultWithExceptionOf(QPushButton *exceptionalButton) {
    for(auto button : buttons) {
        if (button != exceptionalButton)
            ButtonLook::Standard::Default(button);
    }
}

void SoundButton::setStopButtonPressed(QMediaPlayer::State state) {
    ButtonLook::Standard::Pressed(buttons[2]);
    if (state == QMediaPlayer::StoppedState) {
        ButtonLook::Standard::Pressed(buttons[2]); //stop button
        ButtonLook::Standard::Default(buttons[0]); //playbutton
        sound->setPlayPressedFalse();
    }
}
