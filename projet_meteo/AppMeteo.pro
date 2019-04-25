TEMPLATE = app
TARGET = AppMeteo
INCLUDEPATH += .
INCLUDEPATH += /usr/include/c++/6/bits
INCLUDEPATH+=/usr/include/c++/6
INCLUDEPATH+=/usr/include
INCLUDEPATH+=/usr/local/lib

CONFIG += stl
# Input
HEADERS += src/bme280.h \
           src/bme280_defs.h \
           src/capteur_bme.h \
           src/Objets.h \
           src/zambetti.h
SOURCES += src/bme280.c \
           src/capteur_bme.cpp \
           src/main.cpp \
           src/Objets.cpp \
           src/zambetti.cpp
QT += qml
QT += quick
