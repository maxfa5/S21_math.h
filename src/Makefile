CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRC = s21_*.c
OBJ = s21_*.o
LIB = s21_math.a
LIBSFLAGS = -lcheck -lsubunit -lrt -lpthread -lm -lgcov
TEST_SRC = s21t_*.c
GCOV_FLAGS = -fprofile-arcs -ftest-coverage  --coverage
GCOVR_PATH =~/.local/bin/gcovr
REPORT = ./report/index.html

s21_math.a:
	gcc -c $(SRC)
	ar rc s21_math.a *.o
	ranlib s21_math.a 
	rm -rf *.o

all: clean s21_math.a

clang:
	clang-format -n *.c *.h

test: clean ${LIB}
	$(CC) $(CFLAGS) s21_math.a $(GCOV_FLAGS) $(SRC) ${TEST_SRC} -o test $(LIBSFLAGS)
	./test
	rm -rf test

gcov_report: clean test
	mkdir report
	${GCOVR_PATH} -r . --html --html-details -o $(REPORT) -es21t_math.c
	xdg-open $(REPORT)

clean:
	rm -rf a.out
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda *.gcdo *.gcov *.css *.html *.gcno
	rm -rf report

r: clean s21_math.a s21_math test
