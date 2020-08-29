// Copyright 2020 SMS
// License(Apache-2.0)
// �����������

#include "basic_physics.h"

void BasicPhysics::update(GameObject& obj)
{
	velocity += accelerate;

	obj.setPosition(obj.getPosition() + velocity);
}
