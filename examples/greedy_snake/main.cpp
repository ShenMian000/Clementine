// Copyright 2020 SMS
// License(Apache-2.0)
// ̰����

#include <clem/clem.hpp>
#include "snake.hpp"

using Attr = Attribute;

int main()
{
	Terminal::Cursor::hide();                 // ���ع��
	auto winSize = Terminal::getWindowSize(); // ��ȡ�ն˴��ڴ�С

	Scene scene;        // ��������
	Snake snake(scene); // �� �� ���볡��

	snake.setPosition(Coord(winSize.x / 2, winSize.y / 2)); // �� �� ��λ�����õ���������

	scene.render();

	return 0;
}
