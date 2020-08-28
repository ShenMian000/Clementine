// Copyright 2020 SMS
// License(Apache-2.0)
// ³¡¾°

#ifndef CLEM_SCENE_H_
#define CLEM_SCENE_H_

#include <clem/common.hpp>
#include <vector>
#include "renderer.h"

class Camera;
class GameObject;

class Scene
{
public:
	Scene();
	Scene(const Size& size);

	void update();
	void render();

	void addObject(GameObject*);
	void removeObject(GameObject*);

	void                        addCamera(Camera* cam);
	void                        removeCamera(Camera* cam);
	const std::vector<Camera*>& getCameras() const;

private:
	Size                     size;
	Renderer*                renderer;
	std::vector<Camera*>     cameras;
	std::vector<GameObject*> objects;
};

#endif // CLEM_SCENE_H_
