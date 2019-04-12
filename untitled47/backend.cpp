#include "backend.h"
#include <iostream>
#include <QDebug>
BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
}

QString BackEnd::userName()
{
    return m_userName;
}

QString BackEnd::getTemperature()
{
    return m_temperature;
}

void BackEnd::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    qDebug() << userName;
    emit userNameChanged();
}