#ifndef HELPBUTTONS_H
#define HELPBUTTONS_H

#include <QObject>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include <memory>

class HelpButtons final : public QObject{
    Q_OBJECT

public:
                                            HelpButtons(QPlainTextEdit *te, QGroupBox *gB, QObject *parent = nullptr);
    void                                    connectButton(QPushButton *b);

public slots:
    void                                    onButtonClick();

private:
    QPlainTextEdit *                        userText;
    QGroupBox *                             groupBox;
};

#endif // HELPBUTTONS_H
