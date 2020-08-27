// Copyright 2020 SMS
// License(Apache-2.0)
// 输入组件

#ifndef CLEM_INPUT_COMPONENT_H_
#define CLEM_INPUT_COMPONENT_H_

#include <clem/common.hpp>
#include <vector>
#include "component.h"

class InputComponent : public Component
{
public:
	void bind(ushort id, ushort event);
	void setInterval(ushort ms); // 设置 重复响应持续按下相同按键的时间 (单位: ms)

protected:
	std::vector<ushort> codes;
	ushort              interval = 150;
};

#endif // CLEM_INPUT_COMPONENT_H_
