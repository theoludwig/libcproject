#include "filesystem.h"

int filesystem_read(string_t path, byte_t **file_content, off_t *file_size) {
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

int filesystem_write(string_t path, byte_t *file_content, off_t file_size) {
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

bool filesystem_exists(string_t path) {
  return access(path, F_OK) == 0;
}

int filesystem_remove(string_t path) {
  return remove(path);
}

string_t filesystem_get_mimetype(string_t path) {
  if (string_ends_with(path, ".aac")) {
    return "audio/aac";
  }
  if (string_ends_with(path, ".abw")) {
    return "application/x-abiword";
  }
  if (string_ends_with(path, ".arc")) {
    return "application/x-freearc";
  }
  if (string_ends_with(path, ".avif")) {
    return "image/avif";
  }
  if (string_ends_with(path, ".avi")) {
    return "video/x-msvideo";
  }
  if (string_ends_with(path, ".azw")) {
    return "application/vnd.amazon.ebook";
  }
  if (string_ends_with(path, ".bin")) {
    return "application/octet-stream";
  }
  if (string_ends_with(path, ".bmp")) {
    return "image/bmp";
  }
  if (string_ends_with(path, ".bz")) {
    return "application/x-bzip";
  }
  if (string_ends_with(path, ".bz2")) {
    return "application/x-bzip2";
  }
  if (string_ends_with(path, ".cda")) {
    return "application/x-cdf";
  }
  if (string_ends_with(path, ".csh")) {
    return "application/x-csh";
  }
  if (string_ends_with(path, ".css")) {
    return "text/css";
  }
  if (string_ends_with(path, ".csv")) {
    return "text/csv";
  }
  if (string_ends_with(path, ".doc")) {
    return "application/msword";
  }
  if (string_ends_with(path, ".docx")) {
    return "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
  }
  if (string_ends_with(path, ".eot")) {
    return "application/vnd.ms-fontobject";
  }
  if (string_ends_with(path, ".epub")) {
    return "application/epub+zip";
  }
  if (string_ends_with(path, ".gz")) {
    return "application/gzip";
  }
  if (string_ends_with(path, ".gif")) {
    return "image/gif";
  }
  if (string_ends_with(path, ".htm") || string_ends_with(path, ".html")) {
    return "text/html";
  }
  if (string_ends_with(path, ".ico")) {
    return "image/vnd.microsoft.icon";
  }
  if (string_ends_with(path, ".ics")) {
    return "text/calendar";
  }
  if (string_ends_with(path, ".jar")) {
    return "application/java-archive";
  }
  if (string_ends_with(path, ".jpg") || string_ends_with(path, ".jpeg") || string_ends_with(path, ".jpe") || string_ends_with(path, ".jif") || string_ends_with(path, ".jfif") || string_ends_with(path, ".jfi")) {
    return "image/jpeg";
  }
  if (string_ends_with(path, ".js") || string_ends_with(path, ".mjs") || string_ends_with(path, ".cjs")) {
    return "text/javascript";
  }
  if (string_ends_with(path, ".json")) {
    return "application/json";
  }
  if (string_ends_with(path, ".jsonld")) {
    return "application/ld+json";
  }
  if (string_ends_with(path, ".mid") || string_ends_with(path, ".midi")) {
    return "audio/midi";
  }
  if (string_ends_with(path, ".mp3")) {
    return "audio/mpeg";
  }
  if (string_ends_with(path, ".mp4")) {
    return "video/mp4";
  }
  if (string_ends_with(path, ".mpeg")) {
    return "video/mpeg";
  }
  if (string_ends_with(path, ".mpkg")) {
    return "application/vnd.apple.installer+xml";
  }
  if (string_ends_with(path, ".odp")) {
    return "application/vnd.oasis.opendocument.presentation";
  }
  if (string_ends_with(path, ".ods")) {
    return "application/vnd.oasis.opendocument.spreadsheet";
  }
  if (string_ends_with(path, ".odt")) {
    return "application/vnd.oasis.opendocument.text";
  }
  if (string_ends_with(path, ".oga")) {
    return "audio/ogg";
  }
  if (string_ends_with(path, ".ogv")) {
    return "video/ogg";
  }
  if (string_ends_with(path, ".ogx")) {
    return "application/ogg";
  }
  if (string_ends_with(path, ".opus")) {
    return "audio/opus";
  }
  if (string_ends_with(path, ".otf")) {
    return "font/otf";
  }
  if (string_ends_with(path, ".png")) {
    return "image/png";
  }
  if (string_ends_with(path, ".pdf")) {
    return "application/pdf";
  }
  if (string_ends_with(path, ".php")) {
    return "application/x-httpd-php";
  }
  if (string_ends_with(path, ".ppt")) {
    return "application/vnd.ms-powerpoint";
  }
  if (string_ends_with(path, ".pptx")) {
    return "application/vnd.openxmlformats-officedocument.presentationml.presentation";
  }
  if (string_ends_with(path, ".rar")) {
    return "application/vnd.rar";
  }
  if (string_ends_with(path, ".rtf")) {
    return "application/rtf";
  }
  if (string_ends_with(path, ".sh")) {
    return "application/x-sh";
  }
  if (string_ends_with(path, ".svg")) {
    return "image/svg+xml";
  }
  if (string_ends_with(path, ".tar")) {
    return "application/x-tar";
  }
  if (string_ends_with(path, ".tif") || string_ends_with(path, ".tiff")) {
    return "image/tiff";
  }
  if (string_ends_with(path, ".ts")) {
    return "application/typescript";
  }
  if (string_ends_with(path, ".ttf")) {
    return "font/ttf";
  }
  if (string_ends_with(path, ".txt")) {
    return "text/plain";
  }
  if (string_ends_with(path, ".vsd")) {
    return "application/vnd.visio";
  }
  if (string_ends_with(path, ".wav")) {
    return "audio/wav";
  }
  if (string_ends_with(path, ".weba") || string_ends_with(path, ".webm")) {
    return "audio/webm";
  }
  if (string_ends_with(path, ".webp")) {
    return "image/webp";
  }
  if (string_ends_with(path, ".woff")) {
    return "font/woff";
  }
  if (string_ends_with(path, ".woff2")) {
    return "font/woff2";
  }
  if (string_ends_with(path, ".xhtml")) {
    return "application/xhtml+xml";
  }
  if (string_ends_with(path, ".xls")) {
    return "application/vnd.ms-excel";
  }
  if (string_ends_with(path, ".xlsx")) {
    return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
  }
  if (string_ends_with(path, ".xml")) {
    return "application/xml";
  }
  if (string_ends_with(path, ".xul")) {
    return "application/vnd.mozilla.xul+xml";
  }
  if (string_ends_with(path, ".zip")) {
    return "application/zip";
  }
  if (string_ends_with(path, ".3gp")) {
    return "video/3gpp";
  }
  if (string_ends_with(path, ".3g2")) {
    return "video/3gpp2";
  }
  if (string_ends_with(path, ".7z")) {
    return "application/x-7z-compressed";
  }
  return "application/octet-stream";
}
