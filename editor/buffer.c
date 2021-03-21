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
#include <stdlib.h>
#include <string.h>

#include "buffer.h"

struct buffer *buffer_create(const char *name) {
  struct buffer *buf = malloc(sizeof(struct buffer));
  if (!buf)
    return NULL;
  buf->name = strdup(name);
  if (!buf->name)
    return NULL;
  return buf;
}

void buffer_free(struct buffer *buf) {
  assert(buf);
  free(buf->name);
  free(buf);
}
