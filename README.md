# libcproject

## About

`libcproject` is a C static library for learning purposes. It tries to implement useful functions/data structures while being easier to use than `libc` (C standard library) as much as possible.

## Prerequisites

- [GNU coreutils](https://www.gnu.org/software/coreutils/)
- [GNU binutils](https://www.gnu.org/software/binutils/)
- [GNU gcc](https://gcc.gnu.org/)
- [GNU make](https://www.gnu.org/software/make/)
- [clang-format](https://clang.llvm.org/docs/ClangFormat.html)

For example on GNU/Linux Ubuntu:

```sh
sudo apt-get install build-essential gcc make clang-format
```

## Usage

Steps to create a new C project that uses `libcproject`:

### Step 1: Compile `libcproject`

```sh
make
```

### Step 2: Create a new project

```sh
mkdir my-project
cd my-project
```

### Step 3: Install `libcproject` in the project

```sh
mkdir libcproject
cp --recursive <path-to-libcproject> ./ # copy
# or
ln -s <path-to-libcproject> ./ # symbolic link
```

### Step 4: Create a new C file

```sh
touch main.c
```

```cpp
#include <stdio.h>
#include <stdlib.h>

#include "libcproject/libcproject.h"

int main() {
  char* string = "Hello, world!";
  printf("%s\n", string);
  printf("string_length = %ld\n", string_get_length(string)); // `string_get_length` is a function from `libcproject`
  return EXIT_SUCCESS;
}
```

### Step 5: Compile your project and link it with the library

```sh
gcc -o ./main.exe ./main.c -L. -l:./libcproject/build/libcproject.a
```

## Contributing

```sh
make # to compile
make run # to run main
make test # to run unit tests
make lint # to lint the code
make clean # to clean up

nm ./build/libcproject.a # to see the symbols
```
