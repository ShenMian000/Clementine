// Copyright 2020 SMS
// License(Apache-2.0)
// 游戏对象

#include "game_object.h"
#include "scene.h"
#include "component.h"
#include "vector.hpp"

GameObject::GameObject(Scene& scene, const Texture& texture)
		: scene(scene), texture(texture)
{
	scene.addObject(this);
}

void GameObject::update()
{
	for(const auto& com : components)
		com->update(*this);
}

void GameObject::addComponent(Component* com)
{
	components.push_back(com);
}

void GameObject::removeComponent(Component* com)
{
	// TODO
}

void GameObject::setPosition(const Coord& position)
{
	this->position = position;
}

void GameObject::setDirection(int direction)
{
	// 将方向调整至 0-359 之间
	direction %= 360;
	if(direction < 0)
		direction = 360 + direction;

	this->direction = direction;
}

void GameObject::setTexture(const Texture& texture)
{
	this->texture = texture;
}

const Coord& GameObject::getPosition() const
{
	return position;
}

ushort GameObject::getDirection() const
{
	return direction;
}

const Texture& GameObject::getTexture() const
{
	return texture;
}
