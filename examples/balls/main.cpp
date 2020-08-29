// Copyright 2020 SMS
// License(Apache-2.0)
// 球

#include <time.h>
#include <clem/clem.hpp>

#ifdef OS_WIN
#include <windows.h>
#define sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define sleep(ms) usleep(ms * 1000)
#endif

using namespace std;

class BallPhysics : public PhysicsComponent
{
public:
	BallPhysics()
			: border(Vector(0, Terminal::getWindowSize().y), Terminal::getWindowSize())
	{
		velocity.x = (double)rand() / RAND_MAX;
		velocity.y = (double)rand() / RAND_MAX;
	}

	void update(GameObject& obj)
	{
		auto pos = obj.getPosition();
		if(pos.x <= border.x || pos.x >= border.width)
			velocity.x *= -1;
		if(pos.y <= border.y || pos.y >= border.height)
			velocity.y *= -1;

		PhysicsComponent::update(obj);
	}

private:
	Rect border;
};

int main()
{
	Terminal::Cursor::hide();
	Scene               scene({0, 0, 20, 10});
	vector<GameObject*> balls;

	srand(time(nullptr));

	int num;
	printf("Balls num: ");
	scanf("%d", &num);

	for(int i = 0; i < num; i++)
	{
		auto ball = new GameObject(scene, {'O', Attribute(fore::yellow)});
		ball->setPhysics(new BallPhysics());
		ball->setPosition({1, 1});
		balls.push_back(ball);
	}

	while(true)
	{
		Terminal::Cursor::moveTo({0, 11});
		auto pos = balls.back()->getPosition();
		printf("%f %f", pos.x, pos.y);
		getchar();

		scene.update();
		scene.render();

		sleep(50);
	}
}
