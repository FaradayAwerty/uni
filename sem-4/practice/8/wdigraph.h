
#ifndef WDIGRAPH_H
#define WDIGRAPH_H

#include <cstdbool>

typedef struct wdigraph {
	int numnodes;
	int **adjmatrix;
} wdigraph;

// allocate memory for the graph
// return NULL of couldn't allocate
wdigraph *wdigraph_create(int numnodes);

// free memory from the graph
void wdigraph_destroy(wdigraph *g);

// print the graph for graphviz
// note that weights are labels
void wdigraph_print(wdigraph *g);

// create an edge from node1 to node2
// assign weight to it
// don't do anything if the edge is already present
bool wdigraph_edge_set_weight(wdigraph *g, int node1, int node2, int weight);

// return the weight of the edge between node1 and node2
// return -1 if there's no edge
int wdigraph_edge_get_weight(wdigraph *g, int node1, int node2);

#endif // WDIGRAPH_H

