#ifndef CAPTEUR_BME_H
#define CAPTEUR_BME_H
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>

struct bme280_dev init_capteur();
struct bme280_data stream_sensor_data_normal_mode(struct bme280_dev *dev);
void print_sensor_data(struct bme280_data *comp_data);
int8_t user_i2c_write(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len);
int8_t user_i2c_read(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len);
void user_delay_ms(uint32_t period);
#endif // CAPTEUR_BME_H
