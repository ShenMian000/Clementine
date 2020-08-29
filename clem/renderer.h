// Copyright 2020 SMS
// License(Apache-2.0)
// äÖÈ¾Æ÷

#ifndef CLEM_RENDERER_H_
#define CLEM_RENDERER_H_

class Vector;
class Texture;

class Renderer
{
public:
  virtual void render() = 0;
	virtual void draw(const Texture&, const Vector&) = 0;
  virtual void clear() = 0;
};

#endif // CLEM_RENDERER_H_
