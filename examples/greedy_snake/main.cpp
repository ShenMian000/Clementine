// Copyright 2020 SMS
// License(Apache-2.0)
// ̰����

#include <clem/clem.hpp>
#include "snake.hpp"
#include <time.h>

#ifdef OS_WIN
#include <windows.h>
#define sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define sleep(ms) usleep(ms * 1000)
#endif

using Attr = Attribute;

const float snack_speed = 0.2;

int main()
{
	srand(time(nullptr));                                // ��ʼ�������������
	Terminal::Cursor::hide();                            // ���ع��
	auto          winSize = Terminal::getWindowSize();   // ��ȡ�ն˴��ڴ�С
	Scene         scene;                                 // ��������
	BasicPhysics  physics;                               // ���������������
	Snake         snake(scene);                          // ���߼��볡��
	physics.setVelocity({0, snack_speed});               // �����ߵĳ��ٶ�
	snake.addComponent(&physics);                        // Ϊ�������������
	snake.setPosition(Vector(winSize.x, winSize.y) / 2); // �����ߵ�λ�õ���������

	enum
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	KeyboardInput keyboard; // ������������
	keyboard.bind('W', UP);
	keyboard.bind('S', DOWN);
	keyboard.bind('A', LEFT);
	keyboard.bind('D', RIGHT);

	while(true)
	{
		for(auto event : keyboard.update())
			switch(event)
			{
			case UP:
				physics.setVelocity({0, snack_speed});
				break;

			case DOWN:
				physics.setVelocity({0, -snack_speed});
				break;

			case LEFT:
				physics.setVelocity({-snack_speed, 0});
				break;

			case RIGHT:
				physics.setVelocity({snack_speed, 0});
				break;
			}

		scene.update();
		scene.render();

		sleep(50);
	}

	(void)getchar();
	return 0;
}
