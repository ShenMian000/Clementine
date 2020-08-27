// Copyright 2020 SMS
// License(Apache-2.0)
// 控制台光标

#ifndef CLEM_CURSOR_H_
#define CLEM_CURSOR_H_

#include <clem/common.hpp>

class Cursor
{
public:
	static Cursor& getInstance();

	void moveTo(short, short);

	void moveUp(short);
	void moveDown(short);
	void moveRight(short);
	void moveLeft(short);

	void show();
	void hide();

private:
	Cursor();

	short getX() const;
	short getY() const;

	static Cursor* instance;

	#ifdef OS_WIN
	void* hStdOut;
	#endif // OS_WIN
};

#endif // CLEM_CURSOR_H_
