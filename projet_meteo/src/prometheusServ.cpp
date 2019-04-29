#include <iostream>
#include <unistd.h>
#include <chrono>
#include <map>
#include <memory>
#include <string>
#include <thread>
#include "capteur_bme.h"
#include "Objets.h"
#include <prometheus/exposer.h>
#include <prometheus/registry.h>
//using namespace std;
using namespace prometheus;
void thread_prometheus(Objets * capt){
	
	// Server http sur le port 8080
	Exposer exposer{"8080"};


	// Registre de métrique
	auto registry = std::make_shared<Registry>();


	//Utilisation d'un Gauge, une métrique qui représente une valeur numérique unique
	auto& temp = BuildGauge().Name("temperature")
							 						 .Help("Temperatures")
							             .Labels({{"meteo", "temperature"}})
							             .Register(*registry)
			                     .Add({{"metric", "temperature"}});
	auto& humi = BuildGauge().Name("humidite")
							             .Help("Humidite")
			                     .Labels({{"meteo", "humidite"}})
			                     .Register(*registry)
			                     .Add({{"metric", "humidity"}});
	auto& press = BuildGauge().Name("pression")
							              .Help("Pression")
							              .Labels({{"meteo", "pression"}})
							              .Register(*registry)
							              .Add({{"metric", "pression"}});

	exposer.RegisterCollectable(registry);

	for (;;) {
		//boucle d'envoie des données
		sleep(1);
		temp.Set(capt->temp());
		humi.Set(capt->humi());
		press.Set(capt->press());
	}
	 /*    for(;;){
         sleep(1);
		cout << capt->temp() << ",";
		cout << capt->humi() << ",";
		cout << capt->press() << ",";}
	*/
	
	
	}
