// Copyright 2020 SMS
// License(Apache-2.0)
// ³¡¾°

#include "scene.h"
#include "camera.h"

Scene::Scene(const Size& size)
		: size(size)
{
  addCamera(new Camera(*this));
}

void Scene::render()
{
  for(auto cam : cameras)
    cam->render();
}

void Scene::addCamera(Camera* cam)
{
  cameras.push_back(cam);
}
