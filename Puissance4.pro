TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    puissance4.cpp
LIBS += -lX11 -lconio -lpthread -lXgeii

HEADERS += \
    puissance4.h
