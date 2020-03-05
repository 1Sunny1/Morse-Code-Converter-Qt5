#include "AnimatedBackground.h"

#include <random>
#include <QApplication>
#include <QGraphicsBlurEffect>

static std::mt19937 gen{ std::random_device{}() };

template<typename T>
inline T random(T min, T max) {
    return std::uniform_int_distribution<T>{min, max}(gen);
}

template<typename T>
T randomDuration(T min, T max) {
    return random<T>(min, max);
}

AnimatedBackground::AnimatedBackground() noexcept
    : wHeight{ this->height() },
      wWidth{ this->width() } {}

void AnimatedBackground::connectAnimation(QPropertyAnimation *animation) {
    connect(animation, &QPropertyAnimation::currentLoopChanged, this, &AnimatedBackground::onCurrentLoopChanged);
}

void AnimatedBackground::onCurrentLoopChanged(int) {
    auto animation = qobject_cast<QPropertyAnimation*>(sender());
    int randomValue = random<int>(wHeight - wHeight, wHeight);
    animation->setStartValue(QRect(this->width() + 150, randomValue, 100, 100));
    animation->setEndValue(QRect(this->width() - this->width() - 100, randomValue, 100, 100));
}

QPropertyAnimation *AnimatedBackground::createAnimation(QLabel *label, std::pair<int, int> windowDimensions) {
    int randomHeight = random<int>(windowDimensions.first - windowDimensions.first, windowDimensions.first);
    setBlurEffect(label);

    QPropertyAnimation *animation = new QPropertyAnimation(label, "geometry");
    animation->setDuration(randomDuration<int>(5000, 15000));
    animation->setStartValue(QRect(windowDimensions.second + 150, randomHeight, 100, 100));
    animation->setEndValue(QRect(windowDimensions.second - windowDimensions.second - 100, randomHeight, 100, 100));
    animation->setLoopCount(-1);
    animation->start();

    return animation;
}

void AnimatedBackground::setBlurEffect(QLabel *label) {
    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(label) ;
    effect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
    label->setGraphicsEffect(effect);
}
