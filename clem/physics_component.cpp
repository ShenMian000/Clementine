// Copyright 2020 SMS
// License(Apache-2.0)
// 物理引擎组件

#include "physics_component.h"

void PhysicsComponent::setVelocity(const Vector& vec)
{
	velocity = vec;
}

const Vector& PhysicsComponent::getVelocity() const
{
	return velocity;
}

void PhysicsComponent::setAccelerate(const Vector& vec)
{
	accelerate = vec;
}

const Vector& PhysicsComponent::getAccelerate() const
{
	return accelerate;
}