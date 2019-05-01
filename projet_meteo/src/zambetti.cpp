#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <math.h>
#include "zambetti.h"
#include <iostream>
using namespace std;

// calcul de la tendance pour le choix de la tables de zambretti
string get_trend_text(float trend) {
  string trend_str = "Steady";
  if (trend > 0.25  )  {trend_str = "Rising";  }
  else if (trend > -0.25 && trend < 0.25)  {trend_str = "Steady";       }
  else if ( trend < -0.25) {trend_str = "Falling"; }
  return trend_str;
}


/*Above 1020 mB Winter or Summer differences of the pressure results in a change of only 2 Forecast letters
 below 1020 mb only very moderate changes of about 2 Forecast letters in going from Summer to Winter estimates.
*/
// calcul de la pression de zambretti avec les regression linéaire
int calc_zambretti(float zpressure, float trend) {
  string ztrend=get_trend_text(trend);

  //calcul du mois courant
  time_t now =time(0);
  tm *ltm=localtime(&now);
  int zmonth ;
  zmonth=ltm->tm_mon;
  cout << zmonth;

  // FALLING
  if (ztrend == "Falling" ) {
    double zambretti = 0.0009746*zpressure*zpressure - 2.1068*zpressure+1138.7019; //y = 0.0009746x^2-2.1068x+1138.7019

    // hiver, on rajoute 1 au nombre de zambretti
    if (zmonth < 4 || zmonth > 9) zambretti = zambretti + 1;
    switch (int(round(zambretti))) {
      case 1:  return 1;      //Settled Fine
      case 2:  return 2;      //Fine Weather
      case 3:  return 4;      //Fine Becoming Less Settled
      case 4:  return 8;      //Fairly Fine Showers Later
      case 5:  return 15;     //Showery Becoming unsettled
      case 6:  return 18;     //Unsettled, Rain later
      case 7:  return 21;     //Rain at times, worse later
      case 8:  return 22;     //Rain at times, becoming very unsettled
      case 9:  return 24;     //Very Unsettled, Rain
      default: return -1;
    }
  }
  // STEADY
  if (ztrend == "Steady") {
    float zambretti = 138.24-0.133*zpressure; // y = 138.24-0.1331x
    switch (int(round(zambretti))) {
      case 1:  return 1;      //Settled Fine
      case 2:  return 2;      //Fine Weather
      case 3:  return  5;     //Fine, Possibly showers
      case 4:  return 11;     //Fairly Fine, Showers likely
      case 5:  return 14;     //Showery Bright Intervals
      case 6:  return 16;     //Changeable some rain
      case 7:  return 19;     //Unsettled, rain at times
      case 8:  return 23;     //Rain at Frequent Intervals
      case 9:  return 24;     //Very Unsettled, Rain
      case 10: return 26;     //Stormy, much rain
      default: return -1;
    }
  }
  // RISING
  if (ztrend == "Rising" ) {
    float zambretti = 142.57-0.1376*zpressure; //y = 142.57-0.1376x
    //En  été , on améliore les perspectives d'une  1 unité
    if (zmonth < 4 || zmonth > 9) zambretti = zambretti + 1;
    switch (int(round(zambretti))) {
      case 1:  return 1;      //Settled Fine
      case 2:  return 2;      //Fine Weather
      case 3:  return 3;      //Becoming Fine
      case 4:  return 6;      //Fairly Fine, Improving
      case 5:  return 7;      //Fairly Fine, Possibly showers, early
      case 6:  return 9;      //Showery Early, Improving
      case 7:  return 10;     //Changeable, Improving
      case 8:  return 12;     //Rather Unsettled Clearing Later
      case 9:  return 13;     //Unsettled, Probably Improving
      case 10: return 17;     //Unsettled, short fine Intervals
      case 11: return 20;     //Very Unsettled, Finer at times
      case 12: return 25;     //Stormy, possibly improving
      case 13: return 26;     //Stormy, much rain
      default: return -1;
    }
  }
return -1;
}

//calcul de la prévision de zambretti avec la pression
int calc_zambretti_alt(float pressure,float trend){
  string ztrend=get_trend_text(trend);
  time_t now =time(0);
  tm *ltm=localtime(&now);
  int mon ;
  mon=ltm->tm_mon;

              if (ztrend == "Falling" ){
              //FALLING
			    if (pressure>=1030){return 2;}
                if(pressure>=1020 && pressure<1030){return 8;}
			    if(pressure>=980 && pressure<990){return 24;}
                if(pressure>=970 && pressure<980){return 26;}
                if(pressure<970){return 26;}
				
              if (mon>=4 && mon<=9)
              //été
              {
                if(pressure>=1010 && pressure<1020){return 18;}
                if(pressure>=1000 && pressure<1010){return 21;}
                if(pressure>=990 && pressure<1000){return 24;}
              }
              else{
              //hiver
                if(pressure>=1010 && pressure<1020){return 15;}
                if(pressure>=1000 && pressure<1010){return 21;}
                if(pressure>=990 && pressure<1000){return 22;}

              }
            }
              if (ztrend == "Raising" ){
              //RAISING
			    if (pressure>=1030){return 1;}
                if(pressure>=1020 && pressure<1030){return 2;}
				if(pressure>=1000 && pressure<1010){return 7;}
			    if(pressure>=970 && pressure<980){return 17;}
                if(pressure<970){return 17;}
				
              if (mon>=4 && mon<=9){
                //été
                if(pressure>=1010 && pressure<1020){return 3;}
                if(pressure>=990 && pressure<1000){return 9;}
                if(pressure>=980 && pressure<990){return 12;}
              }
              else
                //hiver
               {
                if(pressure>=1010 && pressure<1020){return 6;}
                if(pressure>=990 && pressure<1000){return 10;}
                if(pressure>=980 && pressure<990){return 13;}

               }
            }
            if (ztrend == "Steady") {
                if (pressure>=1030){return 1;}
                else if(pressure>=1020 && pressure<1030){return 2;}
                else if(pressure>=1010 && pressure<1020){return 11;}
                else if(pressure>=1000 && pressure<1010){return 14;}
                else if(pressure>=990 && pressure<1000){return 19;}
                else if(pressure>=980 && pressure<990){return 23;}
                else if(pressure>=970 && pressure<980){return 24;}
                else if(pressure<970){return 26;}
            }
        return -1;
    }
