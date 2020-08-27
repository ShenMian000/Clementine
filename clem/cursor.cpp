// Copyright 2020 SMS
// License(Apache-2.0)
// 控制台光标

#include "cursor.h"

#ifdef OS_WIN

#include <stdexcept>
#include <string>
#include <assert.h>
#include <windows.h>

using std::runtime_error;
using std::to_string;

Cursor* Cursor::instance;

Cursor& Cursor::getInstance()
{
	if(instance == nullptr)
		instance = new Cursor();
	return *instance;
}

void Cursor::moveTo(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, {x, y});
}

void Cursor::moveUp(short i)
{
	assert(getX() - i > 0);
	moveTo(getX(), getY() - i);
}

void Cursor::moveDown(short i)
{
	moveTo(getX(), getY() + i);
}

void Cursor::moveRight(short i)
{
	moveTo(getX() + i, getY());
}

void Cursor::moveLeft(short i)
{
	assert(getX() - i > 0);
	moveTo(getX() - i, getY());
}

void Cursor::show()
{
	CONSOLE_CURSOR_INFO curInfo;
	bool                ret;

	ret = GetConsoleCursorInfo(hStdOut, &curInfo);
	if(!ret)
		throw runtime_error(to_string(GetLastError()));

	curInfo.bVisible = TRUE;

	ret = SetConsoleCursorInfo(hStdOut, &curInfo);
	if(!ret)
		throw runtime_error(to_string(GetLastError()));
}

void Cursor::hide()
{
	CONSOLE_CURSOR_INFO curInfo;
	bool                ret;

	ret = GetConsoleCursorInfo(hStdOut, &curInfo);
	if(!ret)
		throw runtime_error(to_string(GetLastError()));

	curInfo.bVisible = FALSE;

	ret = SetConsoleCursorInfo(hStdOut, &curInfo);
	if(!ret)
		throw runtime_error(to_string(GetLastError()));
}

Cursor::Cursor()
{
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if(!hStdOut)
		throw runtime_error(to_string(GetLastError()));
}

short Cursor::getX() const
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;

	GetConsoleScreenBufferInfo(hStdOut, &bufInfo);

	return bufInfo.dwCursorPosition.X;
}

short Cursor::getY() const
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;

	GetConsoleScreenBufferInfo(hStdOut, &bufInfo);

	return bufInfo.dwCursorPosition.Y;
}

#endif // OS_WIN
