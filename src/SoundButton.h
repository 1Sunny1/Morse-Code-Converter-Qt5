#ifndef SOUNDBUTTON_H
#define SOUNDBUTTON_H

#include "IConnectButton.h"
#include "Sound.h"

#include <QPlainTextEdit>
#include <QPushButton>

class SoundButton final : public QObject, public IConnectButton {
    Q_OBJECT
public:
    explicit                    SoundButton(QPlainTextEdit *tE, QObject *parent = nullptr);
    virtual void                connectButton(QPushButton *) override;

private slots:
    void                        onButtonClick();
    //void                        play();
    //void                        stop();
    //void                        pause();

private:
    Sound *                     sound;
    QPlainTextEdit *            convertedText;
};

#endif // SOUNDBUTTON_H
