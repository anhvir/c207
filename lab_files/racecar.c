/*
 * Racecar module implementation.
 *
 * Created for COMP20007 Design of Algorithms 2020
 * Written by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Note that we need to include the .h file within the .c file as well. */
#include "racecar.h"

#define INITIAL_CAPACITY 4
#define SCALING_FACTOR   2

struct racecar {
  char *driver;
  char *team;
  double *laps;
  size_t n_laps;
  size_t laps_capacity;
};

/*
 * Prints a given error to stderr and exits the program with the EXIT_FAILURE
 * status code.
 *
 * NOTE: Not exposed via racecar.h, thus this can only be used within this file.
 */
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
