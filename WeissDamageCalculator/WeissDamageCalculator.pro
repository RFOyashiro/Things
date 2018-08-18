TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CAttack.cpp \
    CCard.cpp \
    CDeck.cpp

HEADERS += \
    CAttack.h \
    CCard.h \
    CDeck.h
