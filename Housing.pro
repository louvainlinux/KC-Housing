QT           += core gui sql
TEMPLATE      = lib
CONFIG       += plugin
INCLUDEPATH  += ../KapCompta
HEADERS       = housing.h \
    meal.h
SOURCES       = housing.cpp \
    meal.cpp
TARGET        = $$qtLibraryTarget(kc_housing)
DESTDIR       = ../KapCompta/plugins

RESOURCES += \
    icons.qrc
