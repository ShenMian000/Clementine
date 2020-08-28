// Copyright 2020 SMS
// License(Apache-2.0)
// ¼òÒ×äÖÈ¾Æ÷

#include "linux_renderer.h"
#include "cursor.h"

void LinuxRenderer::render()
{
  puts("\e[2j");
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
