#ifndef ANIMATEDBACKGROUND_H
#define ANIMATEDBACKGROUND_H

#include <QMainWindow>
#include <QLabel>
#include <QPropertyAnimation>

class AnimatedBackground final : public QMainWindow {
    Q_OBJECT
public:
    explicit                         AnimatedBackground() noexcept;
    void                             start();
    void                             connectAnimation(QPropertyAnimation *);

public:
    static QPropertyAnimation*       createAnimation(QLabel *, std::pair<int, int>);
    static void                      setBlurEffect(QLabel *);

private slots:
    void                             onCurrentLoopChanged(int);

private:
    int                              wHeight;
    int                              wWidth;
};

#endif // ANIMATEDBACKGROUND_H


