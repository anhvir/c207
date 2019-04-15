/*  Module: graph
	Dependencies: priorityqueue , data_type

	Simple implementation of graph
	Input graph has a format as in graph_data.txt, which is sequence of:
	    name1  name2 weight
    where name? is a single-word name (such as Melbourne)
	      weight is weight/distance (of "double" type)

	Created by Anh Vo, anhvir@gmail.com, for comp20007_2018s1 week 7
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "graph.h"
#include "priorityqueue.h"
	
graph_t *new_graph() {
	graph_t *g= malloc(sizeof(*g));
	assert(g);
	g->n= g->m= 0;
	g->vs= malloc(sizeof( *(g->vs) ) * INIT_DEGREE);
	assert(g->vs);
	g->maxn= INIT_DEGREE;
	
	return g;
}


//  given vertex name, returns vertex id or NOT_FOUND    
int vname2id(char *name, graph_t *g) {
	int i;
	// return id if the vertex exist
	for (i=0; i<g->n; i++) {
		if (strcmp(g->vs[i].name,name)==0) 
			return i;
	} 

	return NOT_FOUND;
}
		

//  add vertex (if not yet exist)    
//  In all cases, returns the vertex ID   
int add_vertex(char *name, graph_t *g) {
	int vid= vname2id(name, g);
	if (vid== NOT_FOUND) {
		vid= g->n;
		if (vid == g->maxn) {
			g->maxn *= 2;
			g->vs= realloc(g->vs, sizeof(*(g->vs)) * g->maxn);
			assert(g->vs);
		} 
		g->n++;
		vertex_t *v=g->vs + vid;
		strcpy(v->name, name);
		v->ni= 0;
		v->A= new_list();
	}
	return vid;
}
		
//  add edge (uname,vname,weight) to graph
// NOTE: this function does not check for duplicated edge!!!
void add_edge(char *uname, char *vname, double weight, graph_t *g) {
	int uid= add_vertex(uname, g);
	int vid= add_vertex(vname, g);
	vertex_t *v;
	data_t data;
	// add (v, weight) to adjacency list of u
	v= g->vs + uid; 
	data= make_data(vid, weight);
	list_add_end(v->A, data);
 	
	// add (u, weight) to adjacency list of v
	v= g->vs + vid; 
	data= make_data(uid, weight);
	list_add_end(v->A, data);

	g->m++;
}
		
// read graph from stdin
void read_graph( graph_t *g) {
	char uname[MAX_NAME_LEN+1], vname[MAX_NAME_LEN+1];
	double weight;

	for (int n=0; scanf("%s %s %lf ", uname, vname, &weight)==3; n++) {
		printf("Adding: (%s --> %s, %lf) \n", uname, vname, weight);
		add_edge(uname, vname, weight, g);
	}
 	printf("Graph built with %d vertices and %d edges\n", g->n, g->m);
} 


void free_graph(graph_t *g) {
	int i;
	for (i=0; i<g->n; i++) 
		free_list(g->vs[i].A);
	free(g->vs);
	free(g);
}


void print_graph(graph_t *g) {
	int i;
 	printf("\nGraph has %d vertices and %d edges\n", g->n, g->m);
	printf("vid  name     Adjacency List of (vertex id, weight) \n");
	printf("=== ======   ======================================\n");

	for (i=0; i<g->n; i++) {
		vertex_t *v= g->vs+i;
		printf("%3d %-6s   ", i, v->name);
		print_list(v->A);
	}
	printf("-------------------------------------------------\n\n");
}



// Print out the shortest paths from the source node to each other node
void dijkstras(graph_t *g, int source) {
	fprintf(stderr, "dijkstras not yet implemented\n");
	fprintf(stderr, "Implement it! It is in graph.c\n");
	fprintf(stderr, "\nBefore implementing, read graph.h, priorityqueue.h"
		" and data_type.h\n\n");
	fprintf(stderr, "Additional task: Build a graph data file campus.txt\n"
		"then run your program to find the quickest path from level 2 Asia Centre\n"
		"to Room 114 of 221 Bouverie St :-)\n\n"); 
}
