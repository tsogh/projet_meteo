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
    Q_PROPERTY(QString color READ color	NOTIFY colorChanged)
    Q_PROPERTY(qreal alti READ alti	WRITE set_alti NOTIFY altiChanged)

private:
    int demo_code=1;
    qreal m_temp=18;
    qreal m_humi= 33;
    qreal m_press=1001;
    QString m_code_couleur;
    QString m_des;
    QString m_img;
    QString m_trend;
		qreal m_alti=0;
		qreal m_press_corrige;
    struct bme280_dev m_dev;
    QString m_fleche;
    std::vector<qreal> his_h;
    std::vector<qreal> his_m;
    std::vector<qreal> his_s;
    struct bme280_data data;
signals:
    void tempChanged();
    void humiChanged();
    void pressChanged();
    void desChanged();
    void imgChanged();
    void flecheChanged();
    void colorChanged();
    void altiChanged();
public slots:
		void refresh();
    void refresh_demo();
public:
    qreal calcul_tendance();
    void recup_val();
    void calcul_zam();
    void histo_press();
    void table_rslt_zambetti(int code);
    Objets();
    qreal temp() const;
    qreal humi() const;
    qreal press() const;
    qreal alti() const;
    QString des() const;
    QString img() const;
    QString fleche() const;
    QString color() const;
		void calcul_altitude();
        void convert_pressAbs(qreal press, qreal altitude,qreal temp);
		void set_alti(qreal alti);

};
