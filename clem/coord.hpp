// Copyright 2020 SMS
// License(Apache-2.0)

#ifndef CLEM_COORD_HPP_
#define CLEM_COORD_HPP_

#include <math.h>

struct Coord
{
	Coord(float x = 0, float y = 0)
			: x(x), y(y)
	{
	}

	// 返回两点间直线距离
	float distanceTo(const Coord& coord)
	{
		auto sumX = fabs(x - coord.x);
		auto sumY = fabs(y - coord.y);
		return sqrt(sumX * sumX + sumY * sumY);
	}

	float x;
	float y;
};

#endif // CLEM_COORD_HPP_
