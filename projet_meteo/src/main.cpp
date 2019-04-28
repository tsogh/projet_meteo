#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Objets.h"
#include <QtDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Objets capt;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("capt", &capt);
    engine.load(QUrl(QStringLiteral("src/qml/main.qml")));
    return app.exec();
}
