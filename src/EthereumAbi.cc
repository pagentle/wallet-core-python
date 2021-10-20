// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "EthereumAbi.h"

#include "Data.h"
#include "EthereumAbiFunction.h"

static PyTypeObject PyEthereumAbiType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumAbi",    /* tp_name */
    sizeof(PyEthereumAbiObject), /* tp_basicsize */
    0,                           /* tp_itemsize */
    0,                           /* tp_dealloc */
    0,                           /* tp_print */
    0,                           /* tp_getattr */
    0,                           /* tp_setattr */
    0,                           /* tp_reserved */
    0,                           /* tp_repr */
    0,                           /* tp_as_number */
    0,                           /* tp_as_sequence */
    0,                           /* tp_as_mapping */
    0,                           /* tp_hash  */
    0,                           /* tp_call */
    0,                           /* tp_str */
    0,                           /* tp_getattro */
    0,                           /* tp_setattro */
    0,                           /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,          /* tp_flags */
    nullptr,                     /* tp_doc */
};

bool PyEthereumAbi_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyEthereumAbiType) != 0;
}

// Create PyEthereumAbi from enum TWEthereumAbi.
PyObject* PyEthereumAbi_FromTWEthereumAbi(TWEthereumAbi* value) {
  if (!value)
    return nullptr;

  PyEthereumAbiObject* object =
      PyObject_New(PyEthereumAbiObject, &PyEthereumAbiType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWEthereumAbi* PyEthereumAbi_GetTWEthereumAbi(PyObject* object) {
  assert(PyEthereumAbi_Check(object));
  return ((PyEthereumAbiObject*)object)->value;
}

// static int PyEthereumAbi_init(PyEthereumAbiObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyEthereumAbi_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyEthereumAbi_FromTWEthereumAbi((TWEthereumAbi)value);
// }

// static PyObject* PyEthereumAbi_str(PyEthereumAbiObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// static method function for DecodeOutput
// bool TWEthereumAbiDecodeOutput(struct TWEthereumAbiFunction* fn, TWData*
// encoded);
static PyObject* PyEthereumAbiDecodeOutput(PyEthereumAbiObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyEthereumAbiFunction_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError,
                    "The arg 0 is not in type EthereumAbiFunction");
    return nullptr;
  }
  auto arg0 = PyEthereumAbiFunction_GetTWEthereumAbiFunction(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  bool result = TWEthereumAbiDecodeOutput(arg0, arg1.get());
  return PyBool_FromLong(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"DecodeOutput", (PyCFunction)PyEthereumAbiDecodeOutput,
     METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_EthereumAbi(PyObject* module) {
  // PyEthereumAbiType.tp_new = PyEthereumAbi_new;
  // PyEthereumAbiType.tp_init = (initproc)PyEthereumAbi_init;
  // PyEthereumAbiType.tp_str = (reprfunc)PyEthereumAbi_str;
  PyEthereumAbiType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumAbiType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumAbiType) < 0)
    return false;

  Py_INCREF(&PyEthereumAbiType);
  if (PyModule_AddObject(module, "EthereumAbi", (PyObject*)&PyEthereumAbiType) <
      0) {
    Py_DECREF(&PyEthereumAbiType);
    return false;
  }

  return true;
}