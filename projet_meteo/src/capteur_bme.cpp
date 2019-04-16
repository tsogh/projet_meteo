#include "capteur_bme.h"

/*
  Comple：make
  Run: ./bme280
  This Demo is tested on Raspberry PI 3B+
  you can use I2C or SPI interface to test this Demo
  When you use I2C interface,the default Address in this demo is 0X77
  When you use SPI interface,PIN 27 define SPI_CS
*/
#include "bme280.h"
#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "zambetti.h"

//Raspberry 3B+ platform's default SPI channel
#define channel 0

//Default write it to the register in one time
#define USESPISINGLEREADWRITE 0

//This definition you use I2C or SPI to drive the bme280
//When it is 1 means use I2C interface, When it is 0,use SPI interface
#define USEIIC 1



#include <string.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>
//Raspberry 3B+ platform's default I2C device file
#define IIC_Dev  "/dev/i2c-1"

int fd;

void user_delay_ms(uint32_t period)
{
  usleep(period*1000);
}

int8_t user_i2c_read(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
  write(fd, &reg_addr,1);
  read(fd, data, len);
  return 0;
}

int8_t user_i2c_write(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len)//typecast
{
  int8_t *buf;
  buf = (int8_t*)malloc(len +1);
  buf[0] = reg_addr;
  memcpy(buf +1, data, len);
  write(fd, buf, len +1);
  free(buf);
  return 0;
}




void print_sensor_data(struct bme280_data *comp_data)
{
#ifdef BME280_FLOAT_ENABLE
    printf("temperature:%0.2f*C   pressure:%0.2fhPa   humidity:%0.2f%%\r\n",comp_data->temperature, comp_data->pressure/100, comp_data->humidity);
#else
    printf("temperature:%ld*C   pressure:%ldhPa   humidity:%ld%%\r\n",comp_data->temperature, comp_data->pressure/100, comp_data->humidity);
#endif
}



struct bme280_data stream_sensor_data_normal_mode(struct bme280_dev *dev)
{
    int8_t rslt;
    //uint8_t settings_sel;
    struct bme280_data comp_data;

    /* Recommended mode of operation: Indoor navigation */
    /*dev->settings.osr_h = BME280_OVERSAMPLING_1X;
    dev->settings.osr_p = BME280_OVERSAMPLING_16X;
    dev->settings.osr_t = BME280_OVERSAMPLING_2X;
    dev->settings.filter = BME280_FILTER_COEFF_16;
    dev->settings.standby_time = BME280_STANDBY_TIME_62_5_MS;

    settings_sel = BME280_OSR_PRESS_SEL;
    settings_sel |= BME280_OSR_TEMP_SEL;
    settings_sel |= BME280_OSR_HUM_SEL;
    settings_sel |= BME280_STANDBY_SEL;
    settings_sel |= BME280_FILTER_SEL;
    rslt = bme280_set_sensor_settings(settings_sel, dev);
    rslt = bme280_set_sensor_mode(BME280_NORMAL_MODE, dev);*/

 /*while (i<10) {
        dev->delay_ms(70);
        rslt = bme280_get_sensor_data(BME280_ALL, &comp_data, dev);
    liste.push_back(comp_data);
    i++;
    }

    printf("Temperature           Pressure             Humidity\r\n");*/
   // while (1) {
    dev->delay_ms(70);
    rslt = bme280_get_sensor_data(BME280_ALL, &comp_data, dev);
    //float trend = 1009- 1010;
    //float trend = liste[liste.size()-4].pressure/100-liste[liste.size()-1].pressure/100;
    //float tmp= comp_data.pressure/100;            // Trend over the last 3-hours
    //calc_zambretti(tmp, get_trend_text(trend));
    //print_sensor_data(&comp_data);
//	}
printf("ok %d\n",rslt);

    return comp_data;
}


struct bme280_dev init_capteur()
{
  struct bme280_dev dev;
  int8_t rslt = BME280_OK;
  uint8_t settings_sel;
  struct bme280_data comp_data;
  if ((fd = open(IIC_Dev, O_RDWR)) < 0) {
    exit(1);
  }
  if (ioctl(fd, I2C_SLAVE, 0x77) < 0) {
    printf("Failed to acquire bus access and/or talk to slave.\n");
    exit(1);
  }
  //dev.dev_id = BME280_I2C_ADDR_PRIM;//0x76
  dev.dev_id = BME280_I2C_ADDR_SEC; //0x77
  dev.intf = BME280_I2C_INTF;
  dev.read = user_i2c_read;
  dev.write = user_i2c_write;
  dev.delay_ms = user_delay_ms;

  rslt = bme280_init(&dev);
  printf("\r\n BME280 Init Result is:%d \r\n",rslt);
  //comp_data=stream_sensor_data_normal_mode(&dev);
  dev.settings.osr_h = BME280_OVERSAMPLING_1X;
  dev.settings.osr_p = BME280_OVERSAMPLING_16X;
  dev.settings.osr_t = BME280_OVERSAMPLING_2X;
  dev.settings.filter = BME280_FILTER_COEFF_16;
  dev.settings.standby_time = BME280_STANDBY_TIME_62_5_MS;

  settings_sel = BME280_OSR_PRESS_SEL;
  settings_sel |= BME280_OSR_TEMP_SEL;
  settings_sel |= BME280_OSR_HUM_SEL;
  settings_sel |= BME280_STANDBY_SEL;
  settings_sel |= BME280_FILTER_SEL;
  rslt = bme280_set_sensor_settings(settings_sel, &dev);
  rslt = bme280_set_sensor_mode(BME280_NORMAL_MODE, &dev);
  return dev;
}

//main(){
//struct bme280_dev dev= init_capteur();
//struct bme280_data data= stream_sensor_data_normal_mode(&dev);

//}
