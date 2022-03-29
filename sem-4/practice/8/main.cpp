
#include <cstdbool>
#include <cstdio>
#include <cstring>

#include "graphs.h"
#include "find_shortest_path.h"

int main()
{
	// example code

	wgraph *g = wgraph_create(10);

	wgraph_edge_set_weight(g, 0, 2, 49);
	wgraph_edge_set_weight(g, 0, 4, 49);
	wgraph_edge_set_weight(g, 0, 5, 29);
	wgraph_edge_set_weight(g, 0, 7, 50);
	wgraph_edge_set_weight(g, 1, 2, 22);
	wgraph_edge_set_weight(g, 1, 6, 46);
	wgraph_edge_set_weight(g, 2, 4, 19);
	wgraph_edge_set_weight(g, 2, 6, 46);
	wgraph_edge_set_weight(g, 2, 8, 23);
	wgraph_edge_set_weight(g, 3, 4, 11);
	wgraph_edge_set_weight(g, 3, 5, 42);
	wgraph_edge_set_weight(g, 4, 8, 18);
	wgraph_edge_set_weight(g, 5, 9, 14);
	wgraph_edge_set_weight(g, 6, 8, 43);
	wgraph_edge_set_weight(g, 8, 9, 18);

	wgraph_print(g);

	printf("// %d\n", wgraph_find_shortest_path(g, 5, 1));

	wgraph_destroy(g);

	return 0;
}

