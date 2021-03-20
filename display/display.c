#include <stdlib.h>

#include <curses.h>

#include "display.h"

void display_init() {
  initscr();
  atexit(display_fini);
  cbreak();
  noecho();
  keypad(stdscr, true);
}

void display_fini() { endwin(); }
