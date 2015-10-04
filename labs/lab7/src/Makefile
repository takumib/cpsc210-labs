# Makefile for lab 7

OBJS = matrixtest.o matrix.o

CFLAGS = -g -Wall

lab7: ${OBJS}
	@echo
	@echo Linking program $@
	gcc -o $@ ${OBJS}

${OBJS}: matrix.h Makefile

clean:
	rm -f *.o *.gch lab7
