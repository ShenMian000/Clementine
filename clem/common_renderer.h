// Copyright 2020 SMS
// License(Apache-2.0)
// Õ®”√‰÷»æ∆˜

#ifndef CLEM_COMMON_RENDERER_H_
#define CLEM_COMMON_RENDERER_H_

#include <vector>
#include "renderer.h"
#include "common.hpp"
#include "texture.hpp"

class CommonRenderer : public Renderer
{
public:
  CommonRenderer(const Size& size);

  void render() override;
  void draw(const Texture& texture, const Coord& coord) override;
  void clear() override;

private:
  Size size;
  struct pair
  {
    Texture texture;
    Coord   coord;
  };
  std::vector<pair> records;
};

#endif // CLEM_COMMON_RENDERER_H_
