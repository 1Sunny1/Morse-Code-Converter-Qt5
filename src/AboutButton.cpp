#include "AboutButton.h"
#include "ButtonAppearance.h"

AboutButton::AboutButton(QTextBrowser *tB, QGroupBox *gB, QObject *parent)
    : QObject(parent)
    , textBrowser(tB)
    , groupBox(gB) { }

void AboutButton::connectButton(QPushButton *button) {
    connect(button, &QPushButton::clicked, this, &AboutButton::changeContent);
}

void AboutButton::changeContent() {
    auto button = qobject_cast<QPushButton *>(sender());

    const QString content = button->text().remove(0, 2); //remove first two characters - in our case it is '?' and '\n'
    textBrowser->setText(content);
    ButtonLook::About::Pressed(button);
    setButtonsDefaultWithExceptionOf(button);

    groupBox->show();
}

void AboutButton::passAboutButtons(std::vector<QPushButton *> &_aboutButtons) {
    aboutButtons = _aboutButtons;
}

void AboutButton::setButtonsDefaultWithExceptionOf(QPushButton *exceptionalButton) {
    if (exceptionalButton == nullptr) {
        for (auto button : aboutButtons)
            ButtonLook::About::Default(button);
    }

    else {
        for (auto button : aboutButtons)
            if (exceptionalButton != button)
                ButtonLook::About::Default(button);
    }
}

void AboutButton::connectCloseButton(QPushButton *closeButton) {
    connect(closeButton, &QPushButton::clicked, this, &AboutButton::closeAboutTab);
}

void AboutButton::closeAboutTab() {
    groupBox->hide();
    setButtonsDefaultWithExceptionOf();
}
