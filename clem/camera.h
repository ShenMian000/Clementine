// Copyright 2020 SMS
// License(Apache-2.0)
// ³¡¾°ÉãÏñ»ú

#ifndef CLEM_CAMERA_H_
#define CLEM_CAMERA_H_

#include <clem/common.hpp>
#include <vector>

class Scene;
class Renderer;
class GameObject;

class Camera
{
public:
	Camera(Scene& scene, const Rect& rect);

  void render(Renderer& renderer, const std::vector<GameObject*>& objs);

	bool inSight(const GameObject& obj) const;

private:
	Rect   rect;
	Scene& scene;
  ushort depth;
};

#endif // CLEM_CAMERA_H_
