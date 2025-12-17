//===-- C standard library header stdint.h --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_STDINT_H
#define LLVM_LIBC_STDINT_H

#ifndef __clang__
#include_next <stdint.h>
#else
#include "llvm-libc-macros/stdint-macros.h"
#endif

#endif // LLVM_LIBC_STDINT_H
