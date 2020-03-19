#ifndef HELPBUTTON_H
#define HELPBUTTON_H

#include "IConnectButton.h"

#include <QObject>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include <memory>

class HelpButton final : public QObject, public IConnectButton {
    Q_OBJECT

public:
                                            HelpButton(QPlainTextEdit *te, QGroupBox *gB, QObject *parent = nullptr);
    void                                    connectButton(QPushButton *b) override;
    void                                    connectCloseButton(QPushButton *b);
    void                                    connectHelpButtonTab(QPushButton *b);
    void                                    passHelpButton(QPushButton *b);

public slots:
    void                                    onButtonClick();
    void                                    onCloseButtonClick();
    void                                    onHelpButtonClick();

private:
    QPlainTextEdit *                        userText;
    QGroupBox *                             groupBox;
    QPushButton *                           helpButton;
};

#endif // HELPBUTTON_H
