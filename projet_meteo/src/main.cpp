#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Objets.h"
#include <QtDebug>
#include <thread>
#include <mutex>
#include <iostream>
#include "prometheusServ.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Objets capt;
    thread v(thread_prometheus,&capt);
    v.detach();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("capt", &capt);
    engine.load(QUrl(QStringLiteral("src/qml/main.qml")));
    return app.exec();
}
