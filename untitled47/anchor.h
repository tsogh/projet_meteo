#ifndef ANCHOR_H
#define ANCHOR_H


#include <QObject>
#include <QColor>
#include <QString>

class Anchor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    Anchor() : _color(Qt::black), _text("") { }
    QColor color() const {
        return _color;
    }
    QString text() const {
        return _text;
    }
    void setColor(const QColor &color) {
        _color = color;
        emit colorChanged();
    }
    void setText(const QString &text) {
        _text = text;
        emit textChanged();
    }

signals:
    void colorChanged();
    void textChanged();

private:
    QColor _color;
    QString _text;
};

#endif // ANCHOR_H
