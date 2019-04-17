#include "Objets.h"
#include <QDebug>
#include <QString>
#include <QtMath>
#include "bme280.h"
#include "capteur_bme.h"
#include <utility>
#include <string>
#include <tuple>
#include <vector>
#include <cmath>
#include <numeric> 
using namespace std;

/*qreal convert_pressAbs(qreal press, qreal altitude,qreal temp){
 qreal conv_cel_kel=temp+273.15;
return 1013.25*(qPow(1-((0.0065*altitude)/conv_cel_kel),5.255));
*/
qreal convert_pressAbs(qreal press, qreal altitude,qreal temp){
    qreal Kelvin=temp+273.1;
    //return press+1013.25*(1-qPow((288-0.0065*altitude)/288,5.255));
return press+1013.25*(1-qPow((Kelvin-0.0065*altitude)/Kelvin,5.255));

}
void Objets::recup_val(){
      struct bme280_data val=stream_sensor_data_normal_mode(&m_dev);
    m_temp=val.temperature;
    m_humi=val.humidity;
    m_press=val.pressure/100;

    qDebug()<<m_press;
    m_press=convert_pressAbs(m_press,151,m_temp);
    qDebug()<<m_press;  
    
}
qreal Objets::calcul_tendance(){
    qreal t;
    if (his_h.size()>0){
            t=his_h.front();
    }
    else if (his_m.size()>0){
        t=his_m.front();
    }
    else if (his_s.size()>0){
        t=his_s.front();
    }
    else{
        t=1013.25;
    }
    
    return t;
    
    
    
    }
void Objets::calcul_zam(){
    qreal tmp= m_press-(m_press-1);
    tuple <string,string,string> rslt;
    rslt=calc_zambretti(m_press,calcul_tendance());
    m_des=QString::fromStdString(get<0>(rslt));
    m_img=QString::fromStdString(get<1>(rslt));
    m_fleche=QString::fromStdString(get<2>(rslt));
    
    }
void Objets::refresh() {
    //m_dev= init_capteur();
    recup_val();
    histo_press();
    calcul_zam();
    //faire histoisation
    calcul_zam();
}

void Objets::histo_press(){
    his_s.push_back(m_press);
    if (his_s.size()==60) {
      qreal moy_s=0;
      moy_s=(qreal)accumulate(his_s.begin(),his_s.end(),0.0);
      moy_s/=60;
      his_m.push_back(moy_s);
      his_s.push_back(m_press);
      his_s.clear();
    }
    if (his_m.size()==60) {
      qreal moy_m=0;
      moy_m=(qreal)accumulate(his_m.begin(),his_m.end(),0.0);
      moy_m/=60;
      his_h.push_back(moy_m);
      his_m.clear();
    }
    if (his_h.size()==24) {
      his_h.erase(his_h.begin());
    }
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
