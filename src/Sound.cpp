#include "Sound.h"

#include <QMediaPlaylist>
#include <QMediaContent>
#include <iterator>

Sound::Sound(QPlainTextEdit *textEdit, QObject *parent)
    : QMediaPlayer(parent)
    , convertedText(textEdit)
    , sounds(nullptr) {
     playlist_ = new QMediaPlaylist(this);
     sounds = new QMediaPlayer(this, QMediaPlayer::LowLatency);
     sounds->setPlaybackRate(1.2);
}

void Sound::fillPlaylist(QMediaPlaylist *playlist) {
    text = convertedText->toPlainText();
    if (!text.isEmpty()) {
        for (auto character = std::begin(text); character != std::end(text); ++character) {
            if(*character == '.')
                playlist->addMedia(shortSound);
            else if (*character == '_')
                playlist->addMedia(longSound);
            else
                playlist->addMedia(blankSound);
        }
    }
}

void Sound::refillPlaylist() {
    auto character = std::begin(text);
    std::advance(character,  indexAtPause);
    for (; character != std::end(text); ++character) {
        if(*character == '.')
            playlist_->addMedia(shortSound);
        else if (*character == '_')
            playlist_->addMedia(longSound);
        else
            playlist_->addMedia(blankSound);
    }
}

void Sound::play() {
    if (paused && !playPressed) {
        playPressed = true;
        paused = false;
        playlist_->clear();

        refillPlaylist();
        sounds->play();
    }

    else if (!playPressed) {
        playPressed = true;
        playlist_->clear();

        fillPlaylist(playlist_);
        sounds->setPlaylist(playlist_);
        sounds->play();

    }
}

void Sound::stop() {  
    sounds->stop();
    playlist_->clear();
    playPressed = false;
    indexAtPause = 0;
}

void Sound::pause() {
    if (playPressed) {
        paused = true;
        playPressed = false;
        sounds->stop();
        indexAtPause = playlist_->currentIndex();
    }
}

void Sound::setPlayPressedFalse() {
    playPressed = false;
}

QMediaPlaylist* Sound::playlist() const {
    return playlist_;
}
