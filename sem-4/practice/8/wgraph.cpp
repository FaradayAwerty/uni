
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "wgraph.h"

wgraph *wgraph_create(int numnodes) {
	wgraph *g = (wgraph *)malloc(sizeof(*g));
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
			wgraph_destroy(g);
			return NULL;
		}
		for(int j = 0; j < numnodes; j++)
			g->adjmatrix[i][j] = -1;
	}

	return g;
}

void wgraph_destroy(wgraph *g) {
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

void wgraph_print(wgraph *g) {
	puts("graph {");
	for(int i = 0; i < g->numnodes; i++)
		for(int j = 0; j < i; j++)
			if(wgraph_edge_get_weight(g, i, j) != -1)
				printf("\t%d -- %d [label=%d];\n", i, j, wgraph_edge_get_weight(g, i, j));
	puts("}");
}

bool wgraph_edge_set_weight(wgraph *g, int node_i, int node_j, int weight) {
	assert(g != NULL && g->adjmatrix != NULL);
	assert(0 <= node_i && node_i < g->numnodes);
	assert(0 <= node_j && node_j < g->numnodes);

	if(wgraph_edge_get_weight(g, node_i, node_j) != -1)
		return false;

	g->adjmatrix[node_i][node_j] = weight;
	g->adjmatrix[node_j][node_i] = weight;

	return true;
}

int wgraph_edge_get_weight(wgraph *g, int node_i, int node_j) {
	assert(g != NULL && g->adjmatrix != NULL);
	assert(0 <= node_i && node_i < g->numnodes);
	assert(0 <= node_j && node_j < g->numnodes);

	if(g->adjmatrix[node_i][node_j] != g->adjmatrix[node_j][node_i])
		return -1;

	return g->adjmatrix[node_i][node_j];
}

