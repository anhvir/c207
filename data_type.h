#ifndef _DATA_TYPES_H_
#define _DATA_TYPES_H_


/* A data_t element is a pair (id, weight)
   Examples of using data_t include:
     - element of adjacency lists of a weighted graph, where
         "id" is vertex id, and "weight" is the edge weight
     - element of priorty queue
*/ 
typedef struct {
	int id;
	double weight;
} data_t;

data_t make_data(int id, double weight);
void print_data(data_t *d);


#endif
