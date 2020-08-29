// Copyright 2020 SMS
// License(Apache-2.0)
// ¾ØÐÎ

#ifndef CLEM_TYPE_RECT_HPP_
#define CLEM_TYPE_RECT_HPP_

struct Size;
struct Vector;

typedef unsigned short ushort;

struct Rect
{
	float x;
	float y;
	float width;
	float height;

	Rect();
	Rect(const Vector& vec, const Size& size);
	Rect(ushort x, ushort y, ushort width, ushort height);

	Size size() const;
};

#endif // CLEM_TYPE_RECT_HPP_
