LIBRARY_NAME = libcproject
CC = gcc
CC_FLAGS = -Wall -Wextra -Wfloat-equal -Wundef -Werror -std=c17 -pedantic -pedantic-errors -I./
LIB_CC_FLAGS = -L. -l:./build/${LIBRARY_NAME}.a
LIB_SOURCES = $(wildcard lib/*.c)
TEST_SOURCES = $(wildcard test/*.c)
HEADER_FILES = $(wildcard lib/*.h) $(wildcard test/*.h) ./${LIBRARY_NAME}.h
MAIN_EXECUTABLE = bin/main.exe
TEST_EXECUTABLE = bin/test.exe

.PHONY: all
all: ${LIB_SOURCES}
	mkdir --parents ./build
	${CC} ${CC_FLAGS} -c ${LIB_SOURCES}
	rm --force ./build/${LIBRARY_NAME}.a
	ar -rcs ./build/${LIBRARY_NAME}.a *.o
	rm --recursive --force *.o

.PHONY: run
run: all ./main.c
	mkdir --parents ./bin
	${CC} ${CC_FLAGS} -o ${MAIN_EXECUTABLE} ./main.c ${LIB_CC_FLAGS}
	./${MAIN_EXECUTABLE} ${ARGS}

.PHONY: test
test: all	 ${TEST_SOURCES}
	mkdir --parents ./bin
	${CC} ${CC_FLAGS} -o ${TEST_EXECUTABLE} ${TEST_SOURCES} ${LIB_CC_FLAGS}
	./${TEST_EXECUTABLE}

.PHONY: lint
lint:
	clang-format --Werror --dry-run ${LIB_SOURCES} ${TEST_SOURCES} ${HEADER_FILES} ./main.c

.PHONY: clean
clean:
	rm --recursive --force ./build ./bin *.out *.o *.exe *.a
