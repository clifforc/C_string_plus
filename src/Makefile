CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
GFLAGS = -fprofile-arcs -ftest-coverage -fPIC
TEST_FLAGS = -lcheck -lpthread -lm 

RM_EXTS := o a out gcno gcda gcov info html css

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
	TEST_FLAGS += -lrt -lsubunit
	GFLAGS += -lgcov
endif

TARGET = s21_string.a

REPORT_TARGET = "`realpath ./core`/.*\.c"

OBJ_DIR = ./obj/
CORE_DIR = ./core/
TEST_DIR = ./tests_suite/

MAIN_SRC = $(shell find $(CORE_DIR) -name '*.c')
TESTS_SRC = $(shell find $(TEST_DIR) -name '*.c') $(wildcard test.c)

MAIN_OBJS = $(patsubst $(CORE_DIR)%.c, $(OBJ_DIR)%.o, $(MAIN_SRC))
TEST_OBJS = $(patsubst $(TEST_DIR)%.c, $(OBJ_DIR)%.o, $(TESTS_SRC))

MAIN_GCOV = $(patsubst $(CORE_DIR)%.c, $(OBJ_DIR)%_gcov.o, $(MAIN_SRC))
TEST_GCOV = $(patsubst $(TEST_DIR)%.c, $(OBJ_DIR)%_gcov.o, $(TESTS_SRC))

all: $(TARGET)
.PHONY: $(all)

$(TARGET): $(MAIN_OBJS)
	@ar rcs $@ $^
.PHONY: $(TARGET)

# Obj for all
$(OBJ_DIR)%.o: $(CORE_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

test: $(TEST_OBJS) $(TARGET)
	@$(CC) $(CFLAGS) -L. $^ -o tests.out $(TEST_FLAGS)
	@./tests.out $(SUITE)
.PHONY: test

# Obj for test
$(OBJ_DIR)%.o: $(TEST_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Obj for gcov
$(OBJ_DIR)%_gcov.o: $(CORE_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(GFLAGS) -c $< -o $@

$(OBJ_DIR)%_gcov.o: $(TEST_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(GFLAGS) -c $< -o $@

gcov_report: $(MAIN_GCOV)$(TEST_GCOV) $(TARGET)
	@$(CC) $(CFLAGS) $(GFLAGS) -L. $^ -o report.out $(TEST_FLAGS)
	@./report.out
	@find . -name "*.gcno" -exec gcov -f {} \;
	@mkdir -p ./report
	@gcovr -r . -f $(REPORT_TARGET) --html --html-details -o ./report/index.html 
ifeq ($(OS), Linux)
	@xdg-open ./report/index.html
else
	@open ./report/index.html
endif
.PHONY: gcov_report


format-check :
	@cp ../materials/linters/.clang-format ./
	@find ./ -type f -name "*.[ch]" -exec clang-format -n {} \;
	@rm ./.clang-format
.PHONY: format-check

format :
	@cp ../materials/linters/.clang-format ./
	@find ./ -type f -name "*.[ch]" -exec clang-format -i {} \;
	@rm ./.clang-format
.PHONY: format

cppcheck :
	@find ./ -type f -name "*.c" -exec cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction {} \;
.PHONY: cppcheck

leaks : clean test
ifeq ($(OS), Linux)
	@valgrind --quiet --tool=memcheck --leak-check=yes ./tests.out
else
	@leaks -atExit -- ./tests.out | grep LEAK:
endif
.PHONY: leaks

clean:
	@for ext in $(RM_EXTS); do \
		find ./ -type f -name "*.$$ext" -exec rm {} \;; \
	done
	@rm -rf ./report
	@rm -rf ./obj
.PHONY: clean