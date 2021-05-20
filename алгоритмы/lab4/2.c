#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define BLANK 0
#define QUEEN 1

void solution(int *desk, int n, int q);
void clear_all(int *desk, int n);
void clear_row(int *desk, int n, int i);
void clear_column(int *desk, int n, int i);
void place_queen(int *desk, int n, int i, int j);
void remove_queen(int *desk, int n, int i, int j);
void print_desk(int *desk, int n);

int main()
{
	int n; printf("n = "); scanf("%d", &n);
	int *desk = calloc(sizeof(int), n*n);

	return 0;
}

void solution(int *desk, int n, int q)
{

}

// O(1)
void place_queen(int *desk, int n, int i, int j)
{
	if(i < 0 || i >= n || j < 0 || j >= n)
		return;

	desk[i + n*j] = QUEEN;
}

// O(1)
void remove_queen(int *desk, int n, int i, int j)
{
	if(i < 0 || i >= n || j < 0 || j >= n)
		return;

	desk[i + n*j] = BLANK;
}

// O(n^2)
void print_desk(int *desk, int n)
{
	for(int i = 0; i < n*n; i++) {
		printf("%d ", desk[i]);
		if((i+1)%n == 0)
			putchar('\n');
	}
}

// O(n)
void clear_row(int *desk, int n, int i)
{
	if(i < 0 || i >= n)
		return;
	for(int j = 0; j < n; j++)
		desk[j + i*n] = BLANK;
}

// O(n)
void clear_column(int *desk, int n, int i)
{
	if(i < 0 || i >= n)
		return;
	for(int j = 0; j < n; j++)
		desk[i + j*n] = BLANK;
}

// O(n^2)
void clear_all(int *desk, int n)
{
	for(int i = 0; i < n*n; i++)
		desk[i] = BLANK;
}

