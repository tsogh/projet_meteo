#ifndef CAPTEUR_BME_H
#define CAPTEUR_BME_H
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>

struct bme280_dev init_capteur();
struct bme280_data lecture_data_capteur(struct bme280_dev *dev);
int8_t user_i2c_write(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len);
int8_t user_i2c_read(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len);
void user_delay_ms(uint32_t period);
#endif // CAPTEUR_BME_H
