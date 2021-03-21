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

#ifndef EDITH_BUFFER_H
#define EDITH_BUFFER_H
#include <sys/stat.h>

#include "gap_buffer.h"

struct buffer {
  struct buffer *next;
  struct buffer *prev;
  char *name;
  struct gap_buffer content;
};

struct buffer *buffer_create(const char *name);
struct buffer *buffer_open(const char *fname, int flags, mode_t mode);
void buffer_free(struct buffer *buf);

#endif
