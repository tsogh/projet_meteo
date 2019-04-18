#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

string get_trend_text(float trend);
int calc_zambretti(float zpressure, float ztrend);
int calc_zambretti_alt(float pressure,float trend);
