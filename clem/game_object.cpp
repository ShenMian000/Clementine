// Copyright 2020 SMS
// License(Apache-2.0)
// ÓÎÏ·¶ÔÏó

#include "game_object.h"
#include "scene.h"
#include "component.h"
#include "physics_component.h"

GameObject::GameObject(Scene& scene, const Texture& texture)
		: scene(scene), texture(texture)
{
	scene.addObject(this);
}

void GameObject::update()
{
	if(physics != nullptr)
		physics->update(*this);

	for(const auto& com : components)
		com->update(*this);
}

void GameObject::setPhysics(PhysicsComponent* physics)
{
	this->physics = physics;
}

PhysicsComponent& GameObject::getPhysics() const
{
	return *physics;
}

void GameObject::addComponent(Component* com)
{
	components.push_back(com);
}

void GameObject::removeComponent(Component* com)
{
	// TODO
}

void GameObject::setPosition(const Vector& position)
{
	this->position = position;
}

void GameObject::setTexture(const Texture& texture)
{
	this->texture = texture;
}

const Vector& GameObject::getPosition() const
{
	return position;
}

const Texture& GameObject::getTexture() const
{
	return texture;
}

Scene& GameObject::getScene() const
{
	return scene;
}
