// Copyright 2020 SMS
// License(Apache-2.0)
// 贪吃蛇

#include <clem/clem.hpp>
#include "snake.hpp"

using Attr = Attribute;

int main()
{
	Terminal::Cursor::hide();                 // 隐藏光标
	auto winSize = Terminal::getWindowSize(); // 获取终端窗口大小

	Scene scene;        // 创建场景
	Snake snake(scene); // 将 蛇 加入场景

	snake.setPosition(Coord(winSize.x / 2, winSize.y / 2)); // 将 蛇 的位置设置到场景中央

	KeyboardInput keyboard;
	keyboard.bind('W', 0);
	keyboard.bind('S', 1);
	keyboard.bind('A', 2);
	keyboard.bind('D', 3);

	while(true)
	{
		for(auto event : keyboard.update())
		{
			auto pos = snake.getPosition();
			switch(event)
			{
			case 0:
				pos.y--;
				break;

			case 1:
				pos.y++;
				break;

			case 2:
				pos.x--;
				break;

			case 3:
				pos.x++;
				break;
			}
			snake.setPosition(pos);
		}

		scene.render();

		#ifdef LINUX
		#include <unistd.h>
		usleep(100000);
		#endif
		#ifdef OS_WIN
		Sleep(100);
		#endif
	}

	getchar();
	return 0;
}
