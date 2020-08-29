// Copyright 2020 SMS
// License(Apache-2.0)
// ด๓ะก

#ifndef CLEM_TYPE_SIZE_HPP_
#define CLEM_TYPE_SIZE_HPP_

#include <assert.h>
typedef unsigned short ushort;

struct Size
{
	ushort x;
	ushort y;

	Size()
			: Size(0, 0)
	{
	}

	Size(int x, int y)
			: x(x), y(y)
	{
		assert(x > 0 && y > 0);
	}

	ushort area() const
	{
		return x * y;
	}
};

#endif // CLEM_TYPE_SIZE_HPP_
