#!/bin/bash
make clean
qmake ServerMeteo.pro
make
make clean
unset LC_ALL LANG LANGUAGE
