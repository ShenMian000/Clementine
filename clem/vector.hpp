// Copyright 2020 SMS
// License(Apache-2.0)
// œÚ¡ø

#ifndef CLEM_VECTOR_HPP_
#define CLEM_VECTOR_HPP_

#include "common.hpp"
#include "coord.hpp"

struct Vector
{
	Vector(Coord start, Coord end)
			: start(start), end(end)
	{
	}
	
	Vector(ushort direction, double distance)
			: direction(direction), distance(distance)
	{
		decomposition();
	}

	void decomposition()
	{
		if((0 <= direction && direction <= 89) ||
			 (180 <= direction && direction <= 359))
		{
			dec.x = sin(direction) * distance;
			dec.y = cos(direction) * distance;
		}
		else
		{
			dec.x = cos(direction) * distance;
			dec.y = sin(direction) * distance;
		}
	}

	Coord  start;
	Coord  end;

	Coord  dec;
	ushort direction;
	double distance;
};

#endif // CLEM_VECTOR_HPP_
