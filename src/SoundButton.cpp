#include "SoundButton.h"
#include "ButtonAppearance.h"
#include <QMediaPlaylist>

SoundButton::SoundButton(std::vector<QPushButton *> const& buttons_, QPlainTextEdit *tE, QObject *parent)
    : QObject(parent)
    , convertedText(tE) {
    std::copy(buttons_.begin(), buttons_.end(), std::back_inserter(buttons));
    sound = new Sound(convertedText, parent);
    connect(sound->playlist(), &QMediaPlaylist::currentIndexChanged, this, &SoundButton::setButtonsDefaultAfterPlaying);
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

void SoundButton::setButtonsDefaultAfterPlaying(int position) {
    if (position == -1) {
        ButtonLook::Standard::Pressed(buttons[2]); //stop button
        ButtonLook::Standard::Default(buttons[0]); //playbutton
        sound->setPlayPressedFalse();
    }
}
