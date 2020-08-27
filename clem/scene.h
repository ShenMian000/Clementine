// Copyright 2020 SMS
// License(Apache-2.0)
// ³¡¾°

#ifndef CLEM_SCENE_H_
#define CLEM_SCENE_H_

#include <clem/common.hpp>
#include <vector>
#include "renderer.h"

class Camera;

class Scene
{
public:
	Scene(const Size& size);

	void render();

	void addCamera(Camera* cam);
	void removeCamera(Camera* cam);

private:
	Size                 size;
	Renderer*            renderer;
	std::vector<Camera*> cameras;
};

#endif // CLEM_SCENE_H_
