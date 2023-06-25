#ifndef __FILESYSTEM__
#define __FILESYSTEM__

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "string.h"

typedef uint8_t byte;

/**
 * @brief Read the content of a file.
 *
 * @param path
 * @param file_content
 * @param file_size
 * @return int
 * @retval -1 if the file does not exist or if there is an error.
 * @retval 0 for success.
 * @since v1.0.0
 */
int filesystem_read(string path, byte **file_content, off_t *file_size);

/**
 * @brief Write the content to a file.
 *
 * @param path
 * @param file_content
 * @param file_size
 * @return int
 * @retval -1 if there is an error.
 * @retval 0 for success.
 * @since v1.0.0
 */
int filesystem_write(string path, byte *file_content, off_t file_size);

/**
 * @brief Get the mimetype of a file.
 *
 * @param path
 * @since v1.0.0
 */
string filesystem_get_mimetype(string path);

#endif
