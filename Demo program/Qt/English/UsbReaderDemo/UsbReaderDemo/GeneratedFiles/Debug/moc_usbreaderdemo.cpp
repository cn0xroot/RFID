/****************************************************************************
** Meta object code from reading C++ file 'usbreaderdemo.h'
**
** Created: Sat Oct 6 13:13:41 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../usbreaderdemo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usbreaderdemo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UsbReaderDemo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      44,   14,   14,   14, 0x0a,
      74,   14,   14,   14, 0x0a,
     100,   14,   14,   14, 0x0a,
     129,   14,   14,   14, 0x0a,
     155,   14,   14,   14, 0x0a,
     175,   14,   14,   14, 0x0a,
     196,   14,   14,   14, 0x0a,
     216,   14,   14,   14, 0x0a,
     237,   14,   14,   14, 0x0a,
     258,   14,   14,   14, 0x0a,
     281,   14,   14,   14, 0x0a,
     303,   14,   14,   14, 0x0a,
     323,   14,   14,   14, 0x0a,
     348,   14,   14,   14, 0x0a,
     374,   14,   14,   14, 0x0a,
     396,   14,   14,   14, 0x0a,
     419,   14,   14,   14, 0x0a,
     437,   14,   14,   14, 0x0a,
     463,   14,   14,   14, 0x0a,
     484,   14,   14,   14, 0x0a,
     506,   14,   14,   14, 0x0a,
     526,   14,   14,   14, 0x0a,
     549,   14,   14,   14, 0x0a,
     573,   14,   14,   14, 0x0a,
     595,   14,   14,   14, 0x0a,
     616,   14,   14,   14, 0x0a,
     640,   14,   14,   14, 0x0a,
     663,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UsbReaderDemo[] = {
    "UsbReaderDemo\0\0on_setsernumButton_clicked()\0"
    "on_readsernumButton_clicked()\0"
    "on_setledButton_clicked()\0"
    "on_setbuzzerButton_clicked()\0"
    "on_getverButton_clicked()\0on_mfRead_clicked()\0"
    "on_mfWrite_clicked()\0on_mfInit_clicked()\0"
    "on_mfDeval_clicked()\0on_mfInval_clicked()\0"
    "on_mfCardNum_clicked()\0on_utsnRead_clicked()\0"
    "on_utHalt_clicked()\0on_utblockRead_clicked()\0"
    "on_utwriteWrite_clicked()\0"
    "on_BRequest_clicked()\0on_BTransfer_clicked()\0"
    "on_BUid_clicked()\0on_isoInventory_clicked()\0"
    "on_isoRead_clicked()\0on_isoWrite_clicked()\0"
    "on_isoGet_clicked()\0on_blockLock_clicked()\0"
    "on_cardSelect_clicked()\0on_afiWrite_clicked()\0"
    "on_afiLock_clicked()\0on_dsfidWrite_clicked()\0"
    "on_dsfidLock_clicked()\0on_blksecGet_clicked()\0"
};

void UsbReaderDemo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UsbReaderDemo *_t = static_cast<UsbReaderDemo *>(_o);
        switch (_id) {
        case 0: _t->on_setsernumButton_clicked(); break;
        case 1: _t->on_readsernumButton_clicked(); break;
        case 2: _t->on_setledButton_clicked(); break;
        case 3: _t->on_setbuzzerButton_clicked(); break;
        case 4: _t->on_getverButton_clicked(); break;
        case 5: _t->on_mfRead_clicked(); break;
        case 6: _t->on_mfWrite_clicked(); break;
        case 7: _t->on_mfInit_clicked(); break;
        case 8: _t->on_mfDeval_clicked(); break;
        case 9: _t->on_mfInval_clicked(); break;
        case 10: _t->on_mfCardNum_clicked(); break;
        case 11: _t->on_utsnRead_clicked(); break;
        case 12: _t->on_utHalt_clicked(); break;
        case 13: _t->on_utblockRead_clicked(); break;
        case 14: _t->on_utwriteWrite_clicked(); break;
        case 15: _t->on_BRequest_clicked(); break;
        case 16: _t->on_BTransfer_clicked(); break;
        case 17: _t->on_BUid_clicked(); break;
        case 18: _t->on_isoInventory_clicked(); break;
        case 19: _t->on_isoRead_clicked(); break;
        case 20: _t->on_isoWrite_clicked(); break;
        case 21: _t->on_isoGet_clicked(); break;
        case 22: _t->on_blockLock_clicked(); break;
        case 23: _t->on_cardSelect_clicked(); break;
        case 24: _t->on_afiWrite_clicked(); break;
        case 25: _t->on_afiLock_clicked(); break;
        case 26: _t->on_dsfidWrite_clicked(); break;
        case 27: _t->on_dsfidLock_clicked(); break;
        case 28: _t->on_blksecGet_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData UsbReaderDemo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UsbReaderDemo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UsbReaderDemo,
      qt_meta_data_UsbReaderDemo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UsbReaderDemo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UsbReaderDemo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UsbReaderDemo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UsbReaderDemo))
        return static_cast<void*>(const_cast< UsbReaderDemo*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UsbReaderDemo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
