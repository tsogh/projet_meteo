#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <math.h>
#include "zambetti.h"
#include <utility>
#include <iostream>
#include <tuple>
using namespace std;
string get_trend_text(float trend) {
  string trend_str = "Steady"; // Default weather state
  //if      (trend > 3.5)                    {trend_str = "Rising";  }//fast
  //else if (trend > 1.5   && trend <= 3.5)  {trend_str = "Rising";       }
  if (trend > 0.25  )  {trend_str = "Rising";  }//slow
  else if (trend > -0.25 && trend < 0.25)  {trend_str = "Steady";       }
  else if ( trend < -0.25) {trend_str = "Falling"; }//slow
  //else if (trend >= -3.5 && trend < -1.5)  {trend_str = "Falling";      }
  //else if (trend <= -3.5)                  {trend_str = "Falling"; }//fast
  return trend_str;
}


string lettre_zambetti(string code){
  string  des ="";
 const  char * tmp=code.c_str();
  switch (tmp[0]) {
  case 'A': des = "Settled Fine Weather"; break;
  case 'B': des = "Fine Weather"; break;
  case 'C': des = "Becoming Fine"; break;
  case 'D': des = "Fine, Becoming Less Settled"; break;
  case 'E': des = "Fine, Possibly showers"; break;
  case 'F': des = "Fairly Fine, Improving"; break;
  case 'G': des = "Fairly Fine, Possibly showers early"; break;
  case 'H': des = "Fairly Fine, Showers Later"; break;
  case 'I': des = "Showery Early, Improving"; break;
  case 'J': des = "Changeable Improving"; break;
  case 'K': des = "Fairly Fine, Showers likely"; break;
  case 'L': des = "Rather Unsettled Clearing Later"; break;
  case 'M': des = "Unsettled, Probably Improving"; break;
  case 'N': des = "Showery Bright Intervals"; break;
  case 'O': des = "Showery Becoming Unsettled"; break;
  case 'P': des = "Changeable some rain"; break;
  case 'Q': des = "Unsettled, short fine Intervals"; break;
  case 'R': des = "Unsettled, Rain later"; break;
  case 'S': des = "Unsettled, rain at times"; break;
  case 'T': des = "Very Unsettled, Finer at times"; break;
  case 'U': des = "Rain at times, Worse later"; break;
  case 'V': des = "Rain at times, becoming very unsettled"; break;
  case 'W': des = "Rain at Frequent Intervals"; break;
  case 'X': des = "Very Unsettled, Rain"; break;
  case 'Y': des = "Stormy, possibly improving"; break;
  case 'Z': des = "Stormy, much rain"; break;
   default: des = "Unknown"; break;
  }
  return des;
}
tuple <string,string,string> calc_zambretti(float zpressure, float trend) {
  string ztrend=get_trend_text(trend);
  time_t now =time(0);
  tm *ltm=localtime(&now);
  int zmonth ;
  zmonth=ltm->tm_mon;
  cout << zmonth;
  //pair<string,string> rslt;
  tuple <string,string,string> rslt;
  string wx_image;
  string wx_text;
  // FALLING
  if (ztrend == "Falling" ) {
    double zambretti = 0.0009746*zpressure*zpressure - 2.1068*zpressure+1138.7019; //y = 0.0009746x^2-2.1068x+1138.7019
    printf("zambetti %f \n",zambretti);    
// A Winter falling generally results in a Z value higher by 1 unit.
    if (zmonth < 4 || zmonth > 9) zambretti = zambretti + 1; // + makes the forecast worst, - better!
    switch (int(round(zambretti))) {
      case 1:  wx_text = 'A'; wx_image = "sunny"; break;       //Settled Fine
      case 2:  wx_text = 'B'; wx_image = "sunny"; break;       //Fine Weather
      case 3:  wx_text = 'D'; wx_image = "expectrain"; break;  //Fine Becoming Less Settled
      case 4:  wx_text = 'H'; wx_image = "expectrain"; break;  //Fairly Fine Showers Later
      case 5:  wx_text = 'O'; wx_image = "expectrain"; break;  //Showery Becoming unsettled
      case 6:  wx_text = 'R'; wx_image = "rain"; break;        //Unsettled, Rain later
      case 7:  wx_text = 'U'; wx_image = "rain"; break;        //Rain at times, worse later
      case 8:  wx_text = 'V'; wx_image = "rain"; break;        //Rain at times, becoming very unsettled
      case 9:  wx_text = 'X'; wx_image = "rain"; break;        //Very Unsettled, Rain
      default: wx_text = "unknown";        wx_image = "nodata"; break;
    }
  }
  // STEADY
  if (ztrend == "Steady") {
    float zambretti = 138.24-0.133*zpressure; // y = 138.24-0.1331x
    switch (int(round(zambretti))) {
      case 1:  wx_text = 'A'; wx_image = "sunny"; break;       //Settled Fine
      case 2:  wx_text = 'B'; wx_image = "sunny"; break;       //Fine Weather
      case 3:  wx_text = 'E'; wx_image = "expectrain"; break;  //Fine, Possibly showers
      case 4:  wx_text = 'K'; wx_image = "expectrain"; break;  //Fairly Fine, Showers likely
      case 5:  wx_text = 'N'; wx_image = "expectrain"; break;  //Showery Bright Intervals
      case 6:  wx_text = 'P'; wx_image = "cloudy"; break;      //Changeable some rain
      case 7:  wx_text = 'S'; wx_image = "rain"; break;        //Unsettled, rain at times
      case 8:  wx_text = 'W'; wx_image = "rain"; break;        //Rain at Frequent Intervals
      case 9:  wx_text = 'X'; wx_image = "rain"; break;        //Very Unsettled, Rain
      case 10: wx_text = 'Z'; wx_image = "tstorms"; break;     //Stormy, much rain
      default: wx_text = "unknown";        wx_image = "nodata"; break;
    }
  }
  // RISING
  if (ztrend == "Rising" ) {
    float zambretti = 142.57-0.1376*zpressure; //y = 142.57-0.1376x
    //A Summer rising, improves the prospects by 1 unit over a Winter rising
    if (zmonth < 4 || zmonth > 9) zambretti = zambretti + 1; // Increasing values makes the forecast worst!
    switch (int(round(zambretti))) {
      case 1:  wx_text = 'A'; wx_image = "sunny"; break;       //Settled Fine
      case 2:  wx_text = 'B'; wx_image = "sunny"; break;       //Fine Weather
      case 3:  wx_text = 'C'; wx_image = "mostlysunny"; break; //Becoming Fine
      case 4:  wx_text = 'F'; wx_image = "mostlysunny"; break; //Fairly Fine, Improving
      case 5:  wx_text = 'G'; wx_image = "expectrain"; break;  //Fairly Fine, Possibly showers, early
      case 6:  wx_text = 'I'; wx_image = "expectrain"; break;  //Showery Early, Improving
      case 7:  wx_text = 'J'; wx_image = "cloudy"; break;      //Changeable, Improving
      case 8:  wx_text = 'L'; wx_image = "cloudy"; break;      //Rather Unsettled Clearing Later
      case 9:  wx_text = 'M'; wx_image = "cloudy"; break;      //Unsettled, Probably Improving
      case 10: wx_text = 'Q'; wx_image = "mostlysunny"; break; //Unsettled, short fine Intervals
      case 11: wx_text = 'T'; wx_image = "cloudy"; break;      //Very Unsettled, Finer at times
      case 12: wx_text = 'Y'; wx_image = "tstorms"; break;     //Stormy, possibly improving
      case 13: wx_text = 'Z'; wx_image = "tstorms"; break;     //Stormy, much rain
      default: wx_text = "unknown";        wx_image = "nodata"; break;
    }
  }
cout << wx_text <<" "<< wx_image<< " " <<ztrend<<endl;
get<0>(rslt)=lettre_zambetti(wx_text);
get<1>(rslt)=wx_image;
get<2>(rslt)=ztrend;
//rslt.first=lettre_zambetti(wx_text);
//rslt.second=wx_image;
return rslt;
}
