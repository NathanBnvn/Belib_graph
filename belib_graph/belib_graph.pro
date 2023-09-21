TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../libgd-master/src/gd.c \
        belib.cpp \
        main.cpp

HEADERS += \
    ../../libgd-master/src/gd.h \
    belib.h
