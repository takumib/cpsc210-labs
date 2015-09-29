CC = gcc
CFLAGS = -std=c99
SRC = test.c list.c iterator.c
SRC_MAIN = main.c list.c iterator.c

all:
	$(CC) $(CFLAGS) $(SRC) -o lab6_test
	$(CC) $(CFLAGS) $(SRC_MAIN) -o lab6

run:
	./lab6

test:
	-@./lab6_test || true

clean:
	rm -f *.o lab6 lab6_test *.tar *.tar.gz

handin:
	tar czvf lab6_handin.tar.gz test.c main.c list.c list.h \
		iterator.c iterator.h Makefile
