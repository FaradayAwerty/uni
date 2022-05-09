
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printSolution(int dist[], int num_nodes)
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < num_nodes; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}

int minDistance(int dist[], bool sptSet[], int num_nodes)
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < num_nodes; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int **graph, int num_nodes, int start)
{
    int dist[num_nodes];

    bool sptSet[num_nodes];
    for (int i = 0; i < num_nodes; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[start] = 0;

    for (int count = 0; count < num_nodes - 1; count++) {
        int u = minDistance(dist, sptSet, num_nodes);
        sptSet[u] = true;
        for (int v = 0; v < num_nodes; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, num_nodes);
}

int main()
{
	int n, m;
	cin >> n >> m;

	int **graph;

	graph = (int **)malloc(sizeof(int *) * n);
	for(int i = 0; i < n; i++)
		graph[i] = (int *)calloc(sizeof(int), n);

	int s, t;
	cin >> s >> t;
	s--;
	t--;

	int a, b, p;

	for(int i = 0; i < m; i++) {
		cin >> a >> b >> p;

		a--;
		b--;

		graph[a][b] = p;
		graph[b][a] = p;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << '\t' << graph[i][j];
		putchar('\n');
	}

	dijkstra(graph, n, 0);

	for(int i = 0; i < n; i++)
		free(graph[i]);
	free(graph);

	return 0;
}

