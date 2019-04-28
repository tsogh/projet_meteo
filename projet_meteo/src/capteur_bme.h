#ifndef CAPTEUR_BME_H
#define CAPTEUR_BME_H



struct bme280_dev init_capteur();
struct bme280_data lecture_data_capteur(struct bme280_dev *dev);

#endif // CAPTEUR_BME_H
