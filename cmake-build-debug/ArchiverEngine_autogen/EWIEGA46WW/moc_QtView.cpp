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
struct qt_meta_stringdata_KeyGenerator_t {
    QByteArrayData data[13];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeyGenerator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeyGenerator_t qt_meta_stringdata_KeyGenerator = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KeyGenerator"
QT_MOC_LITERAL(1, 13, 11), // "typeChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "typesChanged"
QT_MOC_LITERAL(4, 39, 15), // "filenameChanged"
QT_MOC_LITERAL(5, 55, 17), // "passphraseChanged"
QT_MOC_LITERAL(6, 73, 12), // "keyGenerated"
QT_MOC_LITERAL(7, 86, 7), // "success"
QT_MOC_LITERAL(8, 94, 11), // "generateKey"
QT_MOC_LITERAL(9, 106, 4), // "type"
QT_MOC_LITERAL(10, 111, 5), // "types"
QT_MOC_LITERAL(11, 117, 8), // "filename"
QT_MOC_LITERAL(12, 126, 10) // "passphrase"

    },
    "KeyGenerator\0typeChanged\0\0typesChanged\0"
    "filenameChanged\0passphraseChanged\0"
    "keyGenerated\0success\0generateKey\0type\0"
    "types\0filename\0passphrase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyGenerator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::QStringList, 0x00495001,
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void KeyGenerator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KeyGenerator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->typeChanged(); break;
        case 1: _t->typesChanged(); break;
        case 2: _t->filenameChanged(); break;
        case 3: _t->passphraseChanged(); break;
        case 4: _t->keyGenerated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->generateKey(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KeyGenerator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyGenerator::typeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KeyGenerator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyGenerator::typesChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KeyGenerator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyGenerator::filenameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KeyGenerator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyGenerator::passphraseChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (KeyGenerator::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyGenerator::keyGenerated)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<KeyGenerator *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->type(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->types(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->filename(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->filename(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<KeyGenerator *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setType(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setFilename(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setPassphrase(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject KeyGenerator::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_KeyGenerator.data,
    qt_meta_data_KeyGenerator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KeyGenerator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyGenerator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KeyGenerator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KeyGenerator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void KeyGenerator::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void KeyGenerator::typesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void KeyGenerator::filenameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void KeyGenerator::passphraseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void KeyGenerator::keyGenerated(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
