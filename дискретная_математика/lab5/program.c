#include <stdio.h>
#include <stdlib.h>

int calc_det(int **matrix, int n);
void calc_adj(int **matrix_input, int **matrix_output, int n);
void print_matrix(int **matrix, int n);
void randomize_matrix(int **matrix, int n);
void pascal_triangle(int **matrix, int n);

int main()
{
	int n = 10;
	int **matrix = (int **)calloc(sizeof(int *), n);
	for(int i = 0; i < n; matrix[i++] = (int *)calloc(sizeof(int), n));

	pascal_triangle(matrix, n);
	print_matrix(matrix, n);
	printf("%d\n", calc_det(matrix, n));

	return 0;
}

int calc_det(int **matrix, int n)
{
	if(n == 2)
		return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

	int **minor = (int **)calloc(sizeof(int *), n - 1);
	for(int i = 0; i < n - 1; i++)
		minor[i] = (int *)calloc(sizeof(int), n - 1);

	int det = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n - 1; i++)
			for(int j = 0; j < n - 1; j++)
				minor[i][j] = matrix[i + 1][j < k ? j : j + 1];
		det += (k%2 ? -1 : 1) * matrix[0][k] * calc_det(minor, n - 1);
	}

	free(minor);
	return det;
}

void print_matrix(int **matrix, int n)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("\t%d", matrix[i][j]);
		putchar('\n');
	}
}

void randomize_matrix(int **matrix, int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			matrix[i][j] = rand() % 10;
}


void pascal_triangle(int **matrix, int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i + 1; j++)
			if(i == 0 || j == 0)
				matrix[i][j] = 1;
			else
				matrix[i][j] = matrix[i-1][j] + matrix[i-1][j-1];
}

void calc_adj(int **matrix_input, int **matrix_output, int n)
{

}

