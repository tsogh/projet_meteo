#pragma once
#include <QObject>
#include <QString>
#include "zambetti.h"
#include "bme280.h"
#include "vector"
class Objets : public QObject
{
	Q_OBJECT
    Q_PROPERTY(qreal temp READ temp		NOTIFY tempChanged)
    Q_PROPERTY(qreal humi READ humi		NOTIFY humiChanged)
    Q_PROPERTY(qreal press READ press	NOTIFY pressChanged)
    Q_PROPERTY(QString des READ des	NOTIFY desChanged)
    Q_PROPERTY(QString img READ img     NOTIFY imgChanged)
    Q_PROPERTY(QString fleche READ fleche     NOTIFY flecheChanged)

private:
    qreal m_temp=18;
    qreal m_humi= 33;
    qreal m_press=1001;
    QString m_des;
    QString m_img;
    QString m_trend;
    struct bme280_dev m_dev;
    QString m_fleche;
		std::vector<qreal> his_h;
		std::vector<qreal> his_m;
		std::vector<qreal> his_s;

signals:
    void tempChanged();
    void humiChanged();
    void pressChanged();
    void desChanged();
    void imgChanged();
    void flecheChanged();
public slots:
	void refresh();
public:
	  void histo_press();
    Objets();
    qreal temp() const;
    qreal humi() const;
    qreal press() const;
    QString des() const;
    QString img() const;
    QString fleche() const;

};
