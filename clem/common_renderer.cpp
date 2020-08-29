// Copyright 2020 SMS
// License(Apache-2.0)
// 通用渲染器

#include "common_renderer.h"
#include "terminal.h"

using std::string;

CommonRenderer::CommonRenderer(const Rect& rect)
		: rect(rect)
{
}

void CommonRenderer::render()
{
	// 清空屏幕
	string line(rect.width, '.');
	for(ushort i = 0; i <= rect.height; i++)
	{
		Terminal::Cursor::moveTo(Vector(rect.x, rect.y + i));
		printf("%s", line.c_str());
	}

	// 绘制
	for(auto record : records)
	{
		Terminal::Cursor::moveTo({record.coord.x, record.coord.y});
		record.texture.put();
	}
	Terminal::Cursor::moveTo({0, 0});
	putchar('\n'); // 刷新缓冲区
	Terminal::Cursor::moveTo({0, 0});
}

void CommonRenderer::draw(const Texture& texture, const Vector& coord)
{
	records.push_back({texture, coord});
}

void CommonRenderer::clear()
{
	records.clear();
}
