#include <stdlib.h>
#include <stdio.h>

void print_desk(int *desk, int n)
{
	for(int i = 0; i < n*n; i++) {
		printf("%d ", desk[i]);
		if((i+1)%n == 0)
			putchar('\n');
	}
}

void clear_row(int *desk, int n, int i)
{
	if(i < 0 || i >= n)
		return;
	for(int j = i*n; j < (i+1)*n; j++)
		desk[j] = 1;
}

int main()
{
	int n; printf("n = "); scanf("%d", &n);
	int *desk = calloc(sizeof(int), n*n);

	clear_row(desk, n, 3);
	print_desk(desk, n);

	return 0;
}

