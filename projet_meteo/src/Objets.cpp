#include "Objets.h"
#include <QDebug>
#include <QString>
#include "bme280.h"
#include "capteur_bme.h"

void Objets::refresh() {
    m_dev= init_capteur();
    struct bme280_data val=stream_sensor_data_normal_mode(&m_dev);
    m_temp=val.temperature;
    m_humi=val.humidity;
    m_press=val.pressure/100;
    m_des=QString::fromStdString(calc_zambretti(m_press, "Falling"));
    m_img=m_des;
    // m_temp++;
     //m_humi++;
     //m_press++;
     //Qdebug()<< "ok";
}
Objets::Objets() {
}

qreal  Objets::temp() const {

    return m_temp;
}
qreal  Objets::humi() const {

    return m_humi;
}
qreal  Objets::press() const {

    return m_press;
}
QString  Objets::des() const {

    return m_des;
}
QString  Objets::img() const {

    return m_img;
}

