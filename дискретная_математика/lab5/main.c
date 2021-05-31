#include <time.h>
#include <stdio.h>
#include <stdlib.h>

float det(float **matrix, int n);
void adj(float **matrix, int n);
void invert(float **matrix, int n);
void print_matrix(float **matrix, int n);
void randomize_down(float **matrix, int n, int min, int max);
void fill_diag(float **matrix, int n, int val);

int main()
{
	int n = 10;

	float **matrix = (float**)calloc(sizeof(float*), n);
	for(int i = 0; i < n; i++)
		matrix[i] = (float*)calloc(sizeof(float), n); 

	fill_diag(matrix, n, 1);
	randomize_down(matrix, n, 10, 99);

	print_matrix(matrix, n);
	printf("%f\n", det(matrix, n));

	return 0;
}

float det(float **matrix, int n)
{
	float d = 1;
	for(int i = 0; i < n; i++)
		d *= matrix[i][i];
	return d;
}

void adj

void invert(float **matrix, int n)
{

}

void fill_diag(float **matrix, int n, int val)
{
	for(int i = 0; i < n; i++)
		matrix[i][i] = val;
}

void randomize_down(float **matrix, int n, int min, int max)
{
	srand(time(NULL));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			matrix[i][j] = rand() % (max - min + 1) + min;
}

void print_matrix(float **matrix, int n)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("\t%.2f", matrix[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

