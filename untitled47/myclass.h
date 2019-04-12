#ifndef MYCLASS_H
#define MYCLASS_H


#include <QObject>
#include<QDebug>
#include<QQuickItem>

class MyClass : public QObject
{
    Q_OBJECT
public slots:
    void cppSlot(const QVariant &v) {
       qDebug() << "Called the C++ slot with value:" << v;

       QQuickItem *item = qobject_cast<QQuickItem*>(v.value<QObject*>());
       qDebug()<< "Item dimensions:" << item->width()<< item->height();
    }
};

#endif // MYCLASS_H
