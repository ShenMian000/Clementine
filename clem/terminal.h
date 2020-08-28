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
    static void moveTo(const Coord& coord);

    static void show();
    static void hide();
  };
};

#endif // CLEM_TERMINAL_H_
