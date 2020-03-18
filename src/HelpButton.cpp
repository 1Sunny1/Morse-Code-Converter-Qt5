#include "HelpButton.h"
#include "ButtonAppearance.h"
#include "mainwindow.h"

#include <QString>

HelpButton::HelpButton(QPlainTextEdit *tE, QGroupBox *gB, QObject *parent)
    : QObject(parent)
    , userText(tE)
    , groupBox(gB) {}

void HelpButton::connectButton(QPushButton *button) {
    connect(button, &QPushButton::clicked, this, &HelpButton::onButtonClick);
}

void HelpButton::connectCloseButton(QPushButton *controlButton) {
    connect(controlButton, &QPushButton::clicked, this, &HelpButton::onCloseButtonClick);
}

void HelpButton::onButtonClick() {
    auto button = qobject_cast<QPushButton*>(sender());
    QString content = userText->toPlainText();
    if(userText->toPlainText().isEmpty())
        userText->setPlainText(button->text());
    else
        userText->setPlainText(content + " " + button->text());
    groupBox->hide();
    ButtonLook::Standard::Pressed(helpButton);
}

void HelpButton::onCloseButtonClick() {
    groupBox->hide();
    ButtonLook::Standard::Default(helpButton);
}

void HelpButton::passHelpButton(QPushButton *_helpButton) {
    helpButton = _helpButton;
}
