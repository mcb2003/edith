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
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "buffer.h"
#include "gap_buffer.h"

struct buffer *buffer_create(const char *name) {
  struct buffer *buf = malloc(sizeof(struct buffer));
  if (!buf)
    return NULL;
  buf->name = strdup(name);
  if (!buf->name)
    return NULL;
  gb_create(&buf->content);
  return buf;
}

struct buffer *buffer_open(const char *fname, int flags, mode_t mode) {
  struct buffer *buf = malloc(sizeof(struct buffer));
  if (!buf)
    return NULL;
  buf->name = strdup(fname);
  if (!buf->name) {
    free(buf);
    return NULL;
  }

  int fd;
  if ((fd = open(fname, flags, mode)) < 0) {
    fprintf(stderr, "Could not open file %s: %s", fname, strerror(errno));
    goto free_buf;
  }
  // Get the file size to preallocate the gap buffer
  struct stat stats;
  if (fstat(fd, &stats) < 0) {
    perror("stat");
    goto close_fd;
  }
  if (!gb_prealloc(&buf->content, stats.st_size)) {
    perror("Could not allocate buffer");
    goto close_fd;
  }
  // Copy the file's contents into the buffer
  if (read(fd, buf->content.gap_end, stats.st_size) < 0) {
    perror("read");
    goto close_fd;
  }
  close(fd);
  return buf;

close_fd:
  close(fd);
free_buf:
  free(buf->name);
  free(buf);
  return NULL;
}

void buffer_free(struct buffer *buf) {
  assert(buf);
  gb_free(&buf->content);
  free(buf->name);
  free(buf);
}
