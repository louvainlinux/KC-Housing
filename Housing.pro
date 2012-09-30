TEMPLATE      = lib
CONFIG       += plugin
INCLUDEPATH  += ../KapCompta
HEADERS       = \
    housing.h
SOURCES       = \
    housing.cpp
TARGET        = $$qtLibraryTarget(kc_housing)
DESTDIR       = ../KapCompta/plugins
