#ifndef ABOUTBUTTON_H
#define ABOUTBUTTON_H

#include "IConnectButton.h"

#include <QObject>
#include <QPushButton>
#include <QTextBrowser>
#include <QGroupBox>

class AboutButton final : public QObject, public IConnectButton {
    Q_OBJECT
public:
                                AboutButton(QTextBrowser * tB, QGroupBox *gB, QObject *parent = nullptr);
    virtual void                connectButton(QPushButton *) override;
    void                        connectCloseButton(QPushButton *);
    void                        passAboutButtons(std::vector<QPushButton *> &aboutButtons);

private:
    void                        changeContent();
    void                        setButtonsDefaultWithExceptionOf(QPushButton *exceptionalButton = nullptr);
    void                        closeAboutTab();

private:
    QTextBrowser *                                  textBrowser;
    QGroupBox *                                     groupBox;
    std::vector<QPushButton *>                      aboutButtons;

};

#endif // ABOUTBUTTON_H
