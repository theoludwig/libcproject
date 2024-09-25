#ifndef __LIBCPROJECT_FILESYSTEM__
#define __LIBCPROJECT_FILESYSTEM__

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "string.h"
#include "types.h"

/**
 * @brief Read the content of a file.
 *
 * @param path
 * @param file_content
 * @param file_size The size of the file that was read (mutated by the function).
 * @retval -1 if the file does not exist or if there is an error.
 * @retval 0 for success.
 * @return int
 * @since v1.0.0
 */
int filesystem_read(string_t path, byte_t **file_content, size_t *file_size);

/**
 * @brief Write the content to a file.
 *
 * @param path
 * @param file_content
 * @param file_size
 * @retval -1 if there is an error.
 * @retval 0 for success.
 * @return int
 * @since v1.0.0
 */
int filesystem_write(string_t path, byte_t *file_content, size_t file_size);

/**
 * @brief Check if a path exists.
 *
 * @param path
 * @return bool
 * @since v3.1.0
 */
bool filesystem_exists(string_t path);

/**
 * @brief Removes a path.
 *
 * @param path
 * @return int
 * @retval -1 if there is an error.
 * @retval 0 for success.
 * @return int
 * @since v3.1.0
 */
int filesystem_remove(string_t path);

/**
 * @brief Get the mimetype of a file based on its extension.
 *
 * @param path
 * @see https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/MIME_types/Common_types
 * @see https://www.iana.org/assignments/media-types/media-types.xhtml
 * @return string_t
 * @since v1.0.0
 */
string_t filesystem_get_mimetype(string_t path);

#endif
