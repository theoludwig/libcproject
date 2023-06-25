#include "filesystem.h"

int filesystem_read(char *path, byte **file_content, off_t *file_size) {
  int file_descriptor = open(path, O_RDONLY);
  if (file_descriptor == -1) {
    return -1;
  }
  (*file_size) = lseek(file_descriptor, 0, SEEK_END);
  lseek(file_descriptor, 0, SEEK_SET);
  (*file_content) = malloc(*file_size);
  if (read(file_descriptor, *file_content, *file_size) == -1) {
    return -1;
  }
  close(file_descriptor);
  return 0;
}

int filesystem_write(char *path, byte *file_content, off_t file_size) {
  int file_descriptor = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (file_descriptor == -1) {
    return -1;
  }
  if (write(file_descriptor, file_content, file_size) == -1) {
    return -1;
  }
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
  if (string_ends_with(path, ".ico")) {
    return "image/x-icon";
  }
  if (string_ends_with(path, ".svg")) {
    return "image/svg+xml";
  }
  if (string_ends_with(path, ".json")) {
    return "application/json";
  }
  if (string_ends_with(path, ".pdf")) {
    return "application/pdf";
  }
  if (string_ends_with(path, ".xml")) {
    return "application/xml";
  }
  if (string_ends_with(path, ".csv")) {
    return "text/csv";
  }
  if (string_ends_with(path, ".zip")) {
    return "application/zip";
  }
  if (string_ends_with(path, ".tar")) {
    return "application/x-tar";
  }
  if (string_ends_with(path, ".gz")) {
    return "application/x-gzip";
  }
  if (string_ends_with(path, ".mp3")) {
    return "audio/mpeg";
  }
  if (string_ends_with(path, ".wav")) {
    return "audio/wav";
  }
  if (string_ends_with(path, ".mp4")) {
    return "video/mp4";
  }
  if (string_ends_with(path, ".bin")) {
    return "application/octet-stream";
  }
  return "text/plain";
}
