// Copyright 2020 SMS
// License(Apache-2.0)
// º¸≈Ã ‰»Î

#ifndef CLEM_KEYBOARD_INPUT_H_
#define CLEM_KEYBOARD_INPUT_H_

#include "input.h"

class KeyboardInput : public Input
{
public:
	const std::vector<ushort>& update() override;

	void scan();
};

#endif // CLEM_KEYBOARD_INPUT_H_
