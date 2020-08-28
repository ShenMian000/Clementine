// Copyright 2020 SMS
// License(Apache-2.0)
// ¼òÒ×äÖÈ¾Æ÷

#include "linux_renderer.h"
#include "terminal.h"

LinuxRenderer::LinuxRenderer(const Size& size)
		: size(size)
{
}

void LinuxRenderer::render()
{
	Terminal::Cursor::moveTo({0, 0});
	for(ushort y = 0; y < size.y; y++)
	{
		for(ushort x = 0; x < size.x; x++)
			printf(" ");
		if(y + 1 < size.y)
			printf("\n");
	}

	for(auto record : records)
	{
		Terminal::Cursor::moveTo(record.coord);
		record.texture.put();
	}
	Terminal::Cursor::moveTo({0, 0});
	putchar('\n'); // Ë¢ĞÂ»º³åÇø
}

void LinuxRenderer::draw(const Texture& texture, const Coord& coord)
{
	records.push_back({texture, coord});
}

void LinuxRenderer::clear()
{
	records.clear();
}
