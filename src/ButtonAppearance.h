#ifndef BUTTONAPPEARANCE_H
#define BUTTONAPPEARANCE_H

#include <QPushButton>

namespace ButtonLook {
    namespace About {
        inline void Pressed(QPushButton *button) {
            button->setStyleSheet("QPushButton { font: 22pt \"Quite Magical\"; border: 3px solid #ff6666; border-radius: 12px; background-color: #f5f5dc; max-width:24px; max-height:24px; min-width:24px; min-height:24px; } QPushButton:hover { background-color: #f5f5dc; }");
        }

        inline void Default(QPushButton *button) {
            button->setStyleSheet("QPushButton { font: 22pt \"Quite Magical\"; border: 2px solid black; border-radius: 12px; background-color: #f4f3f3; max-width:24px; max-height:24px; min-width:24px; min-height:24px; } QPushButton:hover { background-color: #f5f5dc; }");
        }
    }
    namespace Standard {
        inline void Pressed(QPushButton *button) {
            button->setStyleSheet("QPushButton { border: 2px solid #ff6666; border-radius: 11px; background-color: #f5f5dc; font-size: 20px; } QPushButton:hover { background-color: #f5f5dc; border: 2px solid #ff6666; }");
        }

        inline void Default(QPushButton *button) {
            button->setStyleSheet("QPushButton { border: 1px solid #f0eeee; border-radius: 11px; background-color: #f0eeee; font-size: 20px; } QPushButton:hover { background-color: #f5f5dc; border: 2px solid #f5f5dc; }");
        }
    }
}

#endif // BUTTONAPPEARANCE_H
