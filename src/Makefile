GCC = gcc
FLAG_GCOV = --coverage
FLAGS = -Wall -Werror -Wextra -std=c11
TESTFILE = test/s21_matrix
TEST_LIB = s21_matrix

PATH_PROJECT = $(shell pwd)
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBS_OS_CHECK = -lcheck -lsubunit -lm -lpthread -lrt
	DEVELOP = -fsanitize=address s21_matrix.a -lm
	OSLINUX = 1
else
	LIBS_OS_CHECK = -lcheck -lm -lpthread
	DEVELOP = -fsanitize=address s21_matrix.a
	OSLINUX = 0
endif

all: clean gcov_report

s21_matrix.a:
	$(GCC) $(FLAGS) -c s21_*.c 
	ar rc s21_matrix.a s21_*.o
	ranlib s21_matrix.a

test: clean
	$(GCC) $(FLAGS) -c $(FLAG_GCOV) s21_*.c 
	ar rc s21_matrix.a s21_*.o
	ranlib s21_matrix.a
	bash test/check_test.sh $(GCC) "$(FLAGS)" $(TEST_LIB) "$(LIBS_OS_CHECK)" $(FLAG_GCOV)

leak_test: clean
	$(GCC) $(FLAGS) -c $(FLAG_GCOV) s21_*.c 
	ar rc s21_matrix.a s21_*.o
	ranlib s21_matrix.a
	bash test/leaks_test.sh $(GCC) "$(FLAGS)" $(TEST_LIB) "$(LIBS_OS_CHECK)" $(FLAG_GCOV) "$(OSLINUX)"

gcov_report: test
	bash test/gcov_print.sh
	gcov s21_*.gcda	
	lcov -t "s21_matrix" -o $(TESTFILE).info -c -d .
	genhtml -o report $(TESTFILE).info

open:
	open $(PATH_PROJECT)/report/index.html

check:
	clang-format -n --style=Google *.h *.c
	clang-format -n --style=Google test/*.check
	-rm -rf .clang-format
	-rm -rf test/.clang-format

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt a.out.dSYM tests main 
	-rm -rf test/*.gcda test/*.info test/*.gcno test/*.c test/*.o
	-rm -rf report

dev: clean s21_matrix.a
	$(GCC) $(FLAGS) -c main.c -fsanitize=address -g
	$(GCC) $(FLAGS) main.c -o main $(DEVELOP)
	clear
	./main


