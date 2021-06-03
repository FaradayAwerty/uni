#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// triangle data
int t_h;
int **t_arr;
int t_max = 99;
int t_min = 10;

// triangle functions
void t_create();
void t_randomize();
void t_print();
int t_find_max_sum();

// util functions
void u_print_blanks(int n);

int main()
{
	t_create();
	t_randomize();
	t_print();

	return 0;
}

void t_create()
{
	printf("высота треугольника: "); scanf("%d", &t_h);
	t_arr = (int **)calloc(sizeof(int*), t_h * (t_h+1) / 2);
	for(int i = 0; i < t_h; i++)
		t_arr[i] = (int *)calloc(sizeof(int), i + 1);
}

void t_randomize()
{
	for(int i = 0; i < t_h; i++)
		for(int j = 0; j < i + 1; j++)
			t_arr[i][j] = rand() % (t_max - t_min + 1) + t_min;
}

void t_print()
{
	for(int i = 0; i < t_h; i++) {
		for(int j = 0; j < i + 1; j++)
			printf("\t%d", t_arr[i][j]);
		putchar('\n');
	}
}

int t_find_max_sum()
{
	return 0;
}

void u_print_blanks(int n)
{
	for(int i = 0; i < n; i++)
		putchar(' ');
}
