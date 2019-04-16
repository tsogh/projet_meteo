#include "Objets.h"
#include <QDebug>
#include <QString>
#include <QtMath>
#include "bme280.h"
#include "capteur_bme.h"
#include <utility>
#include <string>
#include <tuple>
using namespace std;

qreal convert_pressAbs(qreal press, qreal altitude,qreal temp){
 qreal conv_cel_kel=temp+273.15;
return press+1013.25*(1-qPow(1-((-0.0065*altitude)/conv_cel_kel),5.255));

}

void Objets::refresh() {
    //m_dev= init_capteur();
    struct bme280_data val=stream_sensor_data_normal_mode(&m_dev);
    m_temp=val.temperature;
    m_humi=val.humidity;
    m_press=val.pressure/100;
    m_press=conv_cel_kel(m_press,151,m_temp);
    //faire histoisation
    qreal tmp= m_press-(m_press-1);
    tuple <string,string,string> rslt;
    rslt=calc_zambretti(convert_pressAbs(m_press,151),tmp);
    m_des=QString::fromStdString(get<0>(rslt));
    m_img=QString::fromStdString(get<1>(rslt));
    m_fleche=QString::fromStdString(get<2>(rslt));
}
Objets::Objets() {
    m_dev= init_capteur();
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

QString  Objets::fleche() const {

    return m_fleche;
}
