// Copyright 2020 SMS
// License(Apache-2.0)
// 控制台光标

#include "cursor.h"

void Cursor::moveTo(const Coord& coord)
{
	printf("\e[%u;%uH", (ushort)coord.y, (ushort)coord.x);
}

void Cursor::show()
{
	printf("\e[?25h");
}

void Cursor::hide()
{
	printf("\e[?25l");
}
