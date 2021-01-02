/****************************************************************************
** Meta object code from reading C++ file 'QtView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QtView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtView_t {
    QByteArrayData data[22];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtView_t qt_meta_stringdata_QtView = {
    {
QT_MOC_LITERAL(0, 0, 6), // "QtView"
QT_MOC_LITERAL(1, 7, 11), // "filepathSet"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "savepathSet"
QT_MOC_LITERAL(4, 32, 19), // "archiveFilesChanged"
QT_MOC_LITERAL(5, 52, 14), // "archiveNameSet"
QT_MOC_LITERAL(6, 67, 10), // "messageSet"
QT_MOC_LITERAL(7, 78, 9), // "showFiles"
QT_MOC_LITERAL(8, 88, 14), // "dearchiveFiles"
QT_MOC_LITERAL(9, 103, 8), // "addFiles"
QT_MOC_LITERAL(10, 112, 5), // "input"
QT_MOC_LITERAL(11, 118, 12), // "archiveFiles"
QT_MOC_LITERAL(12, 131, 5), // "clear"
QT_MOC_LITERAL(13, 137, 4), // "open"
QT_MOC_LITERAL(14, 142, 8), // "QString&"
QT_MOC_LITERAL(15, 151, 3), // "url"
QT_MOC_LITERAL(16, 155, 8), // "filepath"
QT_MOC_LITERAL(17, 164, 16), // "files_in_archive"
QT_MOC_LITERAL(18, 181, 8), // "savepath"
QT_MOC_LITERAL(19, 190, 12), // "archive_name"
QT_MOC_LITERAL(20, 203, 7), // "message"
QT_MOC_LITERAL(21, 211, 7) // "success"

    },
    "QtView\0filepathSet\0\0savepathSet\0"
    "archiveFilesChanged\0archiveNameSet\0"
    "messageSet\0showFiles\0dearchiveFiles\0"
    "addFiles\0input\0archiveFiles\0clear\0"
    "open\0QString&\0url\0filepath\0files_in_archive\0"
    "savepath\0archive_name\0message\0success"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       6,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    1,   71,    2, 0x06 /* Public */,
       5,    0,   74,    2, 0x06 /* Public */,
       6,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   76,    2, 0x0a /* Public */,
       8,    0,   77,    2, 0x0a /* Public */,
       9,    1,   78,    2, 0x0a /* Public */,
      11,    0,   81,    2, 0x0a /* Public */,
      12,    0,   82,    2, 0x0a /* Public */,
      13,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

 // properties: name, type, flags
      16, QMetaType::QString, 0x00495003,
      17, QMetaType::QStringList, 0x00495001,
      18, QMetaType::QString, 0x00495003,
      19, QMetaType::QString, 0x00495003,
      20, QMetaType::QString, 0x00495001,
      21, QMetaType::Bool, 0x00095001,

 // properties: notify_signal_id
       0,
       2,
       1,
       3,
       4,
       0,

       0        // eod
};

void QtView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filepathSet(); break;
        case 1: _t->savepathSet(); break;
        case 2: _t->archiveFilesChanged((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->archiveNameSet(); break;
        case 4: _t->messageSet(); break;
        case 5: _t->showFiles(); break;
        case 6: _t->dearchiveFiles(); break;
        case 7: _t->addFiles((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->archiveFiles(); break;
        case 9: _t->clear(); break;
        case 10: _t->open((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtView::filepathSet)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtView::savepathSet)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtView::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtView::archiveFilesChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QtView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtView::archiveNameSet)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QtView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtView::messageSet)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->get_filepath(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->get_files_in_archive(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->get_savepath(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->get_archive_name(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->get_message(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->get_info(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_filepath(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->set_savepath(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->set_archive_name(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QtView::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QtView.data,
    qt_meta_data_QtView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtView.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "View"))
        return static_cast< View*>(this);
    return QObject::qt_metacast(_clname);
}

int QtView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
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
void QtView::filepathSet()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtView::savepathSet()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtView::archiveFilesChanged(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtView::archiveNameSet()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QtView::messageSet()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
