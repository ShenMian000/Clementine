// Copyright 2020 SMS
// License(Apache-2.0)
// 贪吃蛇

#include <clem/clem.hpp>
#include "snake.hpp"

using Attr = Attribute;

int main()
{
	Scene scene;        // 创建场景, 默认大小和终端窗口一致
	Snake snake(scene); // 将蛇加入场景
	
	

	scene.render();

	return 0;
}
