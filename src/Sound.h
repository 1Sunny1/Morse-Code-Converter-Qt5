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

public slots:
    void                            play();
    void                            stop();
    void                            pause();

private:
    QPlainTextEdit *                convertedText;
    QMediaPlayer *                  sounds;
    QMediaPlaylist *                playlist;
    const QUrl                      shortSound { "qrc:/sfx/sfx/short.wav" };
    const QUrl                      longSound  { "qrc:/sfx/sfx/long.wav"  };
    const QUrl                      blankSound { "qrc:/sfx/sfx/break.wav" };
    bool                            playPressed{false};
};

#endif // SOUND_H
