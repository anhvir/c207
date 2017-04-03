# Makefile 
# Andrew Turpin
# April 2013

OBJ  = main.o heap.o 
SRC  = main.c heap.c 
EXE  = testHeap

CC     = gcc 
CFLAGS = -Wall -O2

testHeap:   $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

clean:
	rm -f $(OBJ) $(EXE)

heap.o: heap.c heap.h Makefile
main.o: main.c heap.h Makefile
