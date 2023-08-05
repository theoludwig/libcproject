#ifndef __LIBCPROJECT_HASH_MAP__
#define __LIBCPROJECT_HASH_MAP__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "string.h"
#include "types.h"

#define HASH_MAP_INITIAL_CAPACITY 10

/**
 * @brief Hash map data structure.
 * @since v2.0.0
 */
struct hash_map {
  struct linked_list **items;

  size_t length;
  size_t capacity;
};

/**
 * @brief Hash map item data structure.
 * @since v2.0.0
 */
struct hash_map_item {
  void *data;
  string_t key;
};

/**
 * @brief Hash function (using SipHash 1-3 algorithm).
 * @param key
 * @param capacity
 * @see https://en.wikipedia.org/wiki/SipHash
 * @see https://github.com/veorq/SipHash
 * @since v2.0.0
 */
uint64_t hash(string_t key, size_t capacity);

/**
 * @brief Hash map initialization.
 * @since v2.0.0
 */
struct hash_map *hash_map_initialization();

/**
 * @brief Add an item to the hash map.
 * @param hash_map
 * @param key
 * @param data
 * @since v2.0.0
 */
void hash_map_add(struct hash_map *hash_map, string_t key, void *data);

/**
 * @brief Remove an item from the hash map.
 * @param hash_map
 * @param key
 * @since v2.0.0
 */
void hash_map_remove(struct hash_map *hash_map, string_t key);

/**
 * @brief Get an item from the hash map.
 * @param hash_map
 * @param key
 * @since v2.0.0
 */
void *hash_map_get(struct hash_map *hash_map, string_t key);

/**
 * @brief Check if the hash map contains a key.
 * @param hash_map
 * @param key
 * @since v2.0.0
 */
bool hash_map_contains_key(struct hash_map *hash_map, string_t key);

/**
 * @brief Get the hash map keys.
 *
 * @param hash_map
 * @since v2.0.0
 */
string_t *hash_map_get_keys(struct hash_map *hash_map);

/**
 * @brief Frees the hash map.
 * @since v3.0.0
 */
void hash_map_free(struct hash_map *hash_map);

#endif
