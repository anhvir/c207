/*  SOLUTION TO Lab Week 7
	Module: graph
	Dependencies: priorityqueue , data_type

	Simple implementation of positively weighted, undirected graph
	Input graph has a format as in graph_data.txt, which is sequence of:
	    name1  name2 weight
    where name? is a single-word name (such as Melbourne)
	      weight is a positive weight/distance (of "double" type)

	Created by Anh Vo, anhvir@gmail.com, for comp20007_2018s1 week 8 
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
 	
	// add (u, weight) to adjacency list of v (as graph is undirected)
	v= g->vs + vid; 
	data= make_data(uid, weight);
	list_add_end(v->A, data);

	g->m++;
}
		

void read_graph( graph_t *g) {
	char uname[MAX_NAME_LEN+1], vname[MAX_NAME_LEN+1];
	double weight;

	for (int n=0; scanf("%s %s %lf ", uname, vname, &weight)==3; n++) {
		printf("Adding: (%s --> %s, %lf) \n", uname, vname, weight);
		assert(weight>=0);	// this test is for Dijkstra's alg
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
	printf("vid  name     Adjacency List (to_vertex, weight) \n");
	printf("=== ======   ======================================\n");

	for (i=0; i<g->n; i++) {
		vertex_t *v= g->vs+i;
		printf("%3d %-6s   ", i, v->name);
		print_list(v->A);
	}
	printf("-------------------------------------------------\n\n");
}




/* ===========  Dijkstra's Algorithm Implementation ============ */
#define INFINITY 1000000000
#define NO_PREV -1

void print_all_path(double dist[], int prev[], graph_t *g, int source); 
void print_path(int prev[], graph_t *g, int source, int dest); 

// Replace 1 by 0 if you want to use the standard Dijlstra's,
//   ie the one that is the same as shown in the lecture

#if 0
// NON-standard version of Dijkstra's:
// Print out the shortest paths from the source node to each other node
void dijkstras(graph_t *g, int source) {
	int i;
	int u, v; double weight;   // generous vars for edge (u->v,weight)
	double new_weight;

	// To store current min-costs and previous vertices
	int *prev;		// prev[v]=u if v was reached from u 
  	double *dist;	// dist[v]= current best dist from source to v
	assert(prev= malloc( g->n * sizeof(*prev) ) );
	assert(dist= malloc( g->n * sizeof(*dist) ) );

	/* Initialization ------------------------------ */
	for (i = 0; i < g->n; i++) {
		prev[i] = NO_PREV;
		dist[i] = INFINITY;
	}
	dist[source] = 0;

	// enqueue "source" - the only one that has limitted dist
	pq_t *queue = new_pq();
	pq_enqueue(queue, source, dist[source]);

	/* Main loop of Dijkstra's ------------------------------ */
	// buddy array of n elements to store the adjacency list of a vertex
	data_t *neighbours; int n;
	assert(neighbours= malloc( g->n * sizeof(*neighbours) ) );

	while (!pq_is_empty(queue)) {
		// remove min vertex 
    	u = pq_remove_min(queue);
		
		// With this vertex u:
		// * first, copies the adjacency list of u to array neighbours
		n= list_2_array(g->vs[u].A, neighbours);
		// * then, inspects each of the neighbour 
		for (i = 0; i < n; i++) {
			v = neighbours[i].id;   // looking at edge (u-->v,weight) 
			weight = neighbours[i].weight;
			new_weight = dist[u] + weight;

			// if v was reached before with a better outcome
			//      then we just ignore the edge u-->v
			if ( dist[v] <= new_weight) continue;  

			// updates vertex v in the queue 
			if (dist[v] == INFINITY) { 
				// if v never been reached before, adds it to queue
				pq_enqueue(queue, v, new_weight);
			} else { 
				// otherwise, updates weight of v in the queue
				//   note that the update must be successful 
				if ( !pq_update(queue, v, new_weight) ){
					fprintf(stderr, "Internal error: Something wrong "
					  "in code or in data (such as negative weight)\n");
					exit(EXIT_FAILURE);
				}
			}
			
			// now updaes dist[v] and prev[v]
			dist[v] = new_weight;          
			prev[v] = u;

		}
	}

	
	/* Prints out all shortest paths ------------------------------ */
	print_all_path(dist, prev, g, source);
	
	// free the dynamic data structures
	free(dist);
	free(prev);
	free(neighbours);
	free_pq(queue);	
}





#else




/****************************************************
	Here, I want to demonstrate
	how to translate a pseudocode to a C function
	by doing that for the Dijkstra's pseudocode
	presented in page 16 of lec08.pdf 
****************************************************/

// The "standard" version of Dijkstra's,
//   ie the one that is the same as shown in the lecture
//    see page 16 of lec08.pdf
// Comments starting with //* are the lines from pseudocode in page 16
// Print out the shortest paths from the source node to each other node
void dijkstras(graph_t *g, int v0) {
	int v;
	int u, w; double weight;   // generous vars for edge (u->w,weight)

	// To store current min-costs and previous vertices
	int *prev;		// prev[v]=u if v was reached from u 
  	double *dist;	// dist[v]= current best dist from source to v
	bool *inQ;	// a helping array for quick check if v in Q
	assert(prev= malloc( g->n * sizeof(*prev) ) );
	assert(dist= malloc( g->n * sizeof(*dist) ) );
	assert(inQ= malloc( g->n * sizeof(*inQ) ) );

	/* Initialization ------------------------------ */
	for (v = 0; v < g->n; v++) {  //* foreach v in V
		prev[v] = NO_PREV;        //*    prev[v]= nil
		dist[v] = INFINITY;       //*    dist[v]= infinity
	}
	dist[v0] = 0;                 //* dist[v0]=0

	//* Q = InitPriorityQueue(V)
	pq_t *Q = new_pq();
	for (v = 0; v < g->n; v++) {
		pq_enqueue(Q, v, dist[v]);
		inQ[v]= true;			// marks v as being inside the queue
	}
		
	/* Main loop of Dijkstra's ------------------------------ */
	// buddy array of n elements to store the adjacency list of a vertex
	data_t *neighbours; int n;
	assert(neighbours= malloc( g->n * sizeof(*neighbours) ) );

	while (!pq_is_empty(Q)) {  //* while Q is non empty do
		// remove min vertex 
    	u = pq_remove_min(Q);  //*    u= EjectMin(Q)
		inQ[u]= false;         //     marks u as not in Q anymore
		
		// With this vertex u:
		//   first, copies the adjacency list of u to array neighbours
		n= list_2_array(g->vs[u].A, neighbours);
		 
		for (v = 0; v < n; v++) {  //* for each (u,w) in E do
			w = neighbours[v].id;   //   having:edge (u-->w,weight) 
			weight= neighbours[v].weight;

			//* if (w in Q && dist[v]+weight(u,w) <dist[v]
			if ( inQ[w] && dist[w] > dist[u]+weight) {  
				dist[w] = dist[u]+weight;  //* dist[w]= dist[u]+weight(u,v)          
				prev[w] = u;               //* prev[w]= u 
			                               //* Update(Q, w, dist[w])
				pq_update(Q, w, dist[w]);
			
			}
		}
	}

	
	/* Prints out all shortest paths ------------------------------ */
	print_all_path(dist, prev, g, v0);
	
	// free the dynamic data structures
	free(dist);
	free(prev);
	free(neighbours);
	free_pq(Q);	
}



#endif


// Prints out all shortest paths 
void print_all_path(double dist[], int prev[], graph_t *g, int source) {
	int i;
	char *source_name= g->vs[source].name;
	for (i = 0; i < g->n; i++) {
		vertex_t *v= g->vs+i;
		printf("Path %s --> %s, dist = %.0lf  Detailed path:\n\t\t", 
			source_name, v->name, dist[i]);
		print_path(prev, g, source, i);
		printf("\n\n");
	}
}
	

// a recursive funcition to print vertex name
//     in reverse order of prev
// Note: prev[v] = u means the edge u-->v was used to reach to v
//       and we want to print u before v
void print_path(int prev[], graph_t *g, int source, int dest) {
	if (source==dest) {
		printf("%s", g->vs[source].name);
		return;
	}
	if (dest==NO_PREV) {
		fprintf(stderr,"Internal error: something wrong with this "
		               "implementation of Dijkstra's.\n\n");
		exit(EXIT_FAILURE);
	}
	print_path(prev, g, source, prev[dest]);
	printf (" --> %s", g->vs[dest].name);
}

