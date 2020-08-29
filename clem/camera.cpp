// Copyright 2020 SMS
// License(Apache-2.0)
// ³¡¾°ÉãÏñ»ú

#include "camera.h"
#include <vector>
#include "renderer.h"
#include "game_object.h"

using std::vector;

Camera::Camera(Scene& scene, const Rect& rect)
		: scene(scene), rect(rect), depth(0)
{
}

void Camera::render(Renderer& renderer, const vector<GameObject*>& objs)
{
	for(auto obj : objs)
		if(inSight(*obj))
			renderer.draw(obj->getTexture(), obj->getPosition());
	renderer.render();
}

bool Camera::inSight(const GameObject& obj) const
{
	auto pos = obj.getPosition();
	if(rect.x <= pos.x && pos.x <= rect.width &&
		 rect.y <= pos.y && pos.y <= rect.height)
		return true;
	else
		return false;
}
