// Copyright 2020 SMS
// License(Apache-2.0)
// ������Ⱦ��

#include "linux_renderer.h"
#include "terminal.h"

using std::string;

LinuxRenderer::LinuxRenderer(const Size& size)
		: size(size)
{
}

void LinuxRenderer::render()
{
	// �����Ļ
	Terminal::Cursor::moveTo({0, 0});
	string line(size.x, ' ');
	for(ushort y = 0; y < size.y; y++)
	{
		printf(line.c_str());
		if(y + 1 < size.y)
			printf("\n");
	}

	// ����
	for(auto record : records)
	{
		Terminal::Cursor::moveTo(record.coord);
		record.texture.put();
	}
	Terminal::Cursor::moveTo({0, 0});
	putchar('\n'); // ˢ�»�����
}

void LinuxRenderer::draw(const Texture& texture, const Coord& coord)
{
	records.push_back({texture, coord});
}

void LinuxRenderer::clear()
{
	records.clear();
}
