CC = gcc
CFLAGS = -std=c99
SRC = listtest.c list.c iterator.c

all:
	$(CC) $(CFLAGS) $(SRC) -o lab6

run:
	./lab6

clean:
	rm -f *.o lab6 lab6_test *.tar *.tar.gz

handin:
	tar czvf lab6_handin.tar.gz listtest.c list.c list.h \
		iterator.c iterator.h Makefile
