#include "dictionary.h"

#include <stdlib.h>

#include "string.h"

struct dictionary *dictionary_initialization() {
  struct dictionary *dictionary = malloc(sizeof(struct dictionary));
  dictionary->items = malloc(sizeof(struct dictionary_item *) * DICTIONARY_INITIAL_CAPACITY);
  dictionary->length = 0;
  dictionary->capacity = DICTIONARY_INITIAL_CAPACITY;
  for (size_t index = 0; index < dictionary->capacity; index++) {
    dictionary->items[index] = NULL;
  }
  return dictionary;
}

void dictionary_add(struct dictionary *dictionary, char *key, void *data) {
  if (dictionary->length == dictionary->capacity) {
    size_t previous_capacity = dictionary->capacity;
    dictionary->capacity += DICTIONARY_INITIAL_CAPACITY;
    dictionary->items = realloc(dictionary->items, sizeof(struct dictionary_item *) * dictionary->capacity);
    for (size_t index = previous_capacity; index < dictionary->capacity; index++) {
      dictionary->items[index] = NULL;
    }
  }
  struct dictionary_item *item = NULL;
  for (size_t index = 0; index < dictionary->length && item == NULL; index++) {
    if (string_equals(key, dictionary->items[index]->key)) {
      item = dictionary->items[index];
    }
  }
  if (item == NULL) {
    item = malloc(sizeof(struct dictionary_item));
    item->key = key;
    item->data = data;
    dictionary->items[dictionary->length] = item;
    dictionary->length++;
  } else {
    item->data = data;
  }
}

void dictionary_remove(struct dictionary *dictionary, char *key) {
  bool found = false;
  for (size_t index = 0; index < dictionary->length && !found; index++) {
    if (string_equals(key, dictionary->items[index]->key)) {
      free(dictionary->items[index]);
      dictionary->items[index] = dictionary->items[dictionary->length - 1];
      dictionary->length--;
      found = true;
    }
  }
}

struct dictionary_item *dictionary_get(struct dictionary *dictionary, char *key) {
  for (size_t index = 0; index < dictionary->length; index++) {
    struct dictionary_item *item = dictionary->items[index];
    if (string_equals(key, item->key)) {
      return item;
    }
  }
  return NULL;
}

bool dictionary_contains_key(struct dictionary *dictionary, char *key) {
  return dictionary_get(dictionary, key) != NULL;
}
