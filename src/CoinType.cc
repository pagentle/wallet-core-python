#include "CoinType.h"

#define CONSTANTS(I) \
    I(Aeternity) \
    I(Aion) \
    I(Binance) \
    I(Bitcoin) \
    I(BitcoinCash) \
    I(BitcoinGold) \
    I(Callisto) \
    I(Cardano) \
    I(Cosmos) \
    I(Dash) \
    I(Decred) \
    I(DigiByte) \
    I(Dogecoin) \
    I(EOS) \
    I(Ethereum) \
    I(EthereumClassic) \
    I(FIO) \
    I(GoChain) \
    I(Groestlcoin) \
    I(ICON) \
    I(IoTeX) \
    I(Kava) \
    I(Kin) \
    I(Litecoin) \
    I(Monacoin) \
    I(Nebulas) \
    I(NULS) \
    I(Nano) \
    I(NEAR) \
    I(Nimiq) \
    I(Ontology) \
    I(POANetwork) \
    I(Qtum) \
    I(XRP) \
    I(Solana) \
    I(Stellar) \
    I(Tezos) \
    I(Theta) \
    I(ThunderToken) \
    I(NEO) \
    I(TomoChain) \
    I(Tron) \
    I(VeChain) \
    I(Viacoin) \
    I(Wanchain) \
    I(Zcash) \
    I(Zcoin) \
    I(Zilliqa) \
    I(Zelcash) \
    I(Ravencoin) \
    I(Waves) \
    I(Terra) \
    I(Harmony) \
    I(Algorand) \
    I(Kusama) \
    I(Polkadot) \
    I(Filecoin) \
    I(Elrond) \
    I(BandChain) \
    I(SmartChainLegacy) \
    I(SmartChain) \
    I(Oasis) \
    I(Polygon) \
    I(THORChain) \
    I(Bluzelle) \
    I(Optimism) \
    I(Arbitrum) \
    I(ECOChain) \
    I(AvalancheCChain) \
    I(XDai) \
    I(Fantom) \
    I(CryptoOrg) \
    I(Celo) \
    I(Ronin) \

struct ValuePair {
    TWCoinType value;
    PyObject* pyvalue;
};

#define I(name) { TWCoinType##name, nullptr },
static ValuePair constants[] = {
    CONSTANTS(I)
};
#undef I

static PyTypeObject PyCoinTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.CoinType",      /* tp_name */
    sizeof(PyCoinTypeObject),   /* tp_basicsize */
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

PyObject* PyCoinType_FromTWCoinType(TWCoinType value) {
    ValuePair* value_pair = nullptr;
    for (auto& constant : constants) {
        if (constant.value == value) {
            value_pair = &constant;
            break;
        }
    }

    if (!value_pair) {
        PyErr_Format(PyExc_ValueError, "Invalid CoinType value: %d", value);
        return nullptr;
    }

    if (!value_pair->pyvalue) {
        auto* pyvalue = PyObject_New(PyCoinTypeObject, &PyCoinTypeType);
        *const_cast<TWCoinType*>(&pyvalue->value) = value;
        value_pair->pyvalue = (PyObject*)pyvalue;
    }

    Py_INCREF(value_pair->pyvalue);
    return value_pair->pyvalue;
}

static int PyCoinType_init(PyCoinTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

static PyObject* PyCoinType_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds) {
    int value = 0;
    if (!PyArg_ParseTuple(args, "|i", &value)) {
        return nullptr;
    }
    return PyCoinType_FromTWCoinType((TWCoinType)value);
}

static PyObject* PyCoinType_str(PyCoinTypeObject *self) {
    const char* str = nullptr;
    switch(self->value) {
#define I(name) \
        case TWCoinType##name: \
            str = #name; \
            break;
        CONSTANTS(I)
#undef I
      default:
        str = "Unknown";
        break;
    }
    return PyUnicode_FromString(str);
}

bool PyInit_CoinType(PyObject *module) {
    PyCoinTypeType.tp_new = PyCoinType_new;
    PyCoinTypeType.tp_init = (initproc)PyCoinType_init;
    PyCoinTypeType.tp_str = (reprfunc)PyCoinType_str;

    if (PyType_Ready(&PyCoinTypeType) < 0)
        return false;

    Py_INCREF(&PyCoinTypeType);
    if (PyModule_AddObject(module, "CoinType", (PyObject *) &PyCoinTypeType) < 0) {
        Py_DECREF(&PyCoinTypeType);
        return false;
    }

    PyObject* dict = PyCoinTypeType.tp_dict;
    (void)dict;

#define I(name) \
    PyDict_SetItemString(dict, #name, PyCoinType_FromTWCoinType(TWCoinType##name));
    CONSTANTS(I)
#undef I

    return true;
}