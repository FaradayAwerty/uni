
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "digraph.h"

digraph *digraph_create(int numnodes) {
	digraph *g = (digraph *)malloc(sizeof(*g));
	if(g == NULL)
		return NULL;

	g->numnodes = numnodes;

	g->adjmatrix = (bool **)calloc(sizeof(bool *), numnodes);
	if(g->adjmatrix == NULL) {
		free(g);
		return NULL;
	}

	for(int i = 0; i < numnodes; i++) {
		g->adjmatrix[i] = (bool *)calloc(sizeof(bool), numnodes);
		if(g->adjmatrix[i] == NULL) {
			digraph_destroy(g);
			return NULL;
		}
	}

	return g;
}

void digraph_destroy(digraph *g) {
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

void digraph_print(digraph *g) {
	puts("digraph {");
	for(int i = 0; i < g->numnodes; i++)
		for(int j = 0; j < g->numnodes; j++)
			if(digraph_edge_exists(g, i, j))
				printf("\t%d -> %d;\n", i, j);
	puts("}");
}

bool digraph_edge_add(digraph *g, int node_i, int node_j) {
	assert(g != NULL && g->adjmatrix != NULL);
	assert(0 <= node_i && node_i < g->numnodes);
	assert(0 <= node_j && node_j < g->numnodes);

	if(digraph_edge_exists(g, node_i, node_j))
		return false;

	g->adjmatrix[node_i][node_j] = true;

	return true;
}

bool digraph_edge_exists(digraph *g, int node_i, int node_j) {
	assert(g != NULL && g->adjmatrix != NULL);
	assert(0 <= node_i && node_i < g->numnodes);
	assert(0 <= node_j && node_j < g->numnodes);

	return g->adjmatrix[node_i][node_j];
}

