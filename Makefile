
CC     = gcc 
CFLAGS = -Wall -std=c99
EXE    = dijkstra
OBJ    = list2.o main.o data_type.o graph.o priorityqueue.o

# Default Target, so "$ make" or "$ make all" will do this
all: $(EXE)

# Create the executable
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

# Other Dependencies
list2.o: list2.h list2.c data_type.h 
	$(CC) $(CFLAGS) -c list2.c
data_type.o: data_type.h data_type.c
	$(CC) $(CFLAGS) -c data_type.c
graph.o: graph.h graph.c
	$(CC) $(CFLAGS) -c graph.c
main.o: data_type.h main.c
	$(CC) $(CFLAGS) -c main.c
priorityqueue.o: priorityqueue.h priorityqueue.c
	$(CC) $(CFLAGS) -c priorityqueue.c

# TODO: Add any other dependencies you may create

# "clean" and "all" don't actually create files called "clean" and "all"
# and are thus "Phony Targets"
.PHONY: clean submit all

# Run "$ make clean" to remove the object and executable files
clean:
	rm -f $(OBJ) $(EXE)

