CC= gcc
CFLAGS= -Wall -g
EXE= race
LIB= 

EXE1= problem1a
SRC1= problem1a.c utils.c leap.c
OBJ1= $(SRC1:.c=.o)
HDR= leap.h utils.h

EXE2= problem1b
SRC2= problem1b.c utils.c leap.c
OBJ2= $(SRC2:.c=.o)

all: $(EXE1) $(EXE2)

$(EXE1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJ1) $(LIB)

$(EXE2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(EXE2) $(OBJ2) $(LIB)

clean:
	rm $(EXE1) $(EXE2) *.o
