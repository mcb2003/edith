/*
 *  Edith: Yet another text editor
    Copyright (C) 2021 Michael Connor Buchan

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

author: Michael Connor Buchan <mikey@blindcomputing.org.>
*/

#include <locale.h>
#include <stdio.h>

#include <buffer.h>
#include <curses.h>
#include <display.h>
#include <editor.h>
#include <gap_buffer.h>

int main() {
  setlocale(LC_ALL, "");
  editor_init();
  display_init();
  // Display the current buffer
  size_t left_len =
      G_CURRENT_BUFFER->content.gap_start - G_CURRENT_BUFFER->content.data;
  size_t buffer_size =
      G_CURRENT_BUFFER->content.gap_end - G_CURRENT_BUFFER->content.gap_start;
  addnstr(G_CURRENT_BUFFER->content.data, left_len);
  addnstr(G_CURRENT_BUFFER->content.gap_end,
          G_CURRENT_BUFFER->content.len - left_len - buffer_size);
  getch();
  return 0;
}
