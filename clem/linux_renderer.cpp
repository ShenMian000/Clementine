// Copyright 2020 SMS
// License(Apache-2.0)
// ¼òÒ×äÖÈ¾Æ÷

#include "linux_renderer.h"
#include "cursor.h"

LinuxRenderer::LinuxRenderer(const Size& size)
		: size(size)
{
}

void LinuxRenderer::render()
{
  Cursor::moveTo({0, 0});
  for(ushort y = 0; y < size.y; y++)
  {
    for(ushort x = 0; x < size.x; x++)
      printf(" ");
    printf("\n");
  }

  for(auto record : records)
  {
		Cursor::moveTo(record.coord);
		record.texture.put();
	}
}

void LinuxRenderer::draw(const Texture& texture, const Coord& coord)
{
  records.push_back({texture, coord});
}

void LinuxRenderer::clear()
{
  records.clear();
}
