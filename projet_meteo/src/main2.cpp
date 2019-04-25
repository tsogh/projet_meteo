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


int main(int argc, char** argv) {
	Objets capt;
	using namespace prometheus;
	struct bme280_data data;
	struct bme280_dev dev=init_capteur();
	
	// create an http server running on port 8080
	Exposer exposer{"8080"};

	// create a metrics registry with component=main labels applied to all its
	// metrics
	auto registry = std::make_shared<Registry>();

	// add a new counter family to the registry (families combine values with the
	// same name, but distinct label dimensions)
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

	// ask the exposer to scrape the registry on incoming scrapes
	exposer.RegisterCollectable(registry);

	for (;;) {
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		data=lecture_data_capteur(&dev);
		temp.Set(data.temperature);
		humi.Set(data.humidity);
		press.Set(data.pressure);
	}
	return 0;
}
