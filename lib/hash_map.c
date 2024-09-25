#include "hash_map.h"

#define ROTATE_LEFT(x, b) (((x) << (b)) | ((x) >> (64 - (b))))

uint64_t sip_round(uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3) {
  v0 += v1;
  v2 += v3;
  v1 = ROTATE_LEFT(v1, 13);
  v3 = ROTATE_LEFT(v3, 16);
  v1 ^= v0;
  v3 ^= v2;
  v0 = ROTATE_LEFT(v0, 32);
  v2 += v1;
  v0 += v3;
  v1 = ROTATE_LEFT(v1, 17);
  v3 = ROTATE_LEFT(v3, 21);
  v1 ^= v2;
  v3 ^= v0;
  v2 = ROTATE_LEFT(v2, 32);
  return v0;
}

uint64_t hash(string_t key, size_t capacity) {
  size_t key_length = string_get_length(key);
  const uint64_t c = 0x736f6d6570736575;
  uint64_t v0 = c ^ 0x736f6d6570736575;
  uint64_t v1 = c ^ 0x646f72616e646f6d;
  uint64_t v2 = c ^ 0x6c7967656e657261;
  uint64_t v3 = c ^ 0x7465646279746573;

  uint64_t m;
  uint64_t hash;

  uint8_t *message = (uint8_t *)key;

  size_t remaining = key_length;
  size_t offset = 0;

  while (remaining >= 8) {
    memcpy(&m, message + offset, sizeof(uint64_t));
    v3 ^= m;

    for (uint8_t i = 0; i < 2; i++) {
      v0 = sip_round(v0, v1, v2, v3);
      v1 = ROTATE_LEFT(v1, 13);
      v2 = ROTATE_LEFT(v2, 16);
      v3 = ROTATE_LEFT(v3, 32);
      v0 ^= m;
    }

    v2 ^= 0xff;
    for (uint8_t i = 0; i < 4; i++) {
      v0 = sip_round(v0, v1, v2, v3);
      v1 = ROTATE_LEFT(v1, 13);
      v2 = ROTATE_LEFT(v2, 16);
      v3 = ROTATE_LEFT(v3, 32);
    }

    hash = v0 ^ v1 ^ v2 ^ v3;
    remaining -= sizeof(uint64_t);
    offset += sizeof(uint64_t);
  }

  m = (uint64_t)remaining << 56;
  switch (remaining) {
    case 7:
      m |= (uint64_t)message[offset + 6] << 48;
      break;
    case 6:
      m |= (uint64_t)message[offset + 5] << 40;
      break;
    case 5:
      m |= (uint64_t)message[offset + 4] << 32;
      break;
    case 4:
      m |= (uint64_t)message[offset + 3] << 24;
      break;
    case 3:
      m |= (uint64_t)message[offset + 2] << 16;
      break;
    case 2:
      m |= (uint64_t)message[offset + 1] << 8;
      break;
    case 1:
      m |= (uint64_t)message[offset];
      break;
    default:
      break;
  }

  v3 ^= m;

  for (uint8_t i = 0; i < 2; i++) {
    v0 = sip_round(v0, v1, v2, v3);
    v1 = ROTATE_LEFT(v1, 13);
    v2 = ROTATE_LEFT(v2, 16);
    v3 = ROTATE_LEFT(v3, 32);
  }

  v0 ^= m;
  v2 ^= 0xff;

  for (uint8_t i = 0; i < 4; i++) {
    v0 = sip_round(v0, v1, v2, v3);
    v1 = ROTATE_LEFT(v1, 13);
    v2 = ROTATE_LEFT(v2, 16);
    v3 = ROTATE_LEFT(v3, 32);
  }

  hash = v0 ^ v1 ^ v2 ^ v3;

  return hash % capacity;
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

void hash_map_add(struct hash_map *hash_map, string_t key_value, void *data) {
  if (hash_map->length == hash_map->capacity) {
    size_t previous_capacity = hash_map->capacity;
    hash_map->capacity += HASH_MAP_INITIAL_CAPACITY;
    hash_map->items = realloc(hash_map->items, sizeof(struct linked_list *) * hash_map->capacity);
    for (size_t index = previous_capacity; index < hash_map->capacity; index++) {
      hash_map->items[index] = NULL;
    }
  }
  string_t key = string_copy(key_value);
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
    } else {
      free(key);
      free(item);
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
    } else {
      free(item->key);
      free(item);
    }
    node = node->next;
  }
  linked_list_free(list);
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

void hash_map_free(struct hash_map *hash_map) {
  for (size_t index = 0; index < hash_map->capacity; index++) {
    struct linked_list *list = hash_map->items[index];
    if (list != NULL) {
      struct linked_list_node *node = list->head;
      while (node != NULL) {
        struct hash_map_item *item = (struct hash_map_item *)node->data;
        free(item->key);
        free(item);
        node = node->next;
      }
      linked_list_free(list);
    }
  }
  free(hash_map->items);
  free(hash_map);
}
