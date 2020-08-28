// Copyright 2020 SMS
// License(Apache-2.0)
// 贪吃蛇

#include <clem/clem.hpp>
#include "snake.hpp"
#include <unistd.h>

using Attr = Attribute;

int main()
{
	Cursor::hide();     // 隐藏光标
	Scene scene;        // 创建场景
	Snake snake(scene); // 将 蛇 加入场景

	auto winSize = Terminal::getWinSize();             // 获取终端窗口大小
	snake.setPosition({winSize.x / 2, winSize.y / 2}); // 将 蛇 的位置设置到场景中央

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
