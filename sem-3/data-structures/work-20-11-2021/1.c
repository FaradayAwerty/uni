#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

void printlist(struct node *head)
{
	struct node *ptr = head;
	while(ptr != NULL) {
		printf("\t%d", ptr->data);
		ptr = ptr->link;
	}
	putchar('\n');
}

int main()
{
	int len, data;
	struct node *head = malloc(sizeof(struct node));
	struct node *tail = head;

	puts("Введите количество элементов в списке:"); scanf("%d", &len);
	puts("Введите элементы:");

	for(int i = 0; i < len; i++) {
		scanf("%d", &data);

		if(tail->link != NULL)
			tail = tail->link;

		tail->data = data;
		tail->link = malloc(sizeof(struct node));
	}
	tail->link = NULL;

	printlist(head);

	int odds = 0;
	struct node *ptr = head;

	while(ptr != NULL && odds < 2) {
		if((ptr->data) % 2 == 0)
			odds = 0;
		else
			odds++;
		ptr = ptr->link;
	}

	if(odds > 1)
		puts("В списке есть хотя бы два подряд идущих нечётных элемента.");

	return 0;
}

