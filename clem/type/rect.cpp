// Copyright 2020 SMS
// License(Apache-2.0)
// ¾ØÐÎ

#include "rect.h"
#include "size.hpp"
#include "vector.h"

Rect::Rect()
		: Rect(0, 0, 0, 0)
{
}

Rect::Rect(const Vector& vec, const Size& size)
		: Rect(vec.x, vec.y, size.x, size.y)
{
}

Rect::Rect(ushort x, ushort y, ushort width, ushort height)
		: x(x), y(y), width(width), height(height)
{
}

Size Rect::size() const
{
	return Size(width - x, height - y);
}
