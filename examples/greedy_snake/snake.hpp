// Copyright 2020 SMS
// License(Apache-2.0)

#ifndef CLEM_EXAMPLE_SNAKE_HPP_
#define CLEM_EXAMPLE_SNAKE_HPP_

#include <vector>
#include "game_object.h"

class Snake : public GameObject
{
public:
	Snake(Scene& scene)
			: GameObject(scene, {'@', Attribute(Fore::green)})
	{
	}

	void update()
	{
		for(size_t i = 0; i < body.size(); i++)
		{
			body[i].setPosition(body[i + 1].getPosition());
		}
	}

private:
	std::vector<GameObject> body;
};

#endif // CLEM_EXAMPLE_SNAKE_HPP_
