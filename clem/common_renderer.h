// Copyright 2020 SMS
// License(Apache-2.0)
// Õ®”√‰÷»æ∆˜

#ifndef CLEM_COMMON_RENDERER_H_
#define CLEM_COMMON_RENDERER_H_

#include <vector>
#include <clem/renderer.h>
#include "common.hpp"
#include "texture.hpp"

class CommonRenderer : public Renderer
{
public:
	CommonRenderer(const Rect& rect);

  void render() override;
	void draw(const Texture& texture, const Vector& coord) override;
  void clear() override;

private:
  Rect rect;
  struct pair
  {
    Texture texture;
    Vector  coord;
  };
  std::vector<pair> records;
};

#endif // CLEM_COMMON_RENDERER_H_
