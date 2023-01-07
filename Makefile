LIBRARY_NAME = libcproject
CC = gcc
CC_FLAGS = -Wall -Wextra -Wfloat-equal -Wundef -Werror -std=c17 -pedantic -pedantic-errors -I./
LIB = ./build/${LIBRARY_NAME}.a
LIB_CC_FLAGS = -L. -l:${LIB}
LIB_SOURCES = $(wildcard lib/*.c)
LIB_OBJECTS = $(patsubst %.c, %.o, $(LIB_SOURCES))
TEST_SOURCES = $(wildcard test/*.c)
TEST_OBJECTS = $(patsubst %.c, %.o, $(TEST_SOURCES))
HEADER_FILES = $(wildcard lib/*.h) $(wildcard test/*.h) ./${LIBRARY_NAME}.h
MAIN_EXECUTABLE = bin/main.exe
SET_VERSION_EXECUTABLE = bin/set_version.exe
TEST_EXECUTABLE = bin/test.exe

${LIB}: $(addprefix build/, ${LIB_OBJECTS})
	rm --force ${LIB}
	ar -rcs ${LIB} $(addprefix build/, ${LIB_OBJECTS})

build/lib:
	mkdir --parents ./build/lib

build/test:
	mkdir --parents ./build/test

build/lib/%.o: lib/%.c ${HEADER_FILES} | build/lib
	${CC} ${CC_FLAGS} -c $< -o $@

build/test/%.o: test/%.c ${HEADER_FILES} | build/test
	${CC} ${CC_FLAGS} -c $< -o $@

.PHONY: run
run: ${LIB} ./main.c
	mkdir --parents ./bin
	${CC} ${CC_FLAGS} -o ${MAIN_EXECUTABLE} ./main.c ${LIB_CC_FLAGS}
	./${MAIN_EXECUTABLE} ${ARGS}

.PHONY: set_version
set_version: ${LIB} ./set_version.c
	mkdir --parents ./bin
	${CC} ${CC_FLAGS} -o ${SET_VERSION_EXECUTABLE} ./set_version.c ${LIB_CC_FLAGS}

.PHONY: test
test: ${LIB} $(addprefix build/, ${TEST_OBJECTS})
	mkdir --parents ./bin
	${CC} ${CC_FLAGS} -o ${TEST_EXECUTABLE} $(addprefix build/, ${TEST_OBJECTS}) ${LIB_CC_FLAGS}
	./${TEST_EXECUTABLE} ${ARGS}

.PHONY: lint
lint:
	clang-format --Werror --dry-run ${LIB_SOURCES} ${TEST_SOURCES} ${HEADER_FILES} ./main.c

.PHONY: documentation
documentation:
	doxygen ./Doxyfile

.PHONY: clean
clean:
	rm --recursive --force ./build ./bin ./documentation
