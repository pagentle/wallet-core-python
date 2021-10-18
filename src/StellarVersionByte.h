#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStellarVersionByte.h>

struct PyStellarVersionByteObject {
    PyObject_HEAD
    const TWStellarVersionByte value;
};

PyObject* PyStellarVersionByte_FromTWStellarVersionByte(TWStellarVersionByte value);
bool PyInit_StellarVersionByte(PyObject *module);