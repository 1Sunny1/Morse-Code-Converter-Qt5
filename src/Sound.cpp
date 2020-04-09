#include "Sound.h"

#include <QMediaPlaylist>
#include <QMediaContent>

Sound::Sound(QPlainTextEdit *textEdit, QObject *parent)
    : QMediaPlayer(parent)
    , convertedText(textEdit)
    , sounds(nullptr) {
     playlist = new QMediaPlaylist(this);
     sounds = new QMediaPlayer(this, QMediaPlayer::LowLatency);
}

void Sound::play() {
    if (!playPressed) {
        playPressed = true;
        playlist->clear();   

        fillPlaylist(playlist);
        sounds->setPlaylist(playlist);
        sounds->play();
    }//TODO: SPEED IT UP! ...somehow
}

void Sound::stop() {
    if (playPressed)
        sounds->stop();

    playPressed = false;
}

void Sound::pause() {
    if (playPressed)
        sounds->stop();

    playPressed = false;
    //save current index of text and after playing again start from this index
}

void Sound::fillPlaylist(QMediaPlaylist *playlist) {
    QString text = convertedText->toPlainText();
    if (!text.isEmpty()) {
        static QString::iterator soundIterator;
        for (auto character = std::begin(text); character != std::end(text); ++character) {
            soundIterator = character;
            if(*character == '.')
                playlist->addMedia(shortSound);
            else if (*character == '_')
                playlist->addMedia(longSound);
            else
                playlist->addMedia(blankSound);
        }
    }
}
