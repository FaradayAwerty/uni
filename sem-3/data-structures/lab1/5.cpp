#include <cstdio>
#include <cstdlib>

struct Chain {
	int data;
	Chain *next;
};

typedef struct Chain List;

void printList(List *list)
{
	Chain *current = list;
	while(current != NULL) {
		printf("\t%d", current->data);
		current = current->next;
	}
	putchar('\n');
}

int main()
{
	FILE *f = fopen("5.txt", "r");
	if(f == NULL) {
		puts("file '5.txt' must exist and have integers separated with newline");
		return 1;
	}

	
	List *list;
	struct Chain *current = list;

	for(int ch = fgetc(f); ch != EOF; ch = fgetc(f)) {
		int n = -1;
		if('0' <= ch && ch <= '9')
			n = ( n == -1 ? ch - '0' : n * 10 + ch - '0' );
		if(ch == '\n') {
			struct Chain *newChain;
			current->next = newChain;
			current->data = n;
			current = current->next;
			current->next = NULL;
		}
	}

	printList(list);

	fclose(f);

	return 0;
}

