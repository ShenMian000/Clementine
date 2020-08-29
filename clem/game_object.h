// Copyright 2020 SMS
// License(Apache-2.0)
// ”Œœ∑∂‘œÛ

#ifndef CLEM_GAME_OBJECT_H_
#define CLEM_GAME_OBJECT_H_

#include <vector>
#include "texture.hpp"

class Scene;
class Component;
class PhysicsComponent;

class GameObject
{
public:
	GameObject(Scene& scene, const Texture& texture);

	virtual void update();

	void              setPhysics(PhysicsComponent* physics);
	PhysicsComponent& getPhysics() const;

	void addComponent(Component* com);
	void removeComponent(Component* com);

	void setPosition(const Vector& position);
	void setTexture(const Texture& texture);

	const Vector&  getPosition() const;
	const Texture& getTexture() const;

	Scene& getScene() const;

private:
	Scene&  scene;

	PhysicsComponent* physics;

	Vector  position;
	Texture texture;

	std::vector<Component*> components;
};

#endif // CLEM_GAME_OBJECT_H_
