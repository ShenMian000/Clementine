// Copyright 2020 SMS
// License(Apache-2.0)
// º¸≈Ã ‰»Î

#include "keyboard_input.h"
#include <time.h>

using std::vector;

const vector<ushort>& KeyboardInput::update()
{
	events.clear();

	scan();

	static vector<ushort> lastEvents;
	static clock_t        lastTime;

	auto now = clock();
	if(events == lastEvents && now - lastTime < interval)
		events.clear();
	else
	{
		lastEvents = events;
		lastTime   = now;
	}

	return events;
}

#ifdef OS_LINUX

#include <termios.h>
#include <fcntl.h>
// #include <unistd.h>

void KeyboardInput::scan()
{
	char    code;
	termios oldTermios, newTermios;
	auto    tty = open("/dev/tty", O_RDONLY);

	tcgetattr(tty, &oldTermios);
	newTermios = oldTermios;
	newTermios.c_lflag &= ~(ICANON | ECHO);

	tcsetattr(tty, TCSANOW, &newTermios);
	read(tty, &code, 1);
	tcsetattr(tty, TCSANOW, &oldTermios);

	for(auto pair : index)
		if(pair.first == code)
			events.push_back(pair.second);
}

#endif // OS_LINUX

#ifdef OS_WIN

#include <windows.h>

void KeyboardInput::scan()
{
	for(auto pair : index)
		if(GetAsyncKeyState(pair.first) & 0x8000)
			events.push_back(pair.second);
}

#endif // OS_WIN
