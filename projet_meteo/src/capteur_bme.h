#ifndef CAPTEUR_BME_H
#define CAPTEUR_BME_H
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>

struct bme280_dev init_capteur();
struct bme280_data lecture_data_capteur(struct bme280_dev *dev);

#endif // CAPTEUR_BME_H
