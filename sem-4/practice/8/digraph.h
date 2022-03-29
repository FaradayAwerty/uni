
#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <cstdbool>

typedef struct digraph {
	int numnodes;
	bool **adjmatrix;
} digraph;

// allocate memory for the graph
// return NULL of couldn't allocate
digraph *digraph_create(int numnodes);

// free memory from the graph
void digraph_destroy(digraph *g);

// print the graph for graphviz
void digraph_print(digraph *g);

// add an edge to the graph from node1 to node2
// don't do anything if exists
bool digraph_edge_add(digraph *g, int node1, int node2);

// return true if edge exists from node1 to node2
// return false otherwise
bool digraph_edge_exists(digraph *g, int node1, int node2);

#endif // DIGRAPH_H

