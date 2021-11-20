#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

void insert_at_end(struct node *head, int data);
void printlist(struct node *head);

int main()
{
	struct node *head = malloc(sizeof(struct node));
	head->data = 11;
	head->link = NULL;
	insert_at_end(head, 22);
	insert_at_end(head, 33);
	insert_at_end(head, 33);
	insert_at_end(head, 44);
	insert_at_end(head, 55);
	insert_at_end(head, 56);
	
	printlist(head);

	return 0;
}

void insert_at_end(struct node *head, int data)
{
	// can't do anything if head is NULL
	if(head == NULL)
		return;

	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;

	struct node *ptr = head;
	while(ptr->link != NULL)
		ptr = ptr->link;

	ptr->link = temp;
}

void printlist(struct node *head)
{
	struct node *ptr = head;
	while(ptr != NULL) {
		printf("\t%d", ptr->data);
		ptr = ptr->link;
	};

	putchar('\n');
}

