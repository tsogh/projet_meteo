######################################################################
# Automatically generated by qmake (3.0) lun. avr. 29 12:37:27 2019
######################################################################

TEMPLATE = app
TARGET = projet_meteo
INCLUDEPATH += .

# Input
HEADERS += src/bme280.h \
           src/bme280_defs.h \
           src/capteur_bme.h \
           src/Objets.h \
           src/prometheusServ.h \
           src/zambetti.h
SOURCES += src/bme280.c \
           src/capteur_bme.cpp \
           src/main.cpp \
           src/mainserv.cpp \
           src/Objets.cpp \
           src/prometheusServ.cpp \
           src/zambetti.cpp
