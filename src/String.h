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

#pragma once

#include <memory>

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <TrustWalletCore/TWString.h>

// std::unique_ptr for holding TWString*
class TWStringPtr
    : public std::unique_ptr<TWString, decltype(&TWStringDelete)> {
 public:
  TWStringPtr() : TWStringPtr(nullptr) {}
  TWStringPtr(TWString* p)
      : std::unique_ptr<TWString, decltype(&TWStringDelete)>(p,
                                                             &TWStringDelete) {}
};

// Create a PyUnicode object from a TWString.
PyObject* PyUnicode_FromTWString(const TWStringPtr& str);

// Get content of a PyUnicode in a new allocated TWString.
TWStringPtr PyUnicode_GetTWString(PyObject* object);