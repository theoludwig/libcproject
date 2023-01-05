#ifndef __FILESYSTEM__
#define __FILESYSTEM__

#include <fcntl.h>

/**
 * @brief Read the content of a file.
 *
 * @param path
 * @param file_content
 * @param file_size
 * @return int
 * @retval -1 if the file does not exist
 * @retval 0 for success
 */
int filesystem_read(char *path, char **file_content, off_t *file_size);

/**
 * @brief Write the content to a file.
 *
 * @param path
 * @param file_content
 * @param file_size
 * @return int
 * @retval -1 if errors
 * @retval 0 for success
 */
int filesystem_write(char *path, char *file_content, off_t file_size);

/**
 * @brief Get the mimetype of a file.
 *
 * @param path
 * @return char*
 */
char *filesystem_get_mimetype(char *path);

#endif
