// Copyright 2020 SMS
// License(Apache-2.0)
// 基础引擎组件

#ifndef CLEM_BASIC_PHYSICS_H_
#define CLEM_BASIC_PHYSICS_H_

#include "physics_component.h"

class BasicPhysics : public PhysicsComponent
{
public:
	void update(GameObject& obj) override;
};

#endif // CLEM_BASIC_PHYSICS_H_
