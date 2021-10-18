#include "EthereumChainID.h"

static PyTypeObject PyEthereumChainIDType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.EthereumChainID",      /* tp_name */
    sizeof(PyEthereumChainIDObject),   /* tp_basicsize */
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

int PyEthereumChainID_init(PyEthereumChainIDObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_EthereumChainID(PyObject *module) {
    PyEthereumChainIDType.tp_init = (initproc)PyEthereumChainID_init;
    PyEthereumChainIDType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyEthereumChainIDType) < 0)
        return false;

    Py_INCREF(&PyEthereumChainIDType);
    if (PyModule_AddObject(module, "EthereumChainID", (PyObject *) &PyEthereumChainIDType) < 0) {
        Py_DECREF(&PyEthereumChainIDType);
        return false;
    }

    // auto* o = PyObject_New(PyEthereumChainIDObject, &PyEthereumChainIDType);

    PyObject* dict = PyEthereumChainIDType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "Ethereum", PyLong_FromLong(TWEthereumChainIDEthereum));
    PyDict_SetItemString(dict, "Go", PyLong_FromLong(TWEthereumChainIDGo));
    PyDict_SetItemString(dict, "POA", PyLong_FromLong(TWEthereumChainIDPOA));
    PyDict_SetItemString(dict, "Callisto", PyLong_FromLong(TWEthereumChainIDCallisto));
    PyDict_SetItemString(dict, "EthereumClassic", PyLong_FromLong(TWEthereumChainIDEthereumClassic));
    PyDict_SetItemString(dict, "VeChain", PyLong_FromLong(TWEthereumChainIDVeChain));
    PyDict_SetItemString(dict, "ThunderToken", PyLong_FromLong(TWEthereumChainIDThunderToken));
    PyDict_SetItemString(dict, "TomoChain", PyLong_FromLong(TWEthereumChainIDTomoChain));
    PyDict_SetItemString(dict, "BinanceSmartChain", PyLong_FromLong(TWEthereumChainIDBinanceSmartChain));
    PyDict_SetItemString(dict, "Polygon", PyLong_FromLong(TWEthereumChainIDPolygon));
    PyDict_SetItemString(dict, "Wanchain", PyLong_FromLong(TWEthereumChainIDWanchain));
    PyDict_SetItemString(dict, "Optimism", PyLong_FromLong(TWEthereumChainIDOptimism));
    PyDict_SetItemString(dict, "Arbitrum", PyLong_FromLong(TWEthereumChainIDArbitrum));
    PyDict_SetItemString(dict, "Heco", PyLong_FromLong(TWEthereumChainIDHeco));
    PyDict_SetItemString(dict, "Avalanche", PyLong_FromLong(TWEthereumChainIDAvalanche));
    PyDict_SetItemString(dict, "XDai", PyLong_FromLong(TWEthereumChainIDXDai));
    PyDict_SetItemString(dict, "Fantom", PyLong_FromLong(TWEthereumChainIDFantom));
    PyDict_SetItemString(dict, "Celo", PyLong_FromLong(TWEthereumChainIDCelo));
    PyDict_SetItemString(dict, "Ronin", PyLong_FromLong(TWEthereumChainIDRonin));

    return true;
}