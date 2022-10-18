####=============================================================================####
####                 School 21 / NSK campus. Project C4: s21_math                ####
####^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^####
####                    Copyright (C) 2022 Team "FastFive"   {                   ####
####                        reelydoi@student.21-school.ru  &                     ####
####                        mortylar@student.21-school.ru  &                     ####
####                        artanisv@student.21-school.ru  &                     ####
####                        galaxiae@student.21-school.ru  &                     ####
####                        heidylaw@student.21-school.ru    }                   ####
####^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^####
####               /* Makefile v.0.6_a RTM, written by reelydoi */               ####
####=============================================================================####

# --------------------------------------------------------------------------------- #
#   List of targets:                                                                #
#       all                                                                         #
#       s21_math.a      (build static lib)                                          #
#       gcov_report     (build project with gcov info, create & open report)        #
#       test            (build && run tests)                                        #
#       check           (tests, cpplint, cppcheck, leaks||valgrind)                 #
#   srv:                                                                            #
#       clean           (maintain sanitary discipline)                              #
#       rebuild         (clean -> all)                                              #
#       backup          (backup for .c, .h, .check & .md files to ../../$PN/$VER)   #
#       restore         (restore any version of codebase)                           #
#       vlist           (see list local backups of project)                         #
# --------------------------------------------------------------------------------- #

# -------------------------------- DEFINED VALUES --------------------------------- #
PROJECT:=s21_math
CODE=c
OpenReportOnExitGCOV=YES
SILENT_STDOUT=NO
# ---------------------------------- VARIABLES ------------------------------------ #
PRJPREFX=s21_
OUT:=$(PROJECT).a
SOURCE:=$(wildcard s21*.c)
HEADERS:=$(wildcard s21*.h)
SRCOBJ=$(wildcard s21*.o)
TEST:=c4test
TESTELF:=$(TEST)
TSTSRC:=$(TEST).c
TSTOBJ:=$(patsubst %.c,%.o, ${TSTSRC})

ifeq ($(shell grep -Ew 'ID=alpine' /etc/os-release),ID=alpine)
VER=Verter
else
VER=0.9rc1
# VER=DEBUG
# VER=Verter
endif

OS:=$(shell uname -s)
ifeq ($(OS),Darwin)
COVER=--coverage
BREW:= ${HOME}/homebrew
WEB:=open
LEAKS:=CK_FORK=no leaks -atExit --
DBGFLAGS=-ggdb -fsanitize=address -fno-omit-frame-pointer -static-libgcc -g -fstack-protector
else
COVER=-fprofile-arcs -ftest-coverage
BREW= .`
WEB:=xdg-open
LEAKS=valgrind --leak-check=full --quiet
DBGFLAGS=-g -fstack-protector -ggdb -fsanitize=address -fno-omit-frame-pointer -static-libasan
TFLAGS:=-lcheck -lm -lrt -lpthread -lsubunit 
endif
PATH:= $(PATH):$(BREW)/bin

ifeq ($(VER),Verter)
CFLAGS=
else 
ifneq ($(VER),DEBUG)
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic -fstack-protector -fstack-clash-protection -Wformat=2 -O2 -march=native
else
STDFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic -O1 -march=native
SAVBIN=-save-temps
CFLAGS=${DBGFLAGS} ${SAVBIN} ${STDFLAGS}
endif
endif
REPORTDIR=report

ifeq ($(CODE), cpp)
CC:=g++
else
CC:=gcc
endif

# ------------------------------- MAKE CONFIGURATION ------------------------------ #
ifeq ($(SILENT_STDOUT), YES)
.SILENT: all clean test check ${SRCOBJ} ${OUT} ${TESTELF} ${TSTOBJ} ${TESTELF}_gcov.o ${PROJECT}_gcov.a gcov_report s21_test.o
endif
# .PHONY: all .PHONY: rebuild clean
# ------------------------------------ TAGRETS ------------------------------------ #

## ............................ ! TARGET s21_math.a ! ............................ ##
s21_math.a: s21_math.o
ifneq ($(SILENT_STDOUT), YES)
	@echo ">>>> Target '$@':\n\tExecuting main target..."
	@echo "Build configuration/version: $(VER)"
endif
	ar rcs $(OUT) s21_math.o
	ranlib $(OUT)
ifneq ($(SILENT_STDOUT), YES)
	@echo ">>>> Target '$@' done.\n"
endif

## ............................ ! TARGET s21_math.o ! ............................ ##
s21_math.o: ${SOURCE}
ifeq ($(SILENT_STDOUT), YES)
	@echo ">>> Target '$@'\n\tBuild object file for: $(SOURCE); and headers: $(HEADERS)..."
endif
	${CC} ${CFLAGS} -c ${SOURCE}
ifeq ($(SILENT_STDOUT), YES)
	@echo ">>> Target '$@' done.\n"
endif

## ............................... ! TARGET all ! ................................ ##
all: clean s21_math.a test gcov_report check

## ............................... ! TARGET style ! .............................. ##
style:
ifeq ($(shell which clang-format),)
	@echo "clang-format not found. Now it will be installed. Please, write user password and press Enter."
	@sleep 2
#	brew install clang-format
	sudo apt install clang-format --yes
endif
ifneq ($(shell which clang-format),)
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.c *.h
	sleep 0.5
	clang-format -i *.c *.h
	rm .clang-format
endif

## ............................... ! TARGET test ! ............................... ##
test: clean s21_math.a s21_test.o
ifneq ($(SILENT_STDOUT), YES)
	@echo ">>>> Target '$@': Unit tests build & run..."
endif
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(TSTOBJ) $(OUT) -lcheck -o $(TEST)
	./$(TEST)
else
	$(CC) $(CFLAGS) $(TSTOBJ) $(OUT) $(TFLAGS) -o $(TEST)
	./$(TEST)
endif
ifneq ($(SILENT_STDOUT), YES)
	@echo ">>>> Target '$@' done.\n"
endif

build_test_src:
	cat -s $(wildcard *.test) > tmp.check
	checkmk tmp.check > $(TSTSRC)

s21_test.o: build_test_src
	$(CC) -c $(TSTSRC) -o $(TSTOBJ)

## ............................. ! TARGET rebuild ! .............................. ##
rebuild: clean s21_math.a

## .............................. ! TARGET backup ! .............................. ##
backup: clean
ifneq ($(SILENT_STDOUT), YES)
	@echo "> Target '$@':\n\tRun as sudo make backup. Make backup for code, headers, tests, Makefile's and .md docs..."
endif
	mkdir -p ../../proj_backups/$(PROJECT)_bak/$(VER)
	cp --backup=existing *.c *.h ../../proj_backups/$(PROJECT)_bak/$(VER)
	cp Makefile* ../../proj_backups/$(PROJECT)_bak/$(VER)/
ifneq ("","$(wildcard ./*.md)")
	cp --backup=existing *.md ../../proj_backups/$(PROJECT)_bak/$(VER)
endif
ifneq ("","$(wildcard ./*.check)")
	cp --backup=existing *.check ../../proj_backups/$(PROJECT)_bak/$(VER)
endif
ifneq ($(SILENT_STDOUT), YES)
	@echo "> Target '$@' done.\n"
endif

## ............................... ! TARGET vlist ! .............................. ##
#list of existing backups
vlist:
	ls ../../proj_backups/$(PROJECT)_bak/

## .............................. ! TARGET restore ! ............................. ##
# Для восстановления файлов нужной версии нужно выставить запрашиваемую для 
# восстановления версию сборки в переменную VER. Посмотреть доступные к восстановлению  
# можно выполнением команды make vlist
# !!! ТЕКУЩИЕ ФАЙЛЫ ПРОЕКТА БУДУТ УДАЛЕНЫ !!!
restore: clean
	@echo "> Target '$@':\n\tRestore all files for ../../../$(PROJECT)_bak/$(VER)."
ifeq ("","$(wildcard ../../proj_backups/$(PROJECT)_bak/)")
	@echo "> Cannot restore files. Not found folder ../../proj_backups/$(PROJECT)_bak/$(VER).\n"
else
ifneq ("","$(wildcard s21*.c s21*.h)") 
	@echo "\n!!! Actual files ($(wildcard s21*.c s21*.h)) will be removed !!!!\n"
	@echo "!!! Press <Ctrl> + <Z> for cancel. 5 sec remaining !!!"
	@sleep 6
	rm s21*.c s21*.h
	@echo "Files for recover: $(shell ls ../../proj_backups/$(PROJECT)_bak/$(VER)/)"
endif
	cp --backup=existing ../../proj_backups/$(PROJECT)_bak/$(VER)/* ./
	@echo "Files for v. $(VER) is recover."
endif
	@echo "> Target '$@' done.\n"

## .............................. ! TARGET clean ! ............................... ##
clean:
ifneq ($(SILENT_STDOUT), YES)
	@echo ">>>> Target '$@'\n\tCleaning temporary and unnecessary files"
endif
	rm -f *.o $(TESTELF) $(OUT) $(TESTELF)_gcov gcov_report *.out *.gcov *.gcda *.gcno *.info *.a *.i *.s CPPLINT.cfg
	rm -rf ./$(REPORTDIR) ./objs
	rm -f $(TSTSRC) tmp.check
ifneq ($(SILENT_STDOUT), YES)
	@echo ">> Target '$@' (cleaning temporary and unnecessary files) - done."
endif

## .............................. ! TARGET check ! ............................... ##
check: test
ifneq ($(SILENT_STDOUT), YES)
	@echo ">>>> Target '$@'\n\tStatic code analysis, checking of style norm and memory leaks"
endif
	cppcheck --suppress=missingIncludeSystem $(SOURCE) ${HEADERS}
	rm -f $(TSTSRC) *.check
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c ${HEADERS}
#	rm -f .clang-format
ifeq ("","$(wildcard ./$(TESTELF))")
	@echo "ELF '$(TESTELF)' not found. Memory leak check failed!"
else
	./$(TESTELF)
endif
ifneq ($(SILENT_STDOUT), YES)
	@echo ">>>> Target '$@' done."
endif

## ........................... ! TARGET gcov_report ! ............................ ##
gcov_report: clean s21_math_gcov.o c4test_gcov.o
ifeq ($(OS), Darwin)
	WEB=open
	$(CC) -fprofile-arcs -ftest-coverage -lcheck s21_math_gcov.o $(TESTELF)_gcov.o -o $(TESTELF)_gcov
else
	WEB=xdg-open
	$(CC) s21_math_gcov.o $(TESTELF)_gcov.o -fprofile-arcs -ftest-coverage $(TFLAGS) -o $(TESTELF)_gcov
endif
	./$(TESTELF)_gcov
	gcov s21_math_gcov
	gcov $(TESTELF)_gcov
	lcov -t "s21_math" -o s21_math.info -c -d .
	genhtml -o $(REPORTDIR) s21_math.info
ifeq ($(OpenReportOnExitGCOV), YES)
	${WEB} ./$(REPORTDIR)/index.html
endif

c4test_gcov.o: build_test_src
	$(CC) -fprofile-arcs -ftest-coverage -c $(TSTSRC) -o $(TESTELF)_gcov.o

s21_math_gcov.o: s21_math.c
	$(CC) -fprofile-arcs -ftest-coverage -c s21_math.c -o s21_math_gcov.o 

#### ............................ ! Makefile END ! ............................. ####
