
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <climits>

#include "find_shortest_path.h"
#include "graphs.h"

#define INFINITY INT_MAX

int min(int a, int b) {
	if(a < b)
		return a;
	return b;
}

void printarr(int *arr, int n) {
	for(int i = 0; i < n; i++)
		printf("\t%d", arr[i]);
	putchar('\n');
}

int wgraph_find_shortest_path(wgraph *g, int node_i, int node_j) {
	bool *explored = (bool *)calloc(sizeof(int), g->numnodes);

	int *path = (int *)malloc(sizeof(int) * g->numnodes);
	for(int i = 0; i < g->numnodes; i++)
		path[i] = -1;

	int *shortest_path_to = (int *)malloc(sizeof(int) * g->numnodes);
	for(int i = 0; i < g->numnodes; i++)
		shortest_path_to[i] = INFINITY;
	shortest_path_to[node_i] = 0;

	int node = node_i;

	while(!explored[node] && node != node_j) {

		for(int i = 0; i < g->numnodes; i++)
			if(!explored[i] && wgraph_edge_get_weight(g, node, i) != -1 && shortest_path_to[node] + wgraph_edge_get_weight(g, node, i) < shortest_path_to[i]) {
					shortest_path_to[i] = shortest_path_to[node] + wgraph_edge_get_weight(g, node, i);
					path[i] = node;
			}
		explored[node] = true;

		for(int i = 0; i < g->numnodes; i++)
			if(explored[node] || (shortest_path_to[i] < shortest_path_to[node] && !explored[i]))
				node = i;
	}

	if(node == node_j) {
		printf("// the shortest path from node %d to node %d is:\n//\t", node_i, node_j);
		while(node != node_i) {
			printf("%d <- ", node);
			node = path[node];
		}
		printf("%d\n", node_i);
		return shortest_path_to[node_j];
	}

	return -1;
}

