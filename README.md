# Projet Station Météo

Notre Station Météo est une application embarquée sur Raspberry Pi avec un capteur BME280 pour la récupération de métriques tels que l'humidité, la température et la pression atmosphérique. Notre application permet aussi la prévision météorologique avec l'algorithme de  Zambretti.

Le projet s'est déroulé sur 3 semaines. Notre projet a été implémenté sur un [Raspberry Pi 3B+](https://www.raspberrypi.org/products/raspberry-pi-3-model-b-plus/) et un capteur [BME280](https://www.waveshare.com/wiki/BME280_Environmental_Sensor).

La prédiction sur 4 heures est  basée sur l'algorithme de [Zambretti](http://drkfs.net/zambretti.htm)


## Guide d'installation

Lien doc généré par doxygen :https://tsogh.github.io/projet_meteo/class_objets.html

### Pré-requis

Avoir un Rapsberry Pi avec la distribution Raspbian à jour.

Les dépendances Qt et QML nécessaires à l'exécution de notre projet

```
sudo apt-get install qt5-default qt5-qmake qtdeclarative5-dev qtdeclarative5-dev-tools qml-module-qtquick2 qml-module-qtquick-controls
```

Qmake pour la compilation

```
sudo apt-get install Qmake
```

Pour l'installation de Prometheus et Grafana, utiliser le script fourni dans le dépôt.

### Mise en place du capteur

Nous avons décidé d'installer le capteur en I2C. Il faut activer l'I2C via le configurateur du Raspberry.

```
sudo raspi-config
```

La connexion du capteur se fait sur les ports GPIO 1 pour l'alimentation, 3 pour le SDA, 5 pour le SDC et 6 pour le GND.

### Compilation

Se positionner dans le répertoire courant StationMeteo.

Exécuter Qmake pour compiler l'application

```
qmake AppMeteo.pro
make
```

Exécuter Qmake pour compiler le serveur de visualisation de données

```
qmake ServerMeteo.pro
make
```

Il est conseillé de faire un '''make clean''' entre les deux compilations.

### Exécution

```
./AppMeteo
./ServerMeteo
```

### Visualisation des données Grafana et Prometheus

Lancer Prometheus

```systemctl start Prometheus```

Modifier le fichier prometheus.yml (etc/prometheus) comme suit :

```
- job_name: ServPro
  # If prometheus-node-exporter is installed, grab stats about the local
  # machine by default.
  static_configs:
    - targets: ['localhost:8080']
```

Ensuite dans Grafana, ajouter un DashBoard, puis ajouter un panel et indiquer temperature pour la température, humidite pour le taux d'humidité et pression pour la pression atmosphérique dans le query du panel. Pour finir sauvegarder pour pouvoir afficher les données.






### Auteurs

* **Colinet Maxime** - *Implémentation de de l'application* - [Tsogh](https://github.com/tsogh/)

* **Turines Alexia** - *Contributeur* - [Alexia31200](https://github.com/Alexia31200)
