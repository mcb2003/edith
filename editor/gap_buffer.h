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

#ifndef EDITH_GAP_BUFFER_H
#define EDITH_GAP_BUFFER_H
#include <stdbool.h>
#include <stddef.h>

extern const size_t GB_GAP_SIZE;

struct gap_buffer {
  char *data;
  char *gap_start;
  char *gap_end;
  size_t len;
};

void gb_create(struct gap_buffer *gb);
bool gb_prealloc(struct gap_buffer *gb, size_t len);
void gb_free(struct gap_buffer *gb);

char *gb_get(struct gap_buffer *gb, size_t index);
char *gb_get_unchecked(struct gap_buffer *gb, size_t index);

#endif
