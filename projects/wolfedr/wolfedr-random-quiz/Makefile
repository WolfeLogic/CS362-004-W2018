CFLAGS = -Wall -fpic -coverage -lm

testme:
	gcc -o testme -g testme.c  $(CFLAGS)
	./testme

all: testme

clean:
	rm testme *.gcov *.gcda *.gcno