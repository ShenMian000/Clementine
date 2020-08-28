// Copyright 2020 SMS
// License(Apache-2.0)
// LinuxäÖÈ¾Æ÷

#ifndef CLEM_LINUX_RENDERER_H_
#define CLEM_LINUX_RENDERER_H_

#include <vector>
#include "renderer.h"
#include "common.hpp"
#include "texture.hpp"

class LinuxRenderer : public Renderer
{
public:
  void render() override;
  void draw(const Texture& texture, const Coord& coord) override;

private:
  struct pair
  {
    Texture texture;
    Coord   coord;
  };
  std::vector<pair> records;
};

#endif // CLEM_LINUX_RENDERER_H_
