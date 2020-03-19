#ifndef CONVERTERCONTROLBUTTON_H
#define CONVERTERCONTROLBUTTON_H

#include "IConnectButton.h"
#include "PushButtonHover.h"

#include <QPushButton>
#include <QObject>
#include <QPlainTextEdit>

class ConverterControlButton final : public QObject, public IConnectButton {
    Q_OBJECT
public:
                             ConverterControlButton(bool *toText, std::pair<PushButtonHover*, PushButtonHover *> &, QObject *parent = nullptr);
    virtual void             connectButton(QPushButton *) override;
    void                     passPlainTextEdits(std::pair<QPlainTextEdit *, QPlainTextEdit *>&);

private slots:
    void                     onClick();

private:
    void                     swapContent();
    void                     handleToTextButton(QPushButton *button);
    void                     handleToCodeButton(QPushButton *button);


private:
    bool *                   toText;
    bool                     isToTextButtonPressed{false};
    bool                     isToCodeButtonPressed{true};
    QPushButton *            toCodeButton;
    QPushButton *            toTextButton;
    QPlainTextEdit *         userText;
    QPlainTextEdit *         convertedText;
};


#endif // CONVERTERCONTROLBUTTON_H
