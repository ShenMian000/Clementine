// Copyright 2020 SMS
// License(Apache-2.0)
// �������

#ifndef CLEM_INPUT_COMPONENT_H_
#define CLEM_INPUT_COMPONENT_H_

#include <clem/common.hpp>
#include <map>
#include <vector>

class Input
{
public:
	virtual const std::vector<ushort>& update() = 0;

	void bind(ushort code, ushort event);

	void   setInterval(ushort ms);
	ushort getInterval() const;

protected:
	std::map<ushort, ushort> index;
	std::vector<ushort>      events;
	ushort                   interval = 150; // �ظ���Ӧ����������ͬ������ʱ��
};

#endif // CLEM_INPUT_COMPONENT_H_
