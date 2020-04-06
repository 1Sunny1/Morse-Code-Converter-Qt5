#include "SoundButton.h"

SoundButton::SoundButton(QPlainTextEdit *tE, QObject *parent)
    : QObject(parent)
    , convertedText(tE) {
    sound = new Sound(convertedText, parent);
}

void SoundButton::connectButton(QPushButton *button) {
    connect(button, &QPushButton::clicked, this, &SoundButton::onButtonClick);
}

void SoundButton::onButtonClick() {
    auto button = qobject_cast<QPushButton *>(sender());
    //if (button->text == "Play") :
        //sound->play();
    //else if (button->text == "Pause")
        //sound->stop();
    //else
        //sound->Plause();
}
