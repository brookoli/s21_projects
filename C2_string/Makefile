CC=gcc
FLAGS=-Wall -Wextra -Werror
ROAD=.
TESTNAME=main.c
FILENAME=a.out
FILENAME2=TEST2_FILE
GCOV= --coverage
OS=$(shell uname)
CHECKFLAGS=`pkg-config --cflags --libs check`
ifeq ($(OS), Linux)
  LIBS=-lcheck -lpthread -lrt -lm -lsubunit
  OPEN=xdg-open
else
  LIBS=-lcheck
  OPEN=open
endif


all: main.c s21_string.a test gcov_report


test:  s21_string.a s21_string.h
	$(CC) $(FLAGS) $(TESTNAME) -g -L . s21_string.a $(LIBS) -o $(FILENAME)

gcov_report: main.c s21_string.c s21_string.h
	gcc $(CFLAGS) $(GCOV) -g $(TESTNAME) s21_string.c -o test.out -std=c11 $(CHECKFLAGS)
	./test.out
	lcov -t "s21_string" -o s21_string.info -c -d .
	genhtml -o report s21_string.info
	gcov s21_string.info -f

s21_string.a: s21_string.o
	ar -rcs s21_string.a s21_string.o

s21_string.o: s21_string.c s21_string.h
	gcc -c s21_string.c -o s21_string.o

clean:
	rm -rf *.dSYM *.out *.gcda *.gcno *.info *.gcov *.a *.o *FILE report

run:
	$(ROAD)/$(FILENAME)

debug:
	$(CC) -g 3.c s21_string.c -o $(FILENAME2)

style:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

leaks:
	leaks -atExit -- $(ROAD)/$(FILENAME)

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

val: 3.c s21_string.c s21_string.h
	$(CC) $(FLAGS) -g 3.c s21_string.c -o a.out

gr:
	valgrind --log-file="v_report" --tool=memcheck --track-origins=yes -v ./a.out
