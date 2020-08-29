// Copyright 2020 SMS
// License(Apache-2.0)
// зјБъ

#ifndef CLEM_TYPE_COORD_HPP_
#define CLEM_TYPE_COORD_HPP_

struct Coord
{
	float x;
	float y;

	Coord operator/(const Coord& coord)
	{
		return Coord(coord.x / 2, coord.y / 2);
	}

	Coord()
			: Coord(0, 0)
	{
	}

	Coord(float x, float y)
			: x(x), y(y)
	{
	}
};

#endif // CLEM_TYPE_COORD_HPP_
