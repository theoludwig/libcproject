#include "dictionary_test.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "libcproject.h"

void dictionary_test() {
  struct dictionary *dictionary = dictionary_initialization();
  assert(dictionary->length == 0);
  dictionary_add(dictionary, "key", (void *)'a');
  dictionary_add(dictionary, "key1", (void *)'b');
  dictionary_add(dictionary, "key2", (void *)'c');
  dictionary_add(dictionary, "key3", (void *)'d');
  dictionary_add(dictionary, "key4", (void *)'e');
  dictionary_add(dictionary, "key5", (void *)'f');
  assert(dictionary->length == 6);
  assert(dictionary_get(dictionary, "key")->data == (void *)'a');
  assert(dictionary_get(dictionary, "key1")->data == (void *)'b');
  assert(dictionary_get(dictionary, "key2")->data == (void *)'c');
  assert(dictionary_get(dictionary, "key3")->data == (void *)'d');
  assert(dictionary_get(dictionary, "key4")->data == (void *)'e');
  assert(dictionary_get(dictionary, "key5")->data == (void *)'f');
  dictionary_add(dictionary, "key5", (void *)'a');
  assert(dictionary_get(dictionary, "key5")->data == (void *)'a');
  assert(dictionary_contains_key(dictionary, "key5"));
  assert(!dictionary_contains_key(dictionary, "invalid key"));
  assert(dictionary_contains_key(dictionary, "key5"));
  dictionary_remove(dictionary, "key5");
  assert(dictionary->length == 5);
  assert(!dictionary_contains_key(dictionary, "key5"));
}
