#ifndef SOUND_H
#define SOUND_H

#include <QObject>
#include <QPlainTextEdit>
#include <QMediaPlayer>
#include <QSoundEffect>

class Sound final : public QMediaPlayer {
    Q_OBJECT
public:
    explicit                        Sound(QPlainTextEdit *textEdit, QObject *parent = nullptr);
    void                            setPlayPressedFalse();

public slots:
    void                            play();
    void                            stop();
    void                            pause();

private:
    void                            fillPlaylist(QMediaPlaylist *);
    void                            refillPlaylist();

private:
    QPlainTextEdit *                convertedText;
    QMediaPlayer *                  sounds;
    QMediaPlaylist *                playlist;
    QString                         text;
    int                             indexAtPause;

    const QUrl                      shortSound { "qrc:/sfx/sfx/short.wav" };
    const QUrl                      longSound  { "qrc:/sfx/sfx/long.wav"  };
    const QUrl                      blankSound { "qrc:/sfx/sfx/break.wav" };
    bool                            playPressed{false};
    bool                            paused{false};
};

#endif // SOUND_H
