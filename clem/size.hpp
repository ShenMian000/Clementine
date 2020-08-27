// Copyright 2020 SMS
// License(Apache-2.0)

#ifndef CLEM_SIZE_HPP_
#define CLEM_SIZE_HPP_

#include "common.hpp"

struct Size
{
	Size(ushort x = 0, ushort y = 0)
			: x(x), y(y)
	{
	}

	ushort x;
  ushort y;

  ushort area() const
  {
    return x * y;
  }
};

#endif // CLEM_SIZE_HPP_
