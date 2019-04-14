#include <stdio.h>
#include "data_type.h"

data_t make_data(int id, double weight) {
	data_t d;
	d.id= id;
	d.weight= weight;
	return d;
}

void print_data(data_t *d) {
	printf("(%d,%.0f)", d->id, d->weight);
}

