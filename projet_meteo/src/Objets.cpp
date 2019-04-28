#include "Objets.h"
#include <QDebug>
#include <QString>
#include <QtMath>
#include "bme280.h"
#include "capteur_bme.h"
#include <string>
#include <cmath>
#include <numeric>
#include <iostream>
using namespace std;

// code d'interface pour le code qml

// convert pression atmospherique sonde -> pression niveau de la mer
void Objets::convert_pressAbs(qreal press, qreal altitude,qreal temp){
    qreal Kelvin=temp+273.1;
    m_press_corrige=press+1013.25*(1-qPow((Kelvin-0.0065*altitude)/Kelvin,5.255));
}
// calcul de l'altitude avec la pression
void Objets::calcul_altitude(){
  m_alti= 44330*(pow(m_press_corrige/m_press,1/5.255)-1);
}

// table du résultat du nombre de zambretti
void Objets::table_rslt_zambetti(int code){
  //recup de l'heure pour modification de l'image
  time_t now =time(0);
  tm *ltm=localtime(&now);
  int heure =ltm->tm_hour;
  int ind_heure=0;
  if (heure>22 || heure<7){ind_heure=1;}
  switch(code){
    case 1: m_des = "Beau temps stable"; m_img=ind_heure==0?"day":"night"; m_code_couleur="#1e90ff"; break;
    case 2: m_des = "Beau temps"; m_img=ind_heure==0?"day":"night"; m_code_couleur="#1e90ff";break;
    case 3 :m_des = "Amélioration";m_img=ind_heure==0?"day":"night";m_code_couleur="#1e90ff";break;
    case 4 :m_des = "Bien, deviens nuageux"; m_img=ind_heure==0?"cloudyday1":"cloudynigh1";m_code_couleur="#1e90ff";break;
    case 5 :m_des = "Bien, possibles averses"; m_img="rainy-2";m_code_couleur="#ebf5ff";break;
    case 6 :m_des = "Assez bien, en amélioration"; m_img="cloudy";m_code_couleur="#ebf5ff";break;
    case 7 :m_des = "Assez bien, averses probable"; m_img="rainy-3";m_code_couleur="#ebf5ff";break;
    case 8 :m_des = "Assez Bien, risque d'averses <br> plus tard"; m_img="rainy-3";m_code_couleur="#ebf5ff";break;
    case 9 :m_des = "Des averses, en amélioration"; m_img="rainy-4";m_code_couleur="#71808d";break;
    case 10 :m_des = "Changeant avec amélioration";m_img=ind_heure==0?"cloudyday1":"cloudynigh1";m_code_couleur="#71808d";break;
    case 11:m_des = "Assez bien, averses probables"; m_img="rainy-4";m_code_couleur="#71808d";break;
    case 12 :m_des = "Plutôt nuageux, en amélioration";m_img=ind_heure==0?"cloudyday2":"cloudynigh2";m_code_couleur="#71808d";break;
    case 13 :m_des = "Nuageux, probable amélioration"; m_img=ind_heure==0?"cloudyday2":"cloudynigh2";m_code_couleur="#71808d";break;
    case 14 :m_des = "Pluvieux avec intervalles <br> ensoleillé"; m_img="rainy-2";m_code_couleur="#71808d";break;
    case 15 :m_des = "Pluvieux, devenant nuageux"; m_img="rainy-5";m_code_couleur="#71808d";break;
    case 16 :m_des = "Changeant avec un peu de pluie"; m_img="rainy-5";m_code_couleur="#71808d";break;
    case 17 :m_des = "Nuageux, petite pluie <br>par intermitance"; m_img="rainy-4";m_code_couleur="#5e80a0";break;
    case 18 :m_des = "Nuageux, pluie plus tard"; m_img="rainy-4";m_code_couleur="#5e80a0";break;
    case 19 :m_des = "Nuageux, pluie à l'occasion"; m_img="rainy-4";m_code_couleur="#5e80a0";break;
    case 20:m_des = "Très nuageux"; m_img="cloudy";m_code_couleur="#5e80a0";break;
    case 21:m_des = "Pluie par intermittence,se détériore"; m_img="rainy-5";m_code_couleur="#5e80a0";break;
    case 22:m_des = "Pluie par intermittence, très nuageux"; m_img="rainy-5"; m_code_couleur="#5e80a0";break;
    case 23 :m_des = "Pluie à intervalles fréquents"; m_img="rainy-6";m_code_couleur="#5e80a0";break;
    case 24:m_des = "Très instable, pluie";m_img="rainy-7"; m_code_couleur="#5e80a0";break;
    case 25:m_des = "Orage, amélioration possible"; m_img="thunder";m_code_couleur="";break;
    case 26:m_des = "Orage, beaucoup de pluie"; m_img="thunder";m_code_couleur="#7b7f83";break;
    default: m_des="erreur table"; break;
}
}
// fonction appel du capteur pour la récuperation des données
void Objets::recup_val(){
    data=lecture_data_capteur(&m_dev);
    m_temp=data.temperature;
    m_humi=data.humidity;
    m_press=data.pressure/100;
    convert_pressAbs(m_press,m_alti,m_temp);
    //calcul_altitude();

}
//historisation, récuperation de la données pour la tendances
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

    return tendance;
    }
  //calcul de zambretti
void Objets::calcul_zam(){
    int code;
    code= calc_zambretti_alt(m_press_corrige,m_press-calcul_tendance());
    table_rslt_zambetti(code);
    m_fleche=QString::fromStdString(get_trend_text(m_press-calcul_tendance()));

    }
// rafraichissement de la page qml
void Objets::refresh() {
    recup_val();
    histo_press();
    calcul_zam();
    cout<<"test "<<m_press_corrige<<" \n";

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
//historisation de al tendance, calcul de moyenne des seconde, minute et heure
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
//Constructeur de l'Objets
Objets::Objets() {
    m_dev= init_capteur();
}

// getteurs
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
qreal  Objets::alti() const {

    return m_alti;
}
vector<string>  Objets::vec_histo() const {

    return m_vec_histo;
}
void Objets::set_alti(qreal alti){
  m_alti=alti;
}
