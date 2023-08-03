#include "hash_map_test.h"

void hash_map_test() {
  struct hash_map *hash_map = hash_map_initialization();
  assert(hash_map->length == 0);
  hash_map_add(hash_map, "key", (void *)'a');
  hash_map_add(hash_map, "key1", (void *)'b');
  hash_map_add(hash_map, "key2", (void *)'c');
  hash_map_add(hash_map, "key3", (void *)'d');
  hash_map_add(hash_map, "key4", (void *)'e');
  hash_map_add(hash_map, "key5", (void *)'f');
  assert(hash_map->length == 6);
  assert(hash_map_get(hash_map, "key") == (void *)'a');
  assert(hash_map_get(hash_map, "key1") == (void *)'b');
  assert(hash_map_get(hash_map, "key2") == (void *)'c');
  assert(hash_map_get(hash_map, "key3") == (void *)'d');
  assert(hash_map_get(hash_map, "key4") == (void *)'e');
  assert(hash_map_get(hash_map, "key5") == (void *)'f');
  hash_map_add(hash_map, "key5", (void *)'a');
  assert(hash_map_get(hash_map, "key5") == (void *)'a');
  assert(hash_map_contains_key(hash_map, "key5"));
  assert(!hash_map_contains_key(hash_map, "invalid key"));
  assert(hash_map_contains_key(hash_map, "key5"));
  hash_map_remove(hash_map, "key5");
  assert(hash_map->length == 5);
  assert(!hash_map_contains_key(hash_map, "key5"));
  hash_map_free(hash_map);
}
