#ifndef ANIMATEDBACKGROUND_H
#define ANIMATEDBACKGROUND_H

#include <QMainWindow>
#include <QLabel>
#include <QPropertyAnimation>
#include "myrandom.h"

class AnimatedBackground final : public QMainWindow {
    Q_OBJECT
public:
    explicit                         AnimatedBackground() noexcept;
    void                             connectAnimation(QPropertyAnimation *);

public:
    static QPropertyAnimation*       createAnimation(QLabel *);
    static void                      setBlurEffect(QLabel *);

private slots:
    void                             onCurrentLoopChanged(int);

private:
    int                              wHeight;
    int                              wWidth;
};

#endif // ANIMATEDBACKGROUND_H


