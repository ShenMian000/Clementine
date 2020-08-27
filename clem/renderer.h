// Copyright 2020 SMS
// License(Apache-2.0)
// ��Ⱦ��

#ifndef CLEM_RENDERER_H_
#define CLEM_RENDERER_H_

class Coord;
class Texture;

class Renderer
{
public:
  virtual void render() = 0;
  virtual void draw() = 0;
  virtual void clear() = 0;
  virtual void erase() = 0;
};

#endif // CLEM_RENDERER_H_
