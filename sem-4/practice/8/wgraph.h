
#ifndef WGRAPH_H
#define WGRAPH_H

#include <cstdbool>

typedef struct wgraph {
	int numnodes;
	int **adjmatrix;
} wgraph;

// allocate memory for the graph
// return NULL of couldn't allocate
wgraph *wgraph_create(int numnodes);

// free memory from the graph
void wgraph_destroy(wgraph *g);

// print the graph for graphviz
// note that weights are labels
void wgraph_print(wgraph *g);

// create an edge between node1 and node2
// assign weight to it
// don't do anything the edge is already present
bool wgraph_edge_set_weight(wgraph *g, int node1, int node2, int weight);

// return the weight of the edge from node1 to node2
// return -1 if there's no edge
int wgraph_edge_get_weight(wgraph *g, int node1, int node2);

#endif // WGRAPH_H

