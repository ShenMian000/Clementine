// Copyright 2020 SMS
// License(Apache-2.0)
// жу╤к

#include "terminal.h"

#ifdef OS_LINUX

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

Size Terminal::getWindowSize()
{
  winsize winSize;
  ioctl(STDIN_FILENO, TIOCGWINSZ, &winSize);
  return {winSize.ws_col, winSize.ws_row + 1};
}

void Terminal::Cursor::moveTo(const Vector& coord)
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

Size Terminal::getWindowSize()
{
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	
	auto ret = GetConsoleScreenBufferInfo(hStdOut, &screenInfo);
	if(!ret)
		assert(false);

	return Size(screenInfo.srWindow.Right + 1, screenInfo.srWindow.Bottom + 1);
}

void Terminal::Cursor::show()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	bool                ret;

	ret = GetConsoleCursorInfo(hStdOut, &cursorInfo);
	if(!ret)
    assert(false);

	cursorInfo.bVisible = TRUE;

	ret = SetConsoleCursorInfo(hStdOut, &cursorInfo);
	if(!ret)
    assert(false);
}

void Terminal::Cursor::hide()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	bool                ret;

	ret = GetConsoleCursorInfo(hStdOut, &cursorInfo);
	if(!ret)
    assert(false);

	cursorInfo.bVisible = FALSE;

	ret = SetConsoleCursorInfo(hStdOut, &cursorInfo);
	if(!ret)
    assert(false);
}

void Terminal::Cursor::moveTo(const Vector& coord)
{
	SetConsoleCursorPosition(hStdOut, {(short)coord.x, (short)coord.y});
}

void Terminal::Cursor::moveUp(ushort n)
{
	Coord pos = getCursorPosition();
	moveTo({pos.x, pos.y - 1});
}

void Terminal::Cursor::moveDown(ushort n)
{
	Coord pos = getCursorPosition();
	moveTo({pos.x, pos.y + 1});
}

void Terminal::Cursor::moveRight(ushort n)
{
	Coord pos = getCursorPosition();
	moveTo({pos.x + 1, pos.y});
}

void Terminal::Cursor::moveLeft(ushort n)
{
	Coord pos = getCursorPosition();
	moveTo({pos.x - 1, pos.y});
}

Vector Terminal::Cursor::getCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;

	GetConsoleScreenBufferInfo(hStdOut, &bufInfo);

	return Coord(bufInfo.dwCursorPosition.X, bufInfo.dwCursorPosition.Y);
}

#endif // OS_WIN
