#!/bin/bash
make clean 
qmake AppMeteo.pro
make 
make clean
unset LC_ALL LANG LANGUAGE
