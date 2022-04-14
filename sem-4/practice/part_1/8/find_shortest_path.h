
#ifndef FIND_SHORTEST_PATH_H
#define FIND_SHORTEST_PATH_H

#include "graphs.h"

// find using Dijkstra's Algorithm and print the shortest path from node_i to node_j
// return it's length
// return -1 if there's no path
int graph_find_shortest_path(graph *g, int node_i, int node_j);
int wgraph_find_shortest_path(wgraph *g, int node_i, int node_j);
int digraph_find_shortest_path(digraph *g, int node_i, int node_j);
int wdigraph_find_shortest_path(wdigraph *g, int node_i, int node_j);

#endif // FIND_SHORTEST_PATH_H

