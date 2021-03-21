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

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "gap_buffer.h"

const size_t GB_GAP_SIZE = 32;

void gb_create(struct gap_buffer *gb) {
  assert(gb);
  gb->data = NULL;
  gb->gap_start = NULL;
  gb->gap_end = NULL;
  gb->len = 0;
}

bool gb_prealloc(struct gap_buffer *gb, size_t len) {
  assert(gb);
  char *data = malloc(len + GB_GAP_SIZE);
  if (!data)
    return false;
  gb->data = data;
  gb->len = len + GB_GAP_SIZE;
  // Gap is at the start by default
  gb->gap_start = gb->data;
  gb->gap_end = gb->gap_start + GB_GAP_SIZE;
  return true;
}

void gb_free(struct gap_buffer *gb) {
  assert(gb);
  if (gb->data)
    free(gb->data);
  gb_create(gb); // Resets all fields to defaults
}

inline char *gb_get(struct gap_buffer *gb, size_t index) {
  if (index > gb->len)
    return NULL;
  return gb_get_unchecked(gb, index);
}

char *gb_get_unchecked(struct gap_buffer *gb, size_t index) {
  if (index < (gb->gap_start - gb->data))
    return gb->data + index;
  return gb->data + (index + (gb->gap_end - gb->gap_start));
}
