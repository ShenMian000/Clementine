// Copyright 2020 SMS
// License(Apache-2.0)
// ¾ØÐÎ

#ifndef CLEM_TYPE_RECT_HPP_
#define CLEM_TYPE_RECT_HPP_

#include "coord.hpp"
#include "size.hpp"

struct Rect
{
	Coord leftTop;
	Coord rightBottom;

	Size size()
	{
		return Size(rightBottom.x - leftTop.x, rightBottom.y - leftTop.y);
	}

	Rect(const Coord& leftTop, const Size& size)
			: leftTop(leftTop), rightBottom(leftTop.x + size.x, leftTop.y + size.y)
	{
	}

	Rect(const Coord& leftTop, const Coord& rightBottom)
			: leftTop(leftTop), rightBottom(rightBottom)
	{
	}
};

#endif // CLEM_TYPE_RECT_HPP_
