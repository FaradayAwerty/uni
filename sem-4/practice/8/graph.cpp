
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "graph.h"

graph *graph_create(int numnodes) {
	graph *g = (graph *)malloc(sizeof(*g));
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
			graph_destroy(g);
			return NULL;
		}
	}

	return g;
}

void graph_destroy(graph *g) {
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

void graph_print(graph *g) {
	puts("graph {");
	for(int i = 0; i < g->numnodes; i++)
		for(int j = 0; j < i; j++)
			if(graph_edge_exists(g, i, j))
				printf("\t%d -- %d;\n", i, j);
	puts("}");
}

bool graph_edge_add(graph *g, int node_i, int node_j) {
	assert(g != NULL && g->adjmatrix != NULL);
	assert(0 <= node_i && node_i < g->numnodes);
	assert(0 <= node_j && node_j < g->numnodes);

	if(graph_edge_exists(g, node_i, node_j))
		return false;

	g->adjmatrix[node_i][node_j] = true;
	g->adjmatrix[node_j][node_i] = true;

	return true;
}

bool graph_edge_exists(graph *g, int node_i, int node_j) {
	assert(g != NULL && g->adjmatrix != NULL);
	assert(0 <= node_i && node_i < g->numnodes);
	assert(0 <= node_j && node_j < g->numnodes);

	return g->adjmatrix[node_i][node_j] && g->adjmatrix[node_j][node_i];
}

