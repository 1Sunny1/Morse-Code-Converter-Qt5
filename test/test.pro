QT += testlib
QT += core gui
QT += widgets

CONFIG += c++1z
CONFIG += qt
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app
HEADERS += \
    ../src/MorseCodeConverter.h \
    ../src/PushButtonHover.h \
    ../src/Keyboard.h

SOURCES += \
    tst_filter.cpp \
    tst_morsecodeconvertertest.cpp \
    ../src/MorseCodeConverter.cpp \
    ../src/PushButtonHover.cpp \
    ../src/Keyboard.cpp

INCLUDEPATH += \
    ../src
