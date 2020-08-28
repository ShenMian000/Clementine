// Copyright 2020 SMS
// License(Apache-2.0)
// жу╤к

#ifndef CLEM_TERMINAL_H_
#define CLEM_TERMINAL_H_

#include <clem/common.hpp>

class Terminal
{
public:
  static Size getWindowSize();

  class Cursor
  {
  public:
    static void show();
    static void hide();

    static void moveTo(const Coord& coord);
		static void moveUp(ushort n);
		static void moveDown(ushort n);
		static void moveRight(ushort n);
		static void moveLeft(ushort n);
  
  private:
#ifdef OS_WIN
    static Coord getCursorPosition();
#endif
	};
};

#endif // CLEM_TERMINAL_H_
