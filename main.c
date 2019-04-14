#include "graph.h"

int main(int argc, char *argv[]) {
	graph_t *g= new_graph();
	read_graph(g);
	print_graph(g);

    dijkstras(g,0);

	free_graph(g);

	return 0;
}
