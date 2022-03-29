
#ifndef GRAPH_H
#define GRAPH_H

#include <cstdbool>

typedef struct graph {
	int numnodes;
	bool **adjmatrix;
} graph;

// allocate memory for the graph and return the pointer to it
// return NULL of couldn't allocate
graph *graph_create(int numnodes);

// free memory from the graph
void graph_destroy(graph *g);

// print the graph for graphviz
void graph_print(graph *g);

// add an edge to the graph from node1 to node2
// don't do anything if exists
bool graph_edge_add(graph *g, int node1, int node2);

// return true if edge exists between node1 and node2
// return false otherwise
bool graph_edge_exists(graph *g, int node1, int node2);

#endif // GRAPH_H

