#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWPurpose.h>

struct PyPurposeObject {
    PyObject_HEAD
    const TWPurpose value;
};

PyObject* PyPurpose_FromTWPurpose(TWPurpose value);
bool PyInit_Purpose(PyObject *module);