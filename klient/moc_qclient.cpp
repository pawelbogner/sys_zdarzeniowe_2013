/****************************************************************************
** Meta object code from reading C++ file 'qclient.h'
**
** Created: Fri Dec 20 14:58:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      63,    9,    8,    8, 0x05,
     154,  130,    8,    8, 0x05,
     243,  226,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     274,    8,    8,    8, 0x08,
     286,    8,    8,    8, 0x08,
     301,    8,    8,    8, 0x08,
     332,  314,    8,    8, 0x0a,
     379,  364,    8,    8, 0x0a,
     441,  434,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QClient[] = {
    "QClient\0\0local_id,id,sector_size_x,sector_size_y,size_x,size_y\0"
    "register_robot_id(int32_t,int32_t,int32_t,int32_t,int32_t,int32_t)\0"
    "id,x,y,response,clients\0"
    "response_sector(int32_t,int32_t,int32_t,eSectorRequestResponse,int32_t"
    ")\0"
    "id,goto_x,goto_y\0go_to(int32_t,int32_t,int32_t)\0"
    "connected()\0disconnected()\0ready_read()\0"
    "local_id,diameter\0register_robot(int32_t,int32_t)\0"
    "id,x,y,request\0"
    "request_sector(int32_t,int32_t,int32_t,eSectorRequest)\0"
    "id,x,y\0current_position(int32_t,int32_t,int32_t)\0"
};

void QClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QClient *_t = static_cast<QClient *>(_o);
        switch (_id) {
        case 0: _t->register_robot_id((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3])),(*reinterpret_cast< int32_t(*)>(_a[4])),(*reinterpret_cast< int32_t(*)>(_a[5])),(*reinterpret_cast< int32_t(*)>(_a[6]))); break;
        case 1: _t->response_sector((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3])),(*reinterpret_cast< eSectorRequestResponse(*)>(_a[4])),(*reinterpret_cast< int32_t(*)>(_a[5]))); break;
        case 2: _t->go_to((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 3: _t->connected(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->ready_read(); break;
        case 6: _t->register_robot((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2]))); break;
        case 7: _t->request_sector((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3])),(*reinterpret_cast< eSectorRequest(*)>(_a[4]))); break;
        case 8: _t->current_position((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QClient,
      qt_meta_data_QClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QClient))
        return static_cast<void*>(const_cast< QClient*>(this));
    return QObject::qt_metacast(_clname);
}

int QClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QClient::register_robot_id(int32_t _t1, int32_t _t2, int32_t _t3, int32_t _t4, int32_t _t5, int32_t _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QClient::response_sector(int32_t _t1, int32_t _t2, int32_t _t3, eSectorRequestResponse _t4, int32_t _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QClient::go_to(int32_t _t1, int32_t _t2, int32_t _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
