// Copyright 2020 SMS
// License(Apache-2.0)
// º¸≈Ã ‰»Î

#include "keyboard_input.h"
#include <time.h>

using std::vector;

const vector<ushort>& KeyboardInput::update()
{
	events.clear();

	for(auto pair : index)
		if(GetAsyncKeyState(pair.first) & 0x8000)
			events.push_back(pair.second);

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
