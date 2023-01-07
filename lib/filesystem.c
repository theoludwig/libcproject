#include "filesystem.h"

int filesystem_read(char *path, char **file_content, off_t *file_size) {
  int file_descriptor = open(path, O_RDONLY);
  if (file_descriptor == -1) {
    return -1;
  }
  (*file_size) = lseek(file_descriptor, 0, SEEK_END);
  lseek(file_descriptor, 0, SEEK_SET);
  (*file_content) = malloc(*file_size);
  read(file_descriptor, *file_content, *file_size);
  close(file_descriptor);
  return 0;
}

int filesystem_write(char *path, char *file_content, off_t file_size) {
  int file_descriptor = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (file_descriptor == -1) {
    return -1;
  }
  write(file_descriptor, file_content, file_size);
  close(file_descriptor);
  return 0;
}

char *filesystem_get_mimetype(char *path) {
  if (string_ends_with(path, ".html")) {
    return "text/html";
  }
  if (string_ends_with(path, ".css")) {
    return "text/css";
  }
  if (string_ends_with(path, ".js")) {
    return "text/javascript";
  }
  if (string_ends_with(path, ".png")) {
    return "image/png";
  }
  if (string_ends_with(path, ".jpg") || string_ends_with(path, ".jpeg")) {
    return "image/jpeg";
  }
  if (string_ends_with(path, ".gif")) {
    return "image/gif";
  }
  return "text/plain";
}
