/*  Module: graph
	Dependencies: priorityqueue , data_type

	Simple implementation of graph
	Input graph has a format as in graph_data.txt, which is sequence of:
	    name1  name2 weight
    where name? is a single-word name (such as Melbourne)
	      weight is weight/distance (of "double" type)

	Created by Anh Vo, anhvir@gmail.com, for comp20007_2018s1 week 7
*/


#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "list2.h"  		 // for adjacency lists of graph


#define INIT_DEGREE 2
#define MAX_NAME_LEN 30         // ..of vertex name
#define NOT_FOUND -1

typedef struct {
	char name[MAX_NAME_LEN+1];	// vertex name
	List *A;					// adjacency list
	int ni;						// num of incidents
} vertex_t;

typedef struct {
	vertex_t *vs; 				// vertices
	int n;						// num of vetrices
	int m;						// num of edges
	int maxn;					// current capacity of vs[]
} graph_t; 


graph_t *new_graph();           // return new empty graph
void free_graph(graph_t *g);  
void read_graph(graph_t *g);   // read graph from stdin
void print_graph(graph_t *g);  // read graph from stdin

int vname2id(char *name, graph_t *g);   // return vertex id given name
int add_vertex(char *name, graph_t *g); // add vertex, return id

// add edge (uname,vname, weight) to graph
void add_edge(char *uname, char *vname, double weight, graph_t *g);
                                      
// Print out the shortest paths from the source node to each other node
void dijkstras(graph_t *g, int source);

#endif
