#include "hash_map.h"

uint64_t hash(string_t key, size_t capacity) {
  uint64_t hash_value = 0;
  for (size_t iteration = 0; iteration < capacity; iteration++) {
    hash_value += key[iteration];
    hash_value *= key[iteration];
  }
  return hash_value % capacity;
}

struct hash_map *hash_map_initialization() {
  struct hash_map *hash_map = malloc(sizeof(struct hash_map));
  hash_map->items = malloc(sizeof(struct linked_list *) * HASH_MAP_INITIAL_CAPACITY);
  hash_map->length = 0;
  hash_map->capacity = HASH_MAP_INITIAL_CAPACITY;
  for (size_t index = 0; index < hash_map->capacity; index++) {
    hash_map->items[index] = NULL;
  }
  return hash_map;
}

void hash_map_add(struct hash_map *hash_map, string_t key, void *data) {
  if (hash_map->length == hash_map->capacity) {
    size_t previous_capacity = hash_map->capacity;
    hash_map->capacity += HASH_MAP_INITIAL_CAPACITY;
    hash_map->items = realloc(hash_map->items, sizeof(struct linked_list *) * hash_map->capacity);
    for (size_t index = previous_capacity; index < hash_map->capacity; index++) {
      hash_map->items[index] = NULL;
    }
  }
  uint64_t hash_value = hash(key, hash_map->capacity);
  struct linked_list *list = hash_map->items[hash_value];
  struct hash_map_item *item = malloc(sizeof(struct hash_map_item));
  item->key = key;
  item->data = data;
  if (list == NULL) {
    list = linked_list_initialization();
    hash_map->items[hash_value] = list;
    linked_list_add_in_head(list, (void *)item);
    hash_map->length++;
  } else {
    struct linked_list_node *node = list->head;
    bool found = false;
    while (node != NULL && !found) {
      struct hash_map_item *item = (struct hash_map_item *)node->data;
      if (string_equals(key, item->key)) {
        item->data = data;
        found = true;
      }
      node = node->next;
    }
    if (!found) {
      linked_list_add_in_head(list, (void *)item);
      hash_map->length++;
    }
  }
}

void hash_map_remove(struct hash_map *hash_map, string_t key) {
  uint64_t hash_value = hash(key, hash_map->capacity);
  struct linked_list *list = hash_map->items[hash_value];
  if (list == NULL) {
    return;
  }
  struct linked_list *new_list = linked_list_initialization();
  struct linked_list_node *node = list->head;
  while (node != NULL) {
    struct hash_map_item *item = (struct hash_map_item *)node->data;
    if (!string_equals(key, item->key)) {
      linked_list_add_in_head(new_list, item);
    }
    node = node->next;
  }
  free(list);
  hash_map->items[hash_value] = new_list;
  hash_map->length--;
}

void *hash_map_get(struct hash_map *hash_map, string_t key) {
  uint64_t hash_value = hash(key, hash_map->capacity);
  struct linked_list *list = hash_map->items[hash_value];
  if (list == NULL) {
    return NULL;
  }
  struct linked_list_node *node = list->head;
  while (node != NULL) {
    struct hash_map_item *item = (struct hash_map_item *)node->data;
    if (string_equals(key, item->key)) {
      return item->data;
    }
    node = node->next;
  }
  return NULL;
}

bool hash_map_contains_key(struct hash_map *hash_map, string_t key) {
  return hash_map_get(hash_map, key) != NULL;
}

string_t *hash_map_get_keys(struct hash_map *hash_map) {
  string_t *keys = malloc(sizeof(string_t) * hash_map->length);
  size_t index = 0;
  for (size_t hash_value = 0; hash_value < hash_map->capacity; hash_value++) {
    struct linked_list *list = hash_map->items[hash_value];
    if (list != NULL) {
      struct linked_list_node *node = list->head;
      while (node != NULL) {
        struct hash_map_item *item = (struct hash_map_item *)node->data;
        keys[index++] = item->key;
        node = node->next;
      }
    }
  }
  return keys;
}
