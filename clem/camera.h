// Copyright 2020 SMS
// License(Apache-2.0)
// ³¡¾°ÉãÏñ»ú

#ifndef CLEM_CAMERA_H_
#define CLEM_CAMERA_H_

#include <clem/common.hpp>

class Scene;

class Camera
{
public:
  Camera(Scene&);

  void render();

private:
	Size   size;
	Scene& scene;
  ushort depth;
};

#endif // CLEM_CAMERA_H_
