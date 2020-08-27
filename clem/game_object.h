// Copyright 2020 SMS
// License(Apache-2.0)
// ”Œœ∑∂‘œÛ

#ifndef CLEM_GAME_OBJECT_H_
#define CLEM_GAME_OBJECT_H_

#include <vector>
#include "texture.hpp"

class Scene;
class Component;

class GameObject
{
public:
	GameObject(Scene& scene, const Texture& texture);

	void update();

	void addComponent(Component* com);
	void removeComponent(Component* com);

	void setPosition(const Coord& position);
	void setDirection(int direction);
	void setTexture(const Texture& texture);

	const Coord&   getPosition() const;
	ushort         getDirection() const;
	const Texture& getTexture() const;

private:
	Scene&  scene;

	Coord   position;
	ushort  direction;
	Texture texture;

	std::vector<Component*> components;
};

#endif // CLEM_GAME_OBJECT_H_
