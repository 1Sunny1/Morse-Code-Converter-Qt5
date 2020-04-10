#ifndef SOUNDBUTTON_H
#define SOUNDBUTTON_H

#include "IConnectButton.h"
#include "Sound.h"

#include <QPlainTextEdit>
#include <QPushButton>
#include <vector>

class SoundButton final : public QObject, public IConnectButton {
    Q_OBJECT
public:
    explicit                    SoundButton(std::vector<QPushButton*>&, QPlainTextEdit *tE, QObject *parent = nullptr);
    virtual void                connectButton(QPushButton *) override;

private slots:
    void                        onButtonClick();
    void                        setButtonsDefaultWithExceptionOf(QPushButton *exceptionalButton = nullptr);
    void                        setStopButtonPressed(QMediaPlayer::State);

private:
    Sound *                     sound;
    QPlainTextEdit *            convertedText;
    std::vector<QPushButton *>  buttons;
};

#endif // SOUNDBUTTON_H
