// Copyright 2020 SMS
// License(Apache-2.0)
// 通用渲染器

#include "common_renderer.h"
#include "terminal.h"

using std::string;

CommonRenderer::CommonRenderer(const Size& size)
		: size(size)
{
}

void CommonRenderer::render()
{
	// 清空屏幕
	Terminal::Cursor::moveTo({0, 0});
	string line(size.x, ' ');
	for(ushort y = 0; y < size.y - 1; y++)
		puts(line.c_str());
	printf("%s", line.c_str());

	// 绘制
	for(auto record : records)
	{
		Terminal::Cursor::moveTo(record.coord);
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
