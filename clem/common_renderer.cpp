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
	string line(rect.size().x, ' ');
	for(ushort y = 0; y < rect.size().y - 1; y++)
	{
		Terminal::Cursor::moveTo({rect.leftTop.x, rect.leftTop.y + y});
		puts(line.c_str());
	}
	Terminal::Cursor::moveTo({rect.leftTop.x, rect.rightBottom.y});
	printf("%s", line.c_str());

	// 绘制
	auto size = Terminal::getWindowSize();
	for(auto record : records)
	{
		Terminal::Cursor::moveTo({record.coord.x, size.y - record.coord.y});
		record.texture.put();
	}
	Terminal::Cursor::moveTo({0, 0});
	putchar('\n'); // 刷新缓冲区
}

void CommonRenderer::draw(const Texture& texture, const Coord& coord)
{
	records.push_back({texture, coord});
}

void CommonRenderer::clear()
{
	records.clear();
}
