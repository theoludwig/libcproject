#ifndef __DICTIONARY__
#define __DICTIONARY__

#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"

#define DICTIONARY_INITIAL_CAPACITY 10

// Dictionary implementation with O(n) lookup complexity.
struct dictionary {
  struct dictionary_item **items;

  size_t length;
  size_t capacity;
};

struct dictionary_item {
  void *data;
  char *key;
};

struct dictionary *dictionary_initialization();

void dictionary_add(struct dictionary *dictionary, char *key, void *data);

void dictionary_remove(struct dictionary *dictionary, char *key);

struct dictionary_item *dictionary_get(struct dictionary *dictionary, char *key);

bool dictionary_contains_key(struct dictionary *dictionary, char *key);

#endif
