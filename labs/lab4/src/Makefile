# Makefile for lab 4

OBJS = vectortest.o vector.o

CFLAGS = -g -Wall

TARGET = lab4

lab5: ${OBJS}
	@echo
	@echo Linking program $(TARGET)
	gcc -o $(TARGET) ${OBJS}

${OBJS}: vector.h Makefile

clean:
	rm -f *.o *.gch lab4
