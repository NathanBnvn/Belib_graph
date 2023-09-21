TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += "-lgd"

SOURCES += \
        belib.cpp \
        main.cpp

HEADERS += \
    belib.h
