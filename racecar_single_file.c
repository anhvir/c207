/*
 * A single program for racecar
 * WHAT TO DO: turn this program into module
               then compare your solution with the provided {racecar.c, racecar.h, racecar_test.compare}
 *
 * Created for COMP20007 Design of Algorithms 2020
 * Written by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * 20220313 - Updated driver teams by Grady Fitzpatrick <grady.fitzpatrick@unimelb.edu.au>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define INITIAL_CAPACITY 4
#define SCALING_FACTOR   2

/* Represents a racecar with information about its driver, team and laps. */
typedef struct racecar Racecar;
struct racecar {
  char *driver;
  char *team;
  double *laps;
  size_t n_laps;
  size_t laps_capacity;
};


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



/*
 * The main function creates two racecars and tests the functions which are
 * exposed through racecar.h.
 */
int main(int argc, char **argv) {
  Racecar *mcclaren = new_racecar("Daniel Ricciardo", "McClaren");
  add_lap(mcclaren, 73.23);
  add_lap(mcclaren, 71.05);
  add_lap(mcclaren, 75.27);
  add_lap(mcclaren, 68.84);

  print_racecar_info(mcclaren);
  printf("Fastest Lap: %.2lf\n", fastest_lap(mcclaren));

  Racecar *aston_martin = new_racecar("Sebastian Vettel", "Aston Martin");
  add_lap(aston_martin, 77.23);
  add_lap(aston_martin, 75.97);
  add_lap(aston_martin, 71.10);

  print_racecar_info(aston_martin);
  printf("Total Time: %.2lf\n", total_time(aston_martin));

  free_racecar(mcclaren);
  mcclaren = NULL;
  free_racecar(aston_martin);
  aston_martin = NULL;

  return 0;
}

void print_error(char *error);

/* Creates a new racecar, must be freed using free_racecar. */
Racecar *new_racecar(char *driver, char *team) {
    Racecar *racecar = malloc(sizeof(Racecar));
    assert(racecar);

    if (!driver || !team) {
      print_error("driver and team must not be NULL");
    }

    racecar->driver = strdup(driver);
    racecar->team = strdup(team);

    racecar->n_laps = 0;
    racecar->laps_capacity = INITIAL_CAPACITY;
    racecar->laps = malloc(racecar->laps_capacity * sizeof(double));
    assert(racecar->laps);

    return racecar;
}

/* Frees the memory associated with a racecar. */
void free_racecar(Racecar *racecar) {
  free(racecar->driver);
  free(racecar->team);
  free(racecar->laps);
  free(racecar);
}

/* Add a lap time to the given racecar. */
void add_lap(Racecar *racecar, double lap) {
  /* If we have already reached the capacity of the laps array we will
   * double the size using realloc. */
  if (racecar->n_laps == racecar->laps_capacity) {
    racecar->laps_capacity *= SCALING_FACTOR;
    racecar->laps = realloc(racecar->laps,
                            racecar->laps_capacity * sizeof(double));
    assert(racecar->laps);
  }

  racecar->laps[racecar->n_laps] = lap;
  racecar->n_laps++;
}

/* Retrieve the fastest lap time for the given racecar. */
double fastest_lap(Racecar *racecar) {
  int i;
  double min;

  if (racecar->n_laps == 0) {
    print_error("racecar hasn't completed any laps");
  }

  min = racecar->laps[0];
  for (i = 1; i < racecar->n_laps; i++) {
    if (racecar->laps[i] < min) {
      min = racecar->laps[i];
    }
  }

  return min;
}

/* Retrieve the total time taken for all laps for the given racecar. */
double total_time(Racecar *racecar) {
  int i;
  double sum = 0;

  for (i = 0; i < racecar->n_laps; i++) {
     sum += racecar->laps[i];
  }

  return sum;
}

/* Print racecar info in the format: Driver (Team) -  N laps */
void print_racecar_info(Racecar *racecar) {
  /* zu is the format specifier for size_t */
  printf(
    "%s (%s) - %2zu laps\n",
    racecar->driver,
    racecar->team,
    racecar->n_laps
  );
}



/*
 * Prints a given error to stderr and exits the program with the EXIT_FAILURE
 * status code.
 *
 * NOTE: Not exposed via racecar.h, thus this can only be used within this file.
 */
void print_error(char *error) {
  fprintf(stderr, "Error: %s\n", error);
  exit(EXIT_FAILURE);
}

