// Copyright 2020 SMS
// License(Apache-2.0)
// ̰����

#include <clem/clem.hpp>
#include "snake.hpp"

using Attr = Attribute;

int main()
{
	Scene scene;        // ��������, Ĭ�ϴ�С���ն˴���һ��
	Snake snake(scene); // ���߼��볡��
	
	

	scene.render();

	return 0;
}
