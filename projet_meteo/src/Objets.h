#pragma once
#include <QObject>
#include <QString>
#include "zambetti.h"
#include "bme280.h"
class Objets : public QObject
{
	Q_OBJECT
    Q_PROPERTY(qreal temp READ temp		NOTIFY tempChanged)
    Q_PROPERTY(qreal humi READ humi		NOTIFY humiChanged)
    Q_PROPERTY(qreal press READ press	NOTIFY pressChanged)
    Q_PROPERTY(QString des READ des	NOTIFY desChanged)
    Q_PROPERTY(QString img READ img     NOTIFY imgChanged)
private:
    qreal m_temp=18;
    qreal m_humi= 33;
    qreal m_press=1001;
    QString m_des;
    QString m_img;
    struct bme280_dev m_dev;
signals:
    void tempChanged();
    void humiChanged();
    void pressChanged();
    void desChanged();
    void imgChanged();
public slots:
	void refresh();
public:
    Objets();
    qreal temp() const;
    qreal humi() const;
    qreal press() const;
    QString des() const;
    QString img() const;
   
};
