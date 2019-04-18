/****************************************************************************
** Meta object code from reading C++ file 'Objets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/Objets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Objets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Objets_t {
    QByteArrayData data[18];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Objets_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Objets_t qt_meta_stringdata_Objets = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Objets"
QT_MOC_LITERAL(1, 7, 11), // "tempChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "humiChanged"
QT_MOC_LITERAL(4, 32, 12), // "pressChanged"
QT_MOC_LITERAL(5, 45, 10), // "desChanged"
QT_MOC_LITERAL(6, 56, 10), // "imgChanged"
QT_MOC_LITERAL(7, 67, 13), // "flecheChanged"
QT_MOC_LITERAL(8, 81, 12), // "colorChanged"
QT_MOC_LITERAL(9, 94, 7), // "refresh"
QT_MOC_LITERAL(10, 102, 12), // "refresh_demo"
QT_MOC_LITERAL(11, 115, 4), // "temp"
QT_MOC_LITERAL(12, 120, 4), // "humi"
QT_MOC_LITERAL(13, 125, 5), // "press"
QT_MOC_LITERAL(14, 131, 3), // "des"
QT_MOC_LITERAL(15, 135, 3), // "img"
QT_MOC_LITERAL(16, 139, 6), // "fleche"
QT_MOC_LITERAL(17, 146, 5) // "color"

    },
    "Objets\0tempChanged\0\0humiChanged\0"
    "pressChanged\0desChanged\0imgChanged\0"
    "flecheChanged\0colorChanged\0refresh\0"
    "refresh_demo\0temp\0humi\0press\0des\0img\0"
    "fleche\0color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Objets[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       7,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      11, QMetaType::QReal, 0x00495001,
      12, QMetaType::QReal, 0x00495001,
      13, QMetaType::QReal, 0x00495001,
      14, QMetaType::QString, 0x00495001,
      15, QMetaType::QString, 0x00495001,
      16, QMetaType::QString, 0x00495001,
      17, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

       0        // eod
};

void Objets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Objets *_t = static_cast<Objets *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tempChanged(); break;
        case 1: _t->humiChanged(); break;
        case 2: _t->pressChanged(); break;
        case 3: _t->desChanged(); break;
        case 4: _t->imgChanged(); break;
        case 5: _t->flecheChanged(); break;
        case 6: _t->colorChanged(); break;
        case 7: _t->refresh(); break;
        case 8: _t->refresh_demo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Objets::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Objets::tempChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Objets::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Objets::humiChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Objets::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Objets::pressChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Objets::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Objets::desChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Objets::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Objets::imgChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Objets::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Objets::flecheChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Objets::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Objets::colorChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Objets *_t = static_cast<Objets *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->temp(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->humi(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->press(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->des(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->img(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->fleche(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->color(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject Objets::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Objets.data,
      qt_meta_data_Objets,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Objets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Objets::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Objets.stringdata0))
        return static_cast<void*>(const_cast< Objets*>(this));
    return QObject::qt_metacast(_clname);
}

int Objets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Objets::tempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Objets::humiChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Objets::pressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Objets::desChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Objets::imgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Objets::flecheChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Objets::colorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
