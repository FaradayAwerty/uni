#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *reverse(struct node *head)
{
	struct node *tail = head;

	while(tail->link != NULL)
		tail = tail->link;

	while(head->link != tail) {
		struct node *temp = head->link;
		head->link = head->link->link;
		temp->link = tail->link;
		tail->link = temp;
	}

	while(tail->link != NULL)
		tail = tail->link;


	tail->link = head;
	struct node *temp = head->link;
	tail->link->link = NULL;

	return temp;
}

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
	head = reverse(head);
	printlist(head);
}
