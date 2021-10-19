// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "StellarMemoType.h"



#define CONSTANTS(I) \
    I(None) \
    I(Text) \
    I(Id) \
    I(Hash) \
    I(Return) \

PyTypeObject PyStellarMemoTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.StellarMemoType",      /* tp_name */
    sizeof(PyStellarMemoTypeObject),   /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    nullptr,                   /* tp_doc */
};

PyObject* PyStellarMemoType_FromTWStellarMemoType(TWStellarMemoType value) {
    struct ValuePair {
        TWStellarMemoType value;
        PyObject* pyvalue;
    };
#define I(name) { TWStellarMemoType##name, nullptr },
    static ValuePair constants[] = {
        CONSTANTS(I)
    };
#undef I

    ValuePair* value_pair = nullptr;
    for (auto& constant : constants) {
        if (constant.value == value) {
            value_pair = &constant;
            break;
        }
    }

    if (!value_pair) {
        PyErr_Format(PyExc_ValueError, "Invalid StellarMemoType value: %d", value);
        return nullptr;
    }

    if (!value_pair->pyvalue) {
        auto* pyvalue = PyObject_New(PyStellarMemoTypeObject, &PyStellarMemoTypeType);
        *const_cast<TWStellarMemoType*>(&pyvalue->value) = value;
        value_pair->pyvalue = (PyObject*)pyvalue;
    }

    Py_INCREF(value_pair->pyvalue);
    return value_pair->pyvalue;
}

static int PyStellarMemoType_init(PyStellarMemoTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

static PyObject* PyStellarMemoType_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds) {
    int value = 0;
    if (!PyArg_ParseTuple(args, "|i", &value)) {
        return nullptr;
    }
    return PyStellarMemoType_FromTWStellarMemoType((TWStellarMemoType)value);
}

static PyObject* PyStellarMemoType_str(PyStellarMemoTypeObject *self) {
    const char* str = "Unknown";
    switch(self->value) {
#define I(name) \
        case TWStellarMemoType##name: \
            str = #name; \
            break;
        CONSTANTS(I)
#undef I
    }
    return PyUnicode_FromString(str);
}



static PyGetSetDef get_set_def[] = {
    
    {},
};

bool PyInit_StellarMemoType(PyObject *module) {

    PyStellarMemoTypeType.tp_new = PyStellarMemoType_new;
    PyStellarMemoTypeType.tp_init = (initproc)PyStellarMemoType_init;
    PyStellarMemoTypeType.tp_str = (reprfunc)PyStellarMemoType_str;
    PyStellarMemoTypeType.tp_getset = (PyGetSetDef*)get_set_def;

    if (PyType_Ready(&PyStellarMemoTypeType) < 0)
        return false;

    Py_INCREF(&PyStellarMemoTypeType);
    if (PyModule_AddObject(module, "StellarMemoType", (PyObject *) &PyStellarMemoTypeType) < 0) {
        Py_DECREF(&PyStellarMemoTypeType);
        return false;
    }

    PyObject* dict = PyStellarMemoTypeType.tp_dict;
    (void)dict;

#define I(name) \
    PyDict_SetItemString(dict, #name, PyStellarMemoType_FromTWStellarMemoType(TWStellarMemoType##name));
    CONSTANTS(I)
#undef I

    return true;
}