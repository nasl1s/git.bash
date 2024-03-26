# VARIABLES
NAME := quadratic_equation.a
EXECNAME := 

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Werror
GCOVFLAGS := -fprofile-arcs -ftest-coverage -g
LDFLAGS := -lm -lcheck
SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

UNAME := $(shell uname -s)

# OS CHECK
# Check the operating system to set specific flags and libraries
ifeq ($(UNAME),Linux)
	LDFLAGS += -lrt -lpthread -lsubunit 
	OPEN=xdg-open
endif
ifeq ($(UNAME),Darwin)
	OPEN=open
endif

# TARGETS 
# Default target - compile the library
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	rm -rf *.o
	ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

# Target for running unit tests
check: unittests $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) unittests.c $(LDFLAGS) -o unittests.out -lm
	rm -rf *.o
	./unittests.out

# Target for running unit tests with Valgrind
valgrind: unittests
	$(CC) $(CFLAGS) -g $(SOURCES) unittests.c $(LDFLAGS) -o unittests.out -lm
	rm -rf *.o
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./unittests.out

rebuild: clean all

# Target to clean up generated files
clean:
	rm -rf *.o *.a *.out unittests.c unit_tests/_unittests.check

# INCLUDE 
# Include the generated check.mk file 
include check.mk

# EXTRAS
# Additional phony targets
.PHONY: all test clean rebuild gcov_report clang-format

# Target to format code using clang-format
clang-format:
	clang-format -i -style=Google *.h *.c