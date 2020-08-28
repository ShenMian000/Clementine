// Copyright 2020 SMS
// License(Apache-2.0)
// 物理引擎组件

#ifndef CLEM_PHYSICS_COMPONENT_H_
#define CLEM_PHYSICS_COMPONENT_H_

#include "component.h"
#include "common.hpp"

class PhysicsComponent : public Component
{
public:
  virtual void update(GameObject&) override = 0;
};

#endif // CLEM_PHYSICS_COMPONENT_H_
