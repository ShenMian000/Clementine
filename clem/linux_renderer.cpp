// Copyright 2020 SMS
// License(Apache-2.0)
// ������Ⱦ��

#include "linux_renderer.h"
#include "cursor.h"

void LinuxRenderer::render()
{
}

void LinuxRenderer::draw(const Texture& texture, const Coord& coord)
{
  Cursor::moveTo(coord);
  texture.put();
}
