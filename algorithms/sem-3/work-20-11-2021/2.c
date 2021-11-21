#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *link;
};

struct node *p(struct node *head)
{
	struct node *ptr = head,
		*new_head = malloc(sizeof(struct node)),
		*new_ptr = new_head;
	new_ptr->link = NULL;

	bool empty = true;

	while(ptr != NULL) {
		if(ptr->data > 0) {
			ptr = ptr->link;
			continue;
		}

		empty = false;

		if(new_ptr->link != NULL)
			new_ptr = new_ptr->link;

		if(ptr->data < 0) {
			new_ptr->data = 0;
			new_ptr->link = malloc(sizeof(struct node));
			new_ptr = new_ptr->link;
		}

		new_ptr->data = ptr->data;
		new_ptr->link = malloc(sizeof(struct node));
		ptr = ptr->link;
	}
	new_ptr->link = NULL;
	if(empty == true)
		return NULL;
	free(head);
	return new_head;
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
	tail->link = NULL;

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

	head = p(head);
	printlist(head);

	return 0;
}

