/****************************************************************************
** Meta object code from reading C++ file 'eter.h'
**
** Created: Sat Dec 28 12:49:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "eter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ether[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      61,    7,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ether[] = {
    "Ether\0\0local_id,id,sector_size_x,sector_size_y,size_x,size_y\0"
    "registerRobotInEter(int32_t,int32_t,int32_t,int32_t,int32_t,int32_t)\0"
};

void Ether::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Ether *_t = static_cast<Ether *>(_o);
        switch (_id) {
        case 0: _t->registerRobotInEter((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3])),(*reinterpret_cast< int32_t(*)>(_a[4])),(*reinterpret_cast< int32_t(*)>(_a[5])),(*reinterpret_cast< int32_t(*)>(_a[6]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Ether::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ether::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ether,
      qt_meta_data_Ether, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ether::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ether::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ether::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ether))
        return static_cast<void*>(const_cast< Ether*>(this));
    return QObject::qt_metacast(_clname);
}

int Ether::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
