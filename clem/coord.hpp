// Copyright 2020 SMS
// License(Apache-2.0)

#ifndef CLEM_COORD_HPP_
#define CLEM_COORD_HPP_

#include <math.h>

struct Coord
{
	Coord(double x = 0, double y = 0)
			: x(x), y(y)
	{
	}

	// 返回两点间直线距离
	double distanceTo(const Coord& coord)
	{
		Coord dec = {fabs(x - coord.x), fabs(y - coord.y)};
		return sqrt(dec.x * dec.x + dec.y * dec.y);
	}

	double x;
	double y;
};

#endif // CLEM_COORD_HPP_
