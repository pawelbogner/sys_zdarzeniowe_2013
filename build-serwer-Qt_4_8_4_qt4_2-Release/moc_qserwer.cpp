/****************************************************************************
** Meta object code from reading C++ file 'qserwer.h'
**
** Created: Sun Dec 15 21:07:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serwer/qserwer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qserwer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSerwer[] = {

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
      27,    9,    8,    8, 0x05,
      80,   59,    8,    8, 0x05,
     148,  135,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     200,  195,  190,    8, 0x0a,
     221,    8,    8,    8, 0x0a,
     258,  234,    8,    8, 0x0a,
     347,  330,    8,    8, 0x0a,
     382,    8,    8,    8, 0x08,
     400,  398,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QSerwer[] = {
    "QSerwer\0\0robot_id,diameter\0"
    "register_robot(int32_t,int32_t)\0"
    "robot_id,x,y,request\0"
    "request_sector(int32_t,int32_t,int32_t,eSectorRequest)\0"
    "robot_id,x,y\0current_position(int32_t,int32_t,int32_t)\0"
    "bool\0port\0StartServer(quint16)\0"
    "StopServer()\0id,x,y,response,clients\0"
    "response_sector(int32_t,int32_t,int32_t,eSectorRequestResponse,int32_t"
    ")\0"
    "id,goto_x,goto_y\0goto_task(int32_t,int32_t,int32_t)\0"
    "NewConnection()\0s\0ReadData(QObject*)\0"
};

void QSerwer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSerwer *_t = static_cast<QSerwer *>(_o);
        switch (_id) {
        case 0: _t->register_robot((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2]))); break;
        case 1: _t->request_sector((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3])),(*reinterpret_cast< eSectorRequest(*)>(_a[4]))); break;
        case 2: _t->current_position((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 3: { bool _r = _t->StartServer((*reinterpret_cast< quint16(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->StopServer(); break;
        case 5: _t->response_sector((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3])),(*reinterpret_cast< eSectorRequestResponse(*)>(_a[4])),(*reinterpret_cast< int32_t(*)>(_a[5]))); break;
        case 6: _t->goto_task((*reinterpret_cast< int32_t(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int32_t(*)>(_a[3]))); break;
        case 7: _t->NewConnection(); break;
        case 8: _t->ReadData((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSerwer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSerwer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSerwer,
      qt_meta_data_QSerwer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSerwer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSerwer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSerwer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSerwer))
        return static_cast<void*>(const_cast< QSerwer*>(this));
    return QObject::qt_metacast(_clname);
}

int QSerwer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QSerwer::register_robot(int32_t _t1, int32_t _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSerwer::request_sector(int32_t _t1, int32_t _t2, int32_t _t3, eSectorRequest _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSerwer::current_position(int32_t _t1, int32_t _t2, int32_t _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
