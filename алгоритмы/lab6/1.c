#include <stdio.h>
#include <stdlib.h>

#define DOWN 0
#define RIGHT 1

void print_streets(int **streets, int m, int l);

int main()
{
	int N, l, m;
	printf("l = "); scanf("%d", &l);
	printf("m = "); scanf("%d", &m);

	N = l * m;
	int **streets = (int **)calloc(sizeof(int *), N);
	for(int i = 0; i < N; i++)
		streets[i] = (int *)calloc(sizeof(int), 2);

	print_streets(streets, m, l);

	return 0;
}

void print_streets(int **streets, int l, int m)
{
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < m; j++)
			printf("%d↓ %d\t", streets[i + l*j][DOWN],
				streets[i + l*j][RIGHT]);
		putchar('\n');
	}
}

