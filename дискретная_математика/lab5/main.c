#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void invert(int **matrix, int n);
void print_matrix(int **matrix, int n);
void randomize_down(int **matrix, int n, int min, int max);
void fill_diag(int **matrix, int n, int val);

int main()
{
	int n = 10;

	int **matrix = (int**)calloc(sizeof(int*), n);
	for(int i = 0; i < n; i++)
		matrix[i] = (int*)calloc(sizeof(int), n); 

	print_matrix(matrix, n);

	fill_diag(matrix, n, 1);
	print_matrix(matrix, n);

	randomize_down(matrix, n, 0, 10);
	print_matrix(matrix, n);

	return 0;
}

void invert(int **matrix, int n)
{
	
}

void fill_diag(int **matrix, int n, int val)
{
	for(int i = 0; i < n; i++)
		matrix[i][i] = val;
}

void randomize_down(int **matrix, int n, int min, int max)
{
	srand(time(NULL));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			matrix[i][j] = rand() % (max - min + 1) + min;
}

void print_matrix(int **matrix, int n)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("%4d ", matrix[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

