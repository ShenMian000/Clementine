// Copyright 2020 SMS
// License(Apache-2.0)
// жу╤к

#include "terminal.h"

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#ifdef OS_LINUX

Size Terminal::getWindowSize()
{
  winsize winSize;
  ioctl(STDIN_FILENO, TIOCGWINSZ, &winSize);
  return {winSize.ws_col, winSize.ws_row};
}

void Terminal::Cursor::moveTo(const Coord& coord)
{
	printf("\e[%u;%uH", (ushort)coord.y, (ushort)coord.x);
}

void Terminal::Cursor::show()
{
	printf("\e[?25h");
}

void Terminal::Cursor::hide()
{
	printf("\e[?25l");
}

#endif // OS_LINUX

#ifdef OS_WIN

#include <windows.h>

void Terminal::Cursor::show()
{
	CONSOLE_CURSOR_INFO curInfo;
	bool                ret;

	ret = GetConsoleCursorInfo(hStdOut, &curInfo);
	if(!ret)
    assert(false);

	curInfo.bVisible = TRUE;

	ret = SetConsoleCursorInfo(hStdOut, &curInfo);
	if(!ret)
    assert(false);
}

void Terminal::Cursor::hide()
{
	CONSOLE_CURSOR_INFO curInfo;
	bool                ret;

	ret = GetConsoleCursorInfo(hStdOut, &curInfo);
	if(!ret)
    assert(false);

	curInfo.bVisible = FALSE;

	ret = SetConsoleCursorInfo(hStdOut, &curInfo);
	if(!ret)
    assert(false);
}

void Terminal::Cursor::moveTo(const Coord& coord)
{
  SetConsoleCursorPosition(hStdOut, {x, y});
}

void Terminal::Cursor::moveUp(ushort n)
{
	Coord pos = getCursorPosition();
	moveTo(pos.x, pos.y - 1);
}

void Terminal::Cursor::moveDown(ushort n)
{
	Coord pos = getCursorPosition();
	moveTo(pos.x, pos.y + 1);
}

void Terminal::Cursor::moveRight(ushort n)
{
	Coord pos = getCursorPosition();
	moveTo(pos.x + 1, pos.y);
}

void Terminal::Cursor::moveLeft(ushort n)
{
	Coord pos = getCursorPosition();
	moveTo(pos.x - 1, pos.y);
}

Coord Terminal::Cursor::getCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;

	GetConsoleScreenBufferInfo(hStdOut, &bufInfo);

	return {bufInfo.dwCursorPosition.X, bufInfo.dwCursorPosition.Y};
}

#endif // OS_WIN
