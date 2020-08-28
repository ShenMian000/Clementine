// Copyright 2020 SMS
// License(Apache-2.0)
// ̰����

#include <clem/clem.hpp>
#include "snake.hpp"

using Attr = Attribute;

int main()
{
	Cursor::hide();     // ���ع��
	Scene scene;        // ��������, Ĭ�ϴ�С���ն˴��ڴ�Сһ��
	Snake snake(scene); // �� �� ���볡��

	auto winSize = Terminal::getWinSize();             // ��ȡ�ն˴��ڴ�С
	snake.setPosition({winSize.x / 2, winSize.y / 2}); // �� �� ��λ�����õ���������

	scene.render();

	getchar();
	return 0;
}
