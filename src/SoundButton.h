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
    explicit                    SoundButton(std::vector<QPushButton*> const&, QPlainTextEdit *tE, QPlainTextEdit *uE, bool *toText, QObject *parent = nullptr);
    virtual void                connectButton(QPushButton *) override;

private slots:
    void                        onButtonClick();
    void                        setButtonsDefaultWithExceptionOf(QPushButton *exceptionalButton = nullptr);
    void                        setButtonsDefaultAfterPlaying(int position);

private:
    Sound *                     sound;
    std::vector<QPushButton *>  buttons;
};

#endif // SOUNDBUTTON_H
