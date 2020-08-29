// Copyright 2020 SMS
// License(Apache-2.0)
// ͨ����Ⱦ��

#include "common_renderer.h"
#include "terminal.h"

using std::string;

CommonRenderer::CommonRenderer(const Rect& rect)
		: rect(rect)
{
}

void CommonRenderer::render()
{
	// �����Ļ
	string line(rect.size().x, '.');
	for(ushort y = rect.y; y <= rect.height; y++)
	{
		Terminal::Cursor::moveTo(Vector(rect.x, y));
		printf("%s", line.c_str());
	}

	// ����
	for(auto record : records)
	{
		Terminal::Cursor::moveTo({record.coord.x, rect.height - record.coord.y});
		record.texture.put();
	}
	Terminal::Cursor::moveTo({0, 0});
	putchar('\n'); // ˢ�»�����
}

void CommonRenderer::draw(const Texture& texture, const Vector& coord)
{
	records.push_back({texture, coord});
}

void CommonRenderer::clear()
{
	records.clear();
}
