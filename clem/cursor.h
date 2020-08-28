// Copyright 2020 SMS
// License(Apache-2.0)
// 控制台光标

#ifndef CLEM_CURSOR_H_
#define CLEM_CURSOR_H_

#include <clem/common.hpp>

class Cursor
{
public:
	static void moveTo(const Coord& coord);

	static void moveUp(ushort);
	static void moveDown(ushort);
	static void moveRight(ushort);
	static void moveLeft(ushort);

	static void show();
	static void hide();
};

#endif // CLEM_CURSOR_H_
