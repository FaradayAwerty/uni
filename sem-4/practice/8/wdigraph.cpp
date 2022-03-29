
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "wdigraph.h"

wdigraph *wdigraph_create(int numnodes) {
	wdigraph *g = (wdigraph *)malloc(sizeof(*g));
	if(g == NULL)
		return NULL;

	g->numnodes = numnodes;

	g->adjmatrix = (int **)malloc(sizeof(int *) * numnodes);
	if(g->adjmatrix == NULL) {
		free(g);
		return NULL;
	}

	for(int i = 0; i < numnodes; i++) {
		g->adjmatrix[i] = (int *)malloc(sizeof(int) * numnodes);
		if(g->adjmatrix[i] == NULL) {
			wdigraph_destroy(g);
			return NULL;
		}
		for(int j = 0; j < numnodes; j++)
			g->adjmatrix[i][j] = -1;
	}

	return g;
}

void wdigraph_destroy(wdigraph *g) {
	if(g == NULL)
		return;
	if(g->adjmatrix == NULL) {
		free(g);
		return;
	}
	for(int i = 0; i < g->numnodes; i++)
		if(g->adjmatrix[i] != NULL)
			free(g->adjmatrix[i]);
	free(g->adjmatrix);
	free(g);
}

void wdigraph_print(wdigraph *g) {
	puts("digraph {");
	for(int i = 0; i < g->numnodes; i++)
		for(int j = 0; j < g->numnodes; j++)
			if(wdigraph_edge_get_weight(g, i, j) != -1)
				printf("\t%d -> %d [label=%d];\n", i, j, wdigraph_edge_get_weight(g, i, j));
	puts("}");
}

bool wdigraph_edge_set_weight(wdigraph *g, int node_i, int node_j, int weight) {
	assert(g != NULL && g->adjmatrix != NULL);
	assert(0 <= node_i && node_i < g->numnodes);
	assert(0 <= node_j && node_j < g->numnodes);

	if(wdigraph_edge_get_weight(g, node_i, node_j) != -1)
		return false;

	g->adjmatrix[node_i][node_j] = weight;

	return true;
}

int wdigraph_edge_get_weight(wdigraph *g, int node_i, int node_j) {
	assert(g != NULL && g->adjmatrix != NULL);
	assert(0 <= node_i && node_i < g->numnodes);
	assert(0 <= node_j && node_j < g->numnodes);

	return g->adjmatrix[node_i][node_j];
}

