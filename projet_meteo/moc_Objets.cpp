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
    QByteArrayData data[15];
    char stringdata0[120];
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
QT_MOC_LITERAL(8, 81, 7), // "refresh"
QT_MOC_LITERAL(9, 89, 4), // "temp"
QT_MOC_LITERAL(10, 94, 4), // "humi"
QT_MOC_LITERAL(11, 99, 5), // "press"
QT_MOC_LITERAL(12, 105, 3), // "des"
QT_MOC_LITERAL(13, 109, 3), // "img"
QT_MOC_LITERAL(14, 113, 6) // "fleche"

    },
    "Objets\0tempChanged\0\0humiChanged\0"
    "pressChanged\0desChanged\0imgChanged\0"
    "flecheChanged\0refresh\0temp\0humi\0press\0"
    "des\0img\0fleche"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Objets[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       6,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QReal, 0x00495001,
      10, QMetaType::QReal, 0x00495001,
      11, QMetaType::QReal, 0x00495001,
      12, QMetaType::QString, 0x00495001,
      13, QMetaType::QString, 0x00495001,
      14, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,

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
        case 6: _t->refresh(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
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
QT_END_MOC_NAMESPACE
