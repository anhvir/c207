/*
 * Racecar module testing program.
 *
 * Created for COMP20007 Design of Algorithms 2020
 * Written by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

#include <stdio.h>

/* Include the racecar module. */
#include "racecar.h"

/*
 * The main function creates two racecars and tests the functions which are
 * exposed through racecar.h.
 */
int main(int argc, char **argv) {
  Racecar *renault = new_racecar("Daniel Ricciardo", "Renault");
  add_lap(renault, 73.23);
  add_lap(renault, 71.05);
  add_lap(renault, 75.27);
  add_lap(renault, 68.84);

  print_racecar_info(renault);
  printf("Fastest Lap: %.2lf\n", fastest_lap(renault));

  Racecar *ferrari = new_racecar("Sebastian Vettel", "Ferrari");
  add_lap(ferrari, 77.23);
  add_lap(ferrari, 75.97);
  add_lap(ferrari, 71.10);

  print_racecar_info(ferrari);
  printf("Total Time: %.2lf\n", total_time(ferrari));

  free_racecar(renault);
  renault = NULL;
  free_racecar(ferrari);
  ferrari = NULL;

  return 0;
}
