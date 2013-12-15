/****************************************************************************
** Meta object code from reading C++ file 'klient.h'
**
** Created: Sun Dec 15 11:57:37 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "klient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'klient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_klient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      32,    7,    7,    7, 0x08,
      58,    7,    7,    7, 0x08,
     138,   84,    7,    7, 0x08,
     229,  205,    7,    7, 0x08,
     318,  301,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_klient[] = {
    "klient\0\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "local_id,id,sector_size_x,sector_size_y,size_x,size_y\0"
    "register_robot_id(int32_t,int32_t,int32_t,int32_t,int32_t,int32_t)\0"
    "id,x,y,response,clients\0"
    "response_sector(int32_t,int32_t,int32_t,eSectorRequestResponse,int32_t"
    ")\0"
    "id,goto_x,goto_y\0go_to(int32_t,int32_t,int32_t)\0"
};

void klient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        klient *_t = static_cast<klient *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->register_robot_id((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3])),(*reinterpret_cast< int32_t(*)>(_a[4])),(*reinterpret_cast< int32_t(*)>(_a[5])),(*reinterpret_cast< int32_t(*)>(_a[6]))); break;
        case 4: _t->response_sector((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3])),(*reinterpret_cast< eSectorRequestResponse(*)>(_a[4])),(*reinterpret_cast< int32_t(*)>(_a[5]))); break;
        case 5: _t->go_to((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData klient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject klient::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_klient,
      qt_meta_data_klient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &klient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *klient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *klient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_klient))
        return static_cast<void*>(const_cast< klient*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int klient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
