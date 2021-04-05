/*
 * Racecar module header file.
 *
 * Created for COMP20007 Design of Algorithms 2020
 * Written by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

/*
 * This is the include guard, which ensures these typedefs/prototypes aren't
 * declared multiple times.
 */
#ifndef RACECAR_H
#define RACECAR_H

/* Represents a racecar with information about its driver, team and laps. */
typedef struct racecar Racecar;

/* Creates a new racecar, must be freed using free_racecar. */
Racecar *new_racecar(char *driver, char *team);
/* Frees the memory associated with a racecar. */
void free_racecar(Racecar *racecar);

/* Add a lap time to the given racecar. */
void add_lap(Racecar *racecar, double lap);
/* Retrieve the fastest lap time for the given racecar. */
double fastest_lap(Racecar *racecar);
/* Retrieve the total time taken for all laps for the given racecar. */
double total_time(Racecar *racecar);
/* Print racecar info in the format: Driver (Team) -  N laps */
void print_racecar_info(Racecar *racecar);

#endif
