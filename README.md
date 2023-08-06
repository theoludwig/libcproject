<h1 align="center">libcproject</h1>

<p align="center">
  <strong>C static library easier to use than `libc` (C standard library).</strong>
</p>

<p align="center">
  <a href="./CONTRIBUTING.md"><img src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat" /></a>
  <a href="./LICENSE"><img src="https://img.shields.io/badge/licence-MIT-blue.svg" alt="Licence MIT"/></a>
  <a href="./CODE_OF_CONDUCT.md"><img src="https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg" alt="Contributor Covenant" /></a>
  <br />
  <a href="https://github.com/theoludwig/libcproject/actions/workflows/ci.yml"><img src="https://github.com/theoludwig/libcproject/actions/workflows/ci.yml/badge.svg?branch=develop" /></a>
  <a href="https://conventionalcommits.org"><img src="https://img.shields.io/badge/Conventional%20Commits-1.0.0-yellow.svg" alt="Conventional Commits" /></a>
  <a href="https://github.com/semantic-release/semantic-release"><img src="https://img.shields.io/badge/%20%20%F0%9F%93%A6%F0%9F%9A%80-semantic--release-e10079.svg" alt="semantic-release" /></a>
</p>

## About

**libcproject** is a C static library for learning purposes. It tries to implement useful functions/data structures while being easier to use than `libc` (C standard library) as much as possible.

C is a low-level programming language and we often end up reinventing the wheel as the C standard library (`libc`) is quite small and in my humble opinion, not well designed.

**libcproject** solve this by providing common functions or data structures (`hash_map`, `array_list`, `linked_list`, `queue`, `stack`, etc.), we might need in our C projects.

[Online documentation](https://libcproject.vercel.app/).

## Prerequisites

- [GNU coreutils](https://www.gnu.org/software/coreutils/)
- [GNU binutils](https://www.gnu.org/software/binutils/)
- [GNU gcc](https://gcc.gnu.org/)
- [GNU make](https://www.gnu.org/software/make/)
- [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html)
- [Doxygen](https://www.doxygen.nl/)

For example on GNU/Linux Ubuntu:

```sh
# Install Build Tools
sudo apt-get install build-essential gcc make clang-format

# Install Documentation Tools
sudo apt-get install doxygen doxygen-gui doxygen-doc graphviz
```

## Usage

```sh
make # to compile
make run # to run main
make test # to run unit tests
make lint # to lint the code
make documentation # to generate the documentation
make clean # to clean up

nm ./build/libcproject.a # to see the symbols
```

Steps to create a new C project that uses `libcproject`:

### Step 1: Create a new project

```sh
mkdir my-project
cd my-project
```

### Step 2: Install and Compile `libcproject` in the project

```sh
# Clone the repository
git clone git@github.com:theoludwig/libcproject.git

# Go to libcproject directory
cd libcproject

# Compile the library
make
```

### Step 3: Create a new C file

```sh
cd ..
touch main.c
```

```cpp
#include <stdio.h>
#include <stdlib.h>

#include "libcproject/libcproject.h"

int main() {
  string_t string = "Hello, world!"; // `string_t` is a typedef from `libcproject`
  printf("%s\n", string);
  printf("string_length = %ld\n", string_get_length(string)); // `string_get_length` is a function from `libcproject`
  return EXIT_SUCCESS;
}
```

### Step 4: Compile your project and link it with the library

```sh
gcc -o ./main ./main.c -L. -l:./libcproject/build/libcproject.a
```

## 💡 Contributing

Anyone can help to improve the project, submit a Feature Request, a bug report or even correct a simple spelling mistake.

The steps to contribute can be found in the [CONTRIBUTING.md](./CONTRIBUTING.md) file.

## 📄 License

[MIT](./LICENSE)
