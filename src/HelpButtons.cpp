#include "HelpButtons.h"

#include <QString>

HelpButtons::HelpButtons(QPlainTextEdit *tE, QGroupBox *gB, QObject *parent) :
    QObject(parent),
    userText(tE),
    groupBox(gB) {}

void HelpButtons::connectButton(QPushButton *button) {
    connect(button, &QPushButton::clicked, this, &HelpButtons::onButtonClick);
}

void HelpButtons::onButtonClick() {
    auto button = qobject_cast<QPushButton*>(sender());
    QString content = userText->toPlainText();
    if(userText->toPlainText().isEmpty())
        userText->setPlainText(button->text());
    else
        userText->setPlainText(content + " " + button->text());
    groupBox->hide();
}
