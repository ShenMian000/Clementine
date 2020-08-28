// Copyright 2020 SMS
// License(Apache-2.0)
// ³¡¾°ÉãÏñ»ú

#include "camera.h"
#include <vector>
#include "renderer.h"
#include "game_object.h"

using std::vector;

Camera::Camera(Scene& scene)
		: scene(scene)
{
}

void Camera::render(Renderer& renderer, vector<GameObject*>& objs)
{
	for(auto obj : objs)
		renderer.draw(obj->getTexture(), obj->getPosition());
}
