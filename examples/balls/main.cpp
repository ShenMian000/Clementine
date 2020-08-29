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

vector<GameObject*> balls;

class BallPhysics : public PhysicsComponent
{
public:
	BallPhysics(Scene& scene, const Rect& border)
			: scene(scene), border(border)
	{
		velocity.x = (double)rand() / (RAND_MAX + 1);
		velocity.y = (double)rand() / (RAND_MAX + 1);
	}

	void update(GameObject& obj)
	{
		auto pos = obj.getPosition();

		pos += velocity;

		// 碰撞检测
		if(pos.x <= border.x || pos.x >= border.x + border.width)
			velocity.x *= -1;
		if(pos.y <= border.y || pos.y >= border.y + border.height)
			velocity.y *= -1;

		for(auto ball : balls)
		{
			if(ball == &obj)
				continue;

			auto otherPos = ball->getPosition();

			if(pos.distance(otherPos) < 1)
			{
				velocity.x *= -1;
				velocity.y *= -1;
				break;
			}
		}

		PhysicsComponent::update(obj);
	}

private:
	Rect   border;
	Scene& scene;
};

int main()
{

	int  num;
	Rect border;
	printf("Balls num: ");
	scanf("%d", &num);
	printf("Border   : ");
	scanf("%f %f %f %f", &border.x, &border.y, &border.width, &border.height);

	Terminal::Cursor::hide();

	Scene scene(border);

	srand(time(nullptr));

	for(int i = 0; i < num; i++)
	{
		auto ball = new GameObject(scene, {'O', Attribute(fore::yellow)});
		ball->setPhysics(new BallPhysics(scene, border));
		ball->setPosition({rand() % (int)border.width + border.x, rand() % (int)border.height + border.y});
		balls.push_back(ball);
	}

	while(true)
	{
		Terminal::Cursor::moveTo({border.x, border.y + border.height});
		auto pos = balls.back()->getPosition();
		printf("%f %f", pos.x, pos.y);
		// getchar();

		scene.update();
		scene.render();

		sleep(50);
	}
}
