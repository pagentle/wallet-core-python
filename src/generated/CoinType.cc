// Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
// This file is part of Wallet-core-python.
//
// Wallet-core-python is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Wallet-core-python is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Wallet-core-python.  If not, see <https://www.gnu.org/licenses/>.
//
// NOTE: this is a GENERATED FILE, changes made here WILL BE LOST.

#include "generated/CoinType.h"

#include <algorithm>
#include <iterator>

#include "String.h"
#include "generated/Blockchain.h"
#include "generated/Curve.h"
#include "generated/HDVersion.h"
#include "generated/HRP.h"
#include "generated/PrivateKey.h"
#include "generated/PublicKey.h"
#include "generated/Purpose.h"

#define CONSTANTS(I)  \
  I(Aeternity)        \
  I(Aion)             \
  I(Binance)          \
  I(Bitcoin)          \
  I(BitcoinCash)      \
  I(BitcoinGold)      \
  I(Callisto)         \
  I(Cardano)          \
  I(Cosmos)           \
  I(Dash)             \
  I(Decred)           \
  I(DigiByte)         \
  I(Dogecoin)         \
  I(EOS)              \
  I(Ethereum)         \
  I(EthereumClassic)  \
  I(FIO)              \
  I(GoChain)          \
  I(Groestlcoin)      \
  I(ICON)             \
  I(IoTeX)            \
  I(Kava)             \
  I(Kin)              \
  I(Litecoin)         \
  I(Monacoin)         \
  I(Nebulas)          \
  I(NULS)             \
  I(Nano)             \
  I(NEAR)             \
  I(Nimiq)            \
  I(Ontology)         \
  I(POANetwork)       \
  I(Qtum)             \
  I(XRP)              \
  I(Solana)           \
  I(Stellar)          \
  I(Tezos)            \
  I(Theta)            \
  I(ThunderToken)     \
  I(NEO)              \
  I(TomoChain)        \
  I(Tron)             \
  I(VeChain)          \
  I(Viacoin)          \
  I(Wanchain)         \
  I(Zcash)            \
  I(Zcoin)            \
  I(Zilliqa)          \
  I(Zelcash)          \
  I(Ravencoin)        \
  I(Waves)            \
  I(Terra)            \
  I(Harmony)          \
  I(Algorand)         \
  I(Kusama)           \
  I(Polkadot)         \
  I(Filecoin)         \
  I(Elrond)           \
  I(BandChain)        \
  I(SmartChainLegacy) \
  I(SmartChain)       \
  I(Oasis)            \
  I(Polygon)          \
  I(THORChain)        \
  I(Bluzelle)         \
  I(Optimism)         \
  I(Arbitrum)         \
  I(ECOChain)         \
  I(AvalancheCChain)  \
  I(XDai)             \
  I(Fantom)           \
  I(CryptoOrg)        \
  I(Celo)             \
  I(Ronin)

static PyTypeObject PyCoinTypeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.CoinType",    /* tp_name */
    sizeof(PyCoinTypeObject), /* tp_basicsize */
    0,                        /* tp_itemsize */
    0,                        /* tp_dealloc */
    0,                        /* tp_print */
    0,                        /* tp_getattr */
    0,                        /* tp_setattr */
    0,                        /* tp_reserved */
    0,                        /* tp_repr */
    0,                        /* tp_as_number */
    0,                        /* tp_as_sequence */
    0,                        /* tp_as_mapping */
    0,                        /* tp_hash  */
    0,                        /* tp_call */
    0,                        /* tp_str */
    0,                        /* tp_getattro */
    0,                        /* tp_setattro */
    0,                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,       /* tp_flags */
    nullptr,                  /* tp_doc */
};

bool PyCoinType_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyCoinTypeType) != 0;
}

// Create PyCoinType from enum TWCoinType. It returns the same PyCoinType
// instance for the same enum TWCoinType value.
PyObject* PyCoinType_FromTWCoinType(TWCoinType value) {
  struct ValuePair {
    const TWCoinType value;
    PyObject* pyvalue;
  };
#define I(name) {TWCoinType##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

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

TWCoinType PyCoinType_GetTWCoinType(PyObject* object) {
  assert(PyCoinType_Check(object));
  return ((PyCoinTypeObject*)object)->value;
}

static int PyCoinType_init(PyCoinTypeObject* self,
                           PyObject* args,
                           PyObject* kwds) {
  return 0;
}

static PyObject* PyCoinType_new(PyTypeObject* subtype,
                                PyObject* args,
                                PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyCoinType_FromTWCoinType((TWCoinType)value);
}

static PyObject* PyCoinType_str(PyCoinTypeObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)          \
  case TWCoinType##name: \
    str = #name;         \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

// getter function for Blockchain
static const char PyCoinTypeBlockchain_doc[] =
    "enum TWBlockchain TWCoinTypeBlockchain(enum TWCoinType coin)";
static PyObject* PyCoinTypeBlockchain(PyCoinTypeObject* self, void*) {
  return PyBlockchain_FromTWBlockchain(TWCoinTypeBlockchain(self->value));
}

// getter function for Purpose
static const char PyCoinTypePurpose_doc[] =
    "enum TWPurpose TWCoinTypePurpose(enum TWCoinType coin)";
static PyObject* PyCoinTypePurpose(PyCoinTypeObject* self, void*) {
  return PyPurpose_FromTWPurpose(TWCoinTypePurpose(self->value));
}

// getter function for Curve
static const char PyCoinTypeCurve_doc[] =
    "enum TWCurve TWCoinTypeCurve(enum TWCoinType coin)";
static PyObject* PyCoinTypeCurve(PyCoinTypeObject* self, void*) {
  return PyCurve_FromTWCurve(TWCoinTypeCurve(self->value));
}

// getter function for XpubVersion
static const char PyCoinTypeXpubVersion_doc[] =
    "enum TWHDVersion TWCoinTypeXpubVersion(enum TWCoinType coin)";
static PyObject* PyCoinTypeXpubVersion(PyCoinTypeObject* self, void*) {
  return PyHDVersion_FromTWHDVersion(TWCoinTypeXpubVersion(self->value));
}

// getter function for XprvVersion
static const char PyCoinTypeXprvVersion_doc[] =
    "enum TWHDVersion TWCoinTypeXprvVersion(enum TWCoinType coin)";
static PyObject* PyCoinTypeXprvVersion(PyCoinTypeObject* self, void*) {
  return PyHDVersion_FromTWHDVersion(TWCoinTypeXprvVersion(self->value));
}

// getter function for HRP
static const char PyCoinTypeHRP_doc[] =
    "enum TWHRP TWCoinTypeHRP(enum TWCoinType coin)";
static PyObject* PyCoinTypeHRP(PyCoinTypeObject* self, void*) {
  return PyHRP_FromTWHRP(TWCoinTypeHRP(self->value));
}

// getter function for P2pkhPrefix
static const char PyCoinTypeP2pkhPrefix_doc[] =
    "uint8_t TWCoinTypeP2pkhPrefix(enum TWCoinType coin)";
static PyObject* PyCoinTypeP2pkhPrefix(PyCoinTypeObject* self, void*) {
  return PyLong_FromLong(TWCoinTypeP2pkhPrefix(self->value));
}

// getter function for P2shPrefix
static const char PyCoinTypeP2shPrefix_doc[] =
    "uint8_t TWCoinTypeP2shPrefix(enum TWCoinType coin)";
static PyObject* PyCoinTypeP2shPrefix(PyCoinTypeObject* self, void*) {
  return PyLong_FromLong(TWCoinTypeP2shPrefix(self->value));
}

// getter function for StaticPrefix
static const char PyCoinTypeStaticPrefix_doc[] =
    "uint8_t TWCoinTypeStaticPrefix(enum TWCoinType coin)";
static PyObject* PyCoinTypeStaticPrefix(PyCoinTypeObject* self, void*) {
  return PyLong_FromLong(TWCoinTypeStaticPrefix(self->value));
}

// getter function for Slip44Id
static const char PyCoinTypeSlip44Id_doc[] =
    "uint32_t TWCoinTypeSlip44Id(enum TWCoinType coin)";
static PyObject* PyCoinTypeSlip44Id(PyCoinTypeObject* self, void*) {
  return PyLong_FromLong(TWCoinTypeSlip44Id(self->value));
}

// method function for Validate
static const char PyCoinTypeValidate_doc[] =
    "bool TWCoinTypeValidate(enum TWCoinType coin, TWString* address)";
static PyObject* PyCoinTypeValidate(PyCoinTypeObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  bool result = TWCoinTypeValidate(self->value, arg0.get());
  return PyBool_FromLong(result);
}

// method function for DerivationPath
static const char PyCoinTypeDerivationPath_doc[] =
    "TWString* TWCoinTypeDerivationPath(enum TWCoinType coin)";
static PyObject* PyCoinTypeDerivationPath(PyCoinTypeObject* self,
                                          PyObject* const* args,
                                          Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWStringPtr result = TWCoinTypeDerivationPath(self->value);
  return PyUnicode_FromTWString(result);
}

// method function for DeriveAddress
static const char PyCoinTypeDeriveAddress_doc[] =
    "TWString* TWCoinTypeDeriveAddress(enum TWCoinType coin, struct "
    "TWPrivateKey* privateKey)";
static PyObject* PyCoinTypeDeriveAddress(PyCoinTypeObject* self,
                                         PyObject* const* args,
                                         Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyPrivateKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PrivateKey");
    return nullptr;
  }
  auto arg0 = PyPrivateKey_GetTWPrivateKey(args[0]);

  TWStringPtr result = TWCoinTypeDeriveAddress(self->value, arg0);
  return PyUnicode_FromTWString(result);
}

// method function for DeriveAddressFromPublicKey
static const char PyCoinTypeDeriveAddressFromPublicKey_doc[] =
    "TWString* TWCoinTypeDeriveAddressFromPublicKey(enum TWCoinType coin, "
    "struct TWPublicKey* publicKey)";
static PyObject* PyCoinTypeDeriveAddressFromPublicKey(PyCoinTypeObject* self,
                                                      PyObject* const* args,
                                                      Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyPublicKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PublicKey");
    return nullptr;
  }
  auto arg0 = PyPublicKey_GetTWPublicKey(args[0]);

  TWStringPtr result = TWCoinTypeDeriveAddressFromPublicKey(self->value, arg0);
  return PyUnicode_FromTWString(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"blockchain", (getter)PyCoinTypeBlockchain, nullptr,
     PyCoinTypeBlockchain_doc},
    {"purpose", (getter)PyCoinTypePurpose, nullptr, PyCoinTypePurpose_doc},
    {"curve", (getter)PyCoinTypeCurve, nullptr, PyCoinTypeCurve_doc},
    {"xpub_version", (getter)PyCoinTypeXpubVersion, nullptr,
     PyCoinTypeXpubVersion_doc},
    {"xprv_version", (getter)PyCoinTypeXprvVersion, nullptr,
     PyCoinTypeXprvVersion_doc},
    {"hrp", (getter)PyCoinTypeHRP, nullptr, PyCoinTypeHRP_doc},
    {"p2pkh_prefix", (getter)PyCoinTypeP2pkhPrefix, nullptr,
     PyCoinTypeP2pkhPrefix_doc},
    {"p2sh_prefix", (getter)PyCoinTypeP2shPrefix, nullptr,
     PyCoinTypeP2shPrefix_doc},
    {"static_prefix", (getter)PyCoinTypeStaticPrefix, nullptr,
     PyCoinTypeStaticPrefix_doc},
    {"slip44_id", (getter)PyCoinTypeSlip44Id, nullptr, PyCoinTypeSlip44Id_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"validate", (PyCFunction)PyCoinTypeValidate, METH_FASTCALL,
     PyCoinTypeValidate_doc},
    {"derivation_path", (PyCFunction)PyCoinTypeDerivationPath, METH_FASTCALL,
     PyCoinTypeDerivationPath_doc},
    {"derive_address", (PyCFunction)PyCoinTypeDeriveAddress, METH_FASTCALL,
     PyCoinTypeDeriveAddress_doc},
    {"derive_address_from_public_key",
     (PyCFunction)PyCoinTypeDeriveAddressFromPublicKey, METH_FASTCALL,
     PyCoinTypeDeriveAddressFromPublicKey_doc},
    {}};

bool PyInit_CoinType(PyObject* module) {
  PyCoinTypeType.tp_new = PyCoinType_new;
  PyCoinTypeType.tp_init = (initproc)PyCoinType_init;
  PyCoinTypeType.tp_str = (reprfunc)PyCoinType_str;
  PyCoinTypeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyCoinTypeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyCoinTypeType) < 0)
    return false;

  Py_INCREF(&PyCoinTypeType);
  if (PyModule_AddObject(module, "CoinType", (PyObject*)&PyCoinTypeType) < 0) {
    Py_DECREF(&PyCoinTypeType);
    return false;
  }

  PyObject* dict = PyCoinTypeType.tp_dict;
  (void)dict;

#define I(name)                     \
  PyDict_SetItemString(dict, #name, \
                       PyCoinType_FromTWCoinType(TWCoinType##name));
  CONSTANTS(I)
#undef I

  return true;
}