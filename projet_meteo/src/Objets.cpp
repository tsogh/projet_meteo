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
#include <utility>
#include <cmath>
#include <numeric>
using namespace std;

// convert pression atmospherique sonde -> pression niveau de la mer
qreal convert_pressAbs(qreal press, qreal altitude,qreal temp){
    qreal Kelvin=temp+273.1;
return press+1013.25*(1-qPow((Kelvin-0.0065*altitude)/Kelvin,5.255));
}

void Objets::table_rslt_zambetti(int code){

    if(code==1){m_des = "Beau temps stable"; m_img="day"; m_code_couleur="#1e90ff";}
    if(code==2){m_des = "Beau temps"; m_img="day"; m_code_couleur="#1e90ff";}
    if(code==3){m_des = "Amélioration"; m_img="day";m_code_couleur="#1e90ff";}
    if(code==4){m_des = "Bien, deviens nuageux"; m_img="cloudy1";m_code_couleur="#1e90ff";}
    if(code==5){m_des = "Bien, possibles averses"; m_img="rainy-2";m_code_couleur="#ebf5ff";}
    if(code==6){m_des = "Assez bien, en amélioration"; m_img="cloudy";m_code_couleur="#ebf5ff";}
    if(code==7){m_des = "Assez bien, averses probable"; m_img="rainy-3";m_code_couleur="#ebf5ff";}
    if(code==8){m_des = "Assez Bien, risque d'averses <br> plus tard"; m_img="rainy-3";m_code_couleur="#ebf5ff";}
    if(code==9){m_des = "Des averses, en amélioration"; m_img="rainy-4";m_code_couleur="#71808d";}
    if(code==10){m_des = "Changeant avec amélioration"; m_img="cloudy1";m_code_couleur="#71808d";}
    if(code==11){m_des = "Assez bien, averses probables"; m_img="rainy-4";m_code_couleur="#71808d";}
    if(code==12){m_des = "Plutôt nuageux, en amélioration"; m_img="cloudy2";m_code_couleur="#71808d";}
    if(code==13){m_des = "Nuageux, probable amélioration"; m_img="cloudy2";m_code_couleur="#71808d";}
    if(code==14){m_des = "Pluvieux avec intervalles <br> ensoleillé"; m_img="rainy-2";m_code_couleur="#71808d";}
    if(code==15){m_des = "Pluvieux, devenant nuageux"; m_img="rainy-5";m_code_couleur="#71808d";}
    if(code==16){m_des = "Changeant avec un peu de pluie"; m_img="rainy-5";m_code_couleur="#71808d";}
    if(code==17){m_des = "Nuageux, petite pluie <br>par intermitance"; m_img="rainy-4";m_code_couleur="#5e80a0";}
    if(code==18){m_des = "Nuageux, pluie plus tard"; m_img="rainy-4";m_code_couleur="#5e80a0";}
    if(code==19){m_des = "Nuageux, pluie à l'occasion"; m_img="rainy-4";m_code_couleur="#5e80a0";}
    if(code==20){m_des = "Très nuageux"; m_img="cloudy";m_code_couleur="#5e80a0";}
    if(code==21){m_des = "Pluie par intermittence,se détériore"; m_img="rainy-5";m_code_couleur="#5e80a0";}
    if(code==22){m_des = "Pluie par intermittence, très nuageux"; m_img="rainy-5"; m_code_couleur="#5e80a0";}
    if(code==23){m_des = "Pluie à intervalles fréquents"; m_img="rainy-6";m_code_couleur="#5e80a0";}
    if(code==24){m_des = "Très instable, pluie";m_img="rainy-7"; m_code_couleur="#5e80a0";}
    if(code==25){m_des = "Orage, amélioration possible"; m_img="thunder";m_code_couleur="";}
    if(code==26){m_des = "Orage, beaucoup de pluie"; m_img="thunder";m_code_couleur="#7b7f83";}

}
void Objets::recup_val(){
    data=lecture_data_capteur(&m_dev);
    m_temp=data.temperature;
    m_humi=data.humidity;
    m_press=data.pressure/100;
    m_press_zam=convert_pressAbs(m_press,151,m_temp);

}
qreal Objets::calcul_tendance(){
    qreal tendance;
    if (his_h.size()>0){
            tendance=his_h.front();
    }
    else if (his_m.size()>0){
            tendance=his_m.front();
    }
    else if (his_s.size()>0){
            tendance=his_s.front();
    }
    else{
            tendance=1013.25;
    }

    return t;
    }
void Objets::calcul_zam(){
    int code;
    code= calc_zambretti_alt(m_press_zam,m_press-calcul_tendance());
    table_rslt_zambetti(code);
    m_fleche=QString::fromStdString(get_trend_text(m_press-calcul_tendance()));
    
    }
void Objets::refresh() {
    
    recup_val();
    histo_press();
    calcul_zam();
    
}
void Objets::refresh_demo() {
    recup_val();
    table_rslt_zambetti(demo_code);
    demo_code++;
    cout<<"test "<<demo_code<<" \n";
    if(demo_code==26){
        demo_code=1;
    }
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
QString  Objets::color() const {

    return m_code_couleur;
}
