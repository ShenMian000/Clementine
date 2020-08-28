// Copyright 2020 SMS
// License(Apache-2.0)
// ̰����

#include <clem/clem.hpp>
#include "snake.hpp"
#include <unistd.h>

using Attr = Attribute;

int main()
{
	Terminal::Cursor::hide();                 // ���ع��
	auto winSize = Terminal::getWindowSize(); // ��ȡ�ն˴��ڴ�С

	Scene scene;        // ��������
	Snake snake(scene); // �� �� ���볡��

	snake.setPosition(Coord(winSize.x / 2, winSize.y / 2)); // �� �� ��λ�����õ���������

	while(true)
	{
		scene.render();
		
		usleep(16000);
	}

	getchar();
	return 0;
}
