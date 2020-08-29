// Copyright 2020 SMS
// License(Apache-2.0)
// 物理引擎组件

#ifndef CLEM_PHYSICS_COMPONENT_H_
#define CLEM_PHYSICS_COMPONENT_H_

#include "component.h"
#include "common.hpp"
#include <clem/game_object.h>

class PhysicsComponent : public Component
{
public:
	virtual void update(GameObject&) override;

	void          setVelocity(const Vector& vec);
	const Vector& getVelocity() const;

	void          setAccelerate(const Vector& vec);
	const Vector& getAccelerate() const;

protected:
	Vector velocity;
	Vector accelerate;
};

#endif // CLEM_PHYSICS_COMPONENT_H_
