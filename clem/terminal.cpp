// Copyright 2020 SMS
// License(Apache-2.0)
// жу╤к

#include "terminal.h"

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

Size Terminal::getWinSize()
{
  winsize winSize;
  ioctl(STDIN_FILENO, TIOCGWINSZ, &winSize);
  return {winSize.ws_col, winSize.ws_row};
}
