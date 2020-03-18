#include "AnimatedBackground.h"
#include "MorseCodeConverter.h"

#include <QApplication>
#include <QGraphicsBlurEffect>

AnimatedBackground::AnimatedBackground(QObject *parent) noexcept
    : QObject(parent)
    , wHeight{ 720 }
    , wWidth{ 1280 } {}

void AnimatedBackground::connectAnimation(QPropertyAnimation *animation) {
    connect(animation, &QPropertyAnimation::currentLoopChanged, this, &AnimatedBackground::onCurrentLoopChanged);
}

void AnimatedBackground::onCurrentLoopChanged(int) {
    auto animation = qobject_cast<QPropertyAnimation*>(sender());

    int randomHeight = random::number<int>(wHeight - wHeight, wHeight);
    animation->setStartValue(QRect(wWidth + 150, randomHeight, 100, 100));
    animation->setEndValue(QRect(wWidth - wWidth - 100, randomHeight, 100, 100));
}

QPropertyAnimation *AnimatedBackground::createAnimation(QLabel *label) {
    const int wHeight = 720;
    const int wWidth = 1280;
    label->setText(MorseCodeConverter::getRandomCode());
    //setBlurEffect(label);

    int randomHeight = random::number<int>(wHeight - wHeight + 100, wHeight);
    int randomStartPos = random::number<int>(wWidth + 100, wWidth + 300);
    int randomEndPos = random::number<int>(wWidth - wWidth - 200, wWidth - wWidth - 50);

    QPropertyAnimation *animation = new QPropertyAnimation(label, "geometry");
    animation->setDuration(random::duration<int>(15000, 30000));
    animation->setStartValue(QRect(randomStartPos, randomHeight, 100, 100));
    animation->setEndValue(QRect(randomEndPos, randomHeight, 100, 100));
    animation->setLoopCount(-1);
    animation->start();

    return animation;
}

void AnimatedBackground::setBlurEffect(QLabel *label) {
    //QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(label) ;
    //effect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
    //label->setGraphicsEffect(effect);
}
