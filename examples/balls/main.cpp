// Copyright 2020 SMS
// License(Apache-2.0)
// 球

#include <time.h>
#include <clem/clem.hpp>

#ifdef OS_WIN
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#else
#include <sys/wait.h>
#define SLEEP(ms) sleep(ms * 1000)
#endif

using namespace std;

class BallPhysics : public PhysicsComponent
{
public:
	BallPhysics()
			: border(Terminal::getWindowSize())
	{
		velocity.x = (double)rand() / RAND_MAX;
		velocity.y = (double)rand() / RAND_MAX;
	}

	void update(GameObject& obj)
	{
		auto pos = obj.getPosition();
		if(pos.x <= 0 || pos.x >= border.x)
			velocity.x *= -1;
		if(pos.y <= 0 || pos.y >= border.y)
			velocity.y *= -1;

		obj.setPosition(obj.getPosition() + velocity);
	}

private:
	Size border;
};

int main()
{
	Terminal::Cursor::hide();
	Scene scene;
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
		scene.update();
		scene.render();

		SLEEP(50);
	}
}
