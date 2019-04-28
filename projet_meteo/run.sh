#!/bin/bash
make clean 
qmake AppMeteo.pro
make 
make clean
qmake ServerMeteo.pro
make
make clean
