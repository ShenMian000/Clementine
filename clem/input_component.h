// Copyright 2020 SMS
// License(Apache-2.0)
// �������

#ifndef CLEM_INPUT_COMPONENT_H_
#define CLEM_INPUT_COMPONENT_H_

#include <clem/common.hpp>
#include <vector>
#include "component.h"

class InputComponent : public Component
{
public:
	void bind(ushort id, ushort event);
	void setInterval(ushort ms); // ���� �ظ���Ӧ����������ͬ������ʱ�� (��λ: ms)

protected:
	std::vector<ushort> codes;
	ushort              interval = 150;
};

#endif // CLEM_INPUT_COMPONENT_H_
