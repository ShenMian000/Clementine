// Copyright 2020 SMS
// License(Apache-2.0)

#ifndef CLEM_EXAMPLE_SNAKE_HPP_
#define CLEM_EXAMPLE_SNAKE_HPP_

#include <vector>
#include <clem/clem.hpp>

using std::vector;
using Attr = Attribute;

class Snake : public GameObject
{
public:
	Snake(Scene& scene)
			: scene(scene), GameObject(scene, {'@', Attr(fore::green)})
	{
		addNewBody(); // 使 Snake 的默认长度为 2
	}

	~Snake()
	{
		for(auto body : bodys)
			delete body;
	}

	void update()
	{
		// 身体随头部移动
		bodys[0]->setPosition(getPosition());
		for(size_t i = 1; i < bodys.size(); i++)
			bodys[i]->setPosition(bodys[i + 1]->getPosition());
	}

	void isHit()
	{

	}

	// 添加一节新身体
	void addNewBody()
	{
		auto body = new GameObject(scene, {'#', Attr(fore::green)});
		// body->setPosition(); // bodys.back()
		bodys.push_back(body);
	}

private:
	Scene&              scene;
	vector<GameObject*> bodys;
};

#endif // CLEM_EXAMPLE_SNAKE_HPP_
