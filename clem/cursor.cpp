// Copyright 2020 SMS
// License(Apache-2.0)
// ����̨���

#include "cursor.h"

void Cursor::moveTo(const Coord& coord)
{
	printf("\e[%u;%uH", (ushort)coord.x, (ushort)coord.y);
}
