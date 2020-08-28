// Copyright 2020 SMS
// License(Apache-2.0)

#ifndef CLEM_COMMON_HPP_
#define CLEM_COMMON_HPP_

typedef unsigned short ushort;

#include <stdio.h>
#include <assert.h>

#include "os.hpp"

#ifdef OS_WIN
  #define hStdOut GetStdHandle(STD_OUTPUT_HANDLE)
#endif

#include "coord.hpp"
#include "size.hpp"

#endif // CLEM_COMMON_HPP_
