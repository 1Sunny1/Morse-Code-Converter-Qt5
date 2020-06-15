#ifndef ANIMATEDBACKGROUND_H
#define ANIMATEDBACKGROUND_H

#include "myrandom.h"

#include <QMainWindow>
#include <QLabel>
#include <QPropertyAnimation>

class AnimatedBackground final : public QObject {
    Q_OBJECT
public:
    explicit                         AnimatedBackground(QObject *parent = nullptr) noexcept;
    void                             connectAnimation(QPropertyAnimation *);

public:
    static QPropertyAnimation*       createAnimation(QLabel *);

private slots:
    void                             onCurrentLoopChanged(int);

private:
    int                              wHeight;
    int                              wWidth;
};

#endif // ANIMATEDBACKGROUND_H


