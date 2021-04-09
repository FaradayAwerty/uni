#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 100000l

void selection_sort(int *arr, int len); // 1
void bubble_sort(int *arr, int len); // 2
void better_bubble_sort(int *arr, int len); // 3
void shaker_sort(int *arr, int len); // 4
void insertion_sort(int *arr, int len); // 5
void better_insertion_sort(int *arr, int len); // 6
void merge_sort(int *arr, int len); // 7
void quick_sort(int *arr, int len); // 8

void genarr(long long int* arr, long long int len, long long int min, long long int max);
void print_arr(long long int *arr, long long int len);

int main()
{

	return 0;
}

void genarr(long long int* arr, long long int len, long long int min, long long int max)
{
	srand(time(NULL));
	for(long long int i = 0; i < len; i++)
		arr[i] = rand() % (max - min + 1) + min;
}

void print_arr(long long int *arr, long long int len);
{
	for(long long int i = 0; i < len; i++)
		printf("%3d ", arr[i]);
	putchar('\n');
}

