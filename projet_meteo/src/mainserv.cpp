#include "capteur_bme.h"

#include <chrono>
#include <map>
#include <memory>
#include <string>
#include <thread>
#include "capteur_bme.h"
#include "Objets.h"
#include <prometheus/exposer.h>
#include <prometheus/registry.h>


int main() {
	Objets capt;
	using namespace prometheus;
	struct bme280_data data;
	struct bme280_dev dev=init_capteur();

	// Server http sur le port 8080
	Exposer exposer{"8080"};


	// Registre de métrique
	auto registry = std::make_shared<Registry>();


	//Utilisation d'un Gauge, une métrique qui représente une valeur numérique unique
	auto& temp = BuildGauge().Name("temperature")
							 						 .Help("Temperatures")
							             .Labels({{"meteo", "temperature"}})
							             .Register(*registry)
			                     .Add({{"metric", "temp"}});
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
		data=lecture_data_capteur(&dev);
		temp.Set(data.temperature);
		humi.Set(data.humidity);
		press.Set(data.pressure);
	}
	return 0;
}
