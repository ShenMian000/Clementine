// Copyright 2020 SMS
// License(Apache-2.0)
// ³¡¾°

#include "scene.h"
#include "terminal.h"
#include "game_object.h"
#include "camera.h"

#include "linux_renderer.h"

Scene::Scene()
		: Scene(Terminal::getWinSize())
{
}

Scene::Scene(const Size& size)
		: size(size), renderer(new LinuxRenderer())
{
  addCamera(new Camera(*this, size));
}

void Scene::update()
{
  for(auto obj : objects)
    obj->update();
}

void Scene::render()
{
  for(auto cam : cameras)
    cam->render(*renderer, objects);
}

void Scene::addObject(GameObject* obj)
{
  objects.push_back(obj);
}


void Scene::addCamera(Camera* cam)
{
  cameras.push_back(cam);
}
