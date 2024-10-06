CC = gcc 
FLAGS = -Wall -Wextra -Werror -g -std=c11 # -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector -fanalyzer
SOURCES = *.c 
OBJECTS = *.o 
TESTS = ./tests/*.c
GCOV_FLAGS= -fprofile-arcs -ftest-coverage
LINK_FLAGS = -lcheck -lpthread -lsubunit -lrt
OS := $(shell uname -s)

ifeq ($(OS), Linux) 
	LINK_FLAGS += -lm -lsubunit
endif

all: clean s21_matrix.a test gcov_report

s21_matrix.a: clean
	$(CC) $(FLAGS) -c $(SOURCES)
	ar rcs s21_matrix.a $(OBJECTS)

test: clean
	$(CC) $(FLAGS) $(LEAKS) $(SOURCES) ${TESTS} ${LINK_FLAGS} -o test
	./test

leaks: test
ifeq ($(OS), Linux) 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
endif
ifeq ($(OS), Darwin) 
	leaks -quiet -atExit -- ./test
endif

clean: 
	rm -fr *.o *.a *.gch *.gcno *.gcda *.info test report unit_test

rebuild: all 

gcov_report: clean
	$(CC) $(FLAGS) $(GCOV_FLAGS) ${SOURCES} ${TESTS} ${LINK_FLAGS} -o test
	./test
	lcov -t "test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open report/index.html	

style:
	clang-format -style=google -n tests/* ./*.c ./*.h
