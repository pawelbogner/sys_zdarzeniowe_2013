/****************************************************************************
** Meta object code from reading C++ file 'mapka.h'
**
** Created: Mon Nov 18 16:28:13 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mapka.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapka.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Mapka[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      25,    6,    6,    6, 0x08,
      44,    6,    6,    6, 0x08,
      61,    6,    6,    6, 0x08,
      85,   79,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Mapka[] = {
    "Mapka\0\0on_gora_clicked()\0on_prawo_clicked()\0"
    "on_dol_clicked()\0on_lewo_clicked()\0"
    "value\0on_Zoom_valueChanged(int)\0"
};

void Mapka::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Mapka *_t = static_cast<Mapka *>(_o);
        switch (_id) {
        case 0: _t->on_gora_clicked(); break;
        case 1: _t->on_prawo_clicked(); break;
        case 2: _t->on_dol_clicked(); break;
        case 3: _t->on_lewo_clicked(); break;
        case 4: _t->on_Zoom_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Mapka::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Mapka::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Mapka,
      qt_meta_data_Mapka, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Mapka::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Mapka::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Mapka::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mapka))
        return static_cast<void*>(const_cast< Mapka*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Mapka::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
