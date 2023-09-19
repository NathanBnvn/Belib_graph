TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../cJSON-master/cJSON.c \
        ../../libgd-master/src/gd.c \
        main.cpp

HEADERS += \
    ../../cJSON-master/cJSON.h \
    ../../libgd-master/src/gd.h
