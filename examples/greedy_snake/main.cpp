// Copyright 2020 SMS
// License(Apache-2.0)
// ̰����

#include <clem/clem.hpp>
#include "snake.hpp"
#include <unistd.h>

using Attr = Attribute;

int main()
{
	Cursor::hide();     // ���ع��
	Scene scene;        // ��������
	Snake snake(scene); // �� �� ���볡��

	auto winSize = Terminal::getWinSize();             // ��ȡ�ն˴��ڴ�С
	snake.setPosition({winSize.x / 2, winSize.y / 2}); // �� �� ��λ�����õ���������

	while(true)
	{
		auto pos = snake.getPosition();
		pos.x += 0.1;
		snake.setPosition(pos);

		scene.render();

		sleep(1);
	}

	getchar();
	return 0;
}
