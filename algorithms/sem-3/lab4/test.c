#include <stdio.h>
#include <stdlib.h>

struct digit {
	int data;
	struct digit *next;
	struct digit *prev;
};

struct number {
	struct digit *first;
	struct digit *last;
};

struct number *new_number() {
	struct number *new = malloc(sizeof(struct number));
	struct digit *zero = malloc(sizeof(struct digit));

	zero->data = 0;
	zero->prev = NULL;
	zero->next = NULL;

	new->first = zero;
	new->last = zero;

	return new;
}

void print_number(struct number *n)
{
	struct digit *d = n->first;
	while(d != NULL) {
		printf("%d", d->data);
		d = d->next;
	}
	putchar('\n');
}

void insertFirst(struct number *n, int digit) {

	if(digit == 0)
		return;

	struct digit *new = malloc(sizeof(struct digit));
	new->data = digit;
	new->prev = NULL;
	new->next = n->first;
	n->first = new;
}

void insertLast(struct number *n, int digit) {

	if(n->first == n->last && n->first->data == 0) {
		n->first->data = digit;
		return;
	}


	struct digit *new = malloc(sizeof(struct digit));
	new->data = digit;
	new->next= NULL;
	new->prev = n->last;
	n->last->next = new;
	n->last = new;
}

struct number *add(struct number *a, struct number *b)
{
	return NULL;
}

struct number *mult(struct number *a, struct number *b)
{
	return NULL;
}

struct number *sub(struct number *a, struct number *b)
{
	return NULL;
}

int main()
{
	struct number *num = new_number();



	print_number(num);

	return 0;
}

