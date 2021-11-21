#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

void insert(struct node *node, int data);
void printlist(struct node *head);

int main()
{
	int input_number;
	struct node *head = NULL;

	puts("Введите несколько целых чисел");
	puts("\tпримечание: 0 завершает ввод\n");

	while(1) {
		scanf("%d", &input_number);

		if(input_number == 0) {
			break;
		} else if(head == NULL) {
			head = malloc(sizeof(struct node));
			head->data = input_number;
			head->link = NULL;
		} else {
			//tail->link = malloc(sizeof(struct node));
			//tail = tail->link;
			//tail->data = input_number;
			//tail->link = NULL;
			insert(head, input_number);
		}

	}

	printlist(head);

	return 0;
}

void insert(struct node *head, int data)
{
	if(head == NULL)
		return;

	struct node *ptr = head;
	while(ptr->link != NULL && data > ptr->data) {
		ptr = ptr->link;
	}

	struct node *new = malloc(sizeof(struct node));
	new->data = data;

	new->link = ptr->link;
	ptr->link = new; 

	if(ptr->data > data) {
		int t = ptr->data;
		ptr->data = new->data;
		new->data = t;
	}
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

