#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 50

void fill_arr_2_3(int **arr, int h);
void print_arr_2_3(int **arr, int h);

int main()
{

	int **arr_2_3 = (int**)calloc(sizeof(int*), HEIGHT);
	for(int i = 0; i < HEIGHT; i++) {
		arr_2_3[i] = (int*)calloc(sizeof(int), 2 + i%2);
	}

	fill_arr_2_3(arr_2_3, HEIGHT);
	print_arr_2_3(arr_2_3, HEIGHT);	

	return 0;
}

void fill_arr_2_3(int **arr, int h)
{
	for(int i = 0; i < HEIGHT; i++) {
		for(int j = 0; j < 2 + i%2; j++) {
			arr[i][j] = (9*i + 2*j)%8 + 1;
		}
	}
}


void print_arr_2_3(int **arr, int h)
{
	for(int i = 0; i < HEIGHT; i++) {
		if(i%2 == 0)
			printf("  %d   %d  \n", arr[i][0], arr[i][1]);
		if(i%2 == 1)
			printf("%d   %d   %d\n", arr[i][0], arr[i][1], arr[i][2]);
	}
}