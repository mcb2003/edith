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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "buffer.h"
#include "editor.h"

/* Global Data */

// The circular list of buffers
struct buffer *G_BUFFERS;
// The currently selected buffer
struct buffer *G_CURRENT_BUFFER;

void editor_init() {
  G_BUFFERS = buffer_open("../editor/editor.h", O_RDONLY, 0);
  if (!G_BUFFERS) {
    perror("Could not create initial buffer");
    exit(EXIT_FAILURE);
  }
  atexit(editor_fini);

  // Set up the circular chain
  G_BUFFERS->next = G_BUFFERS;
  G_BUFFERS->prev = G_BUFFERS;

  G_CURRENT_BUFFER = G_BUFFERS;
}

void editor_fini() { buffer_free(G_BUFFERS); }
