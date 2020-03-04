include(gtest_dependency.pri)

QT += core gui
QT += widgets

TARGET = tests
TEMPLATE = app
CONFIG += c++1z
CONFIG += thread
CONFIG += qt

HEADERS += \
    FilterTest.h \
    MorseCodeConverterClassTest.h \
    ../src/MorseCodeConverter.h \
    ../src/PushButtonHover.h \
    ../src/Keyboard.h \


SOURCES += \
    source.cpp \
    ../src/MorseCodeConverter.cpp \
    ../src/PushButtonHover.cpp \
    ../src/Keyboard.cpp

INCLUDEPATH += \
    ../src

