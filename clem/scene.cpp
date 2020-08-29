// Copyright 2020 SMS
// License(Apache-2.0)
// ³¡¾°

#include "scene.h"
#include "terminal.h"
#include "game_object.h"
#include "camera.h"
#include "common_renderer.h"

using std::vector;

Scene::Scene()
		: Scene(Rect(Vector(0, Terminal::getWindowSize().y), Terminal::getWindowSize()))
{
}

Scene::Scene(const Rect& rect)
		: rect(rect), renderer(new CommonRenderer(rect))
{
  addCamera(new Camera(*this, rect));
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
  renderer->clear();
}

void Scene::addObject(GameObject* obj)
{
  objects.push_back(obj);
}


void Scene::addCamera(Camera* cam)
{
  cameras.push_back(cam);
}

const vector<Camera*>& Scene::getCameras() const
{
	return cameras;
}
