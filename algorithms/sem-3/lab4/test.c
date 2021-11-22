#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct digit {
	int data;
	struct digit *next;
	struct digit *prev;
};

struct number {
	struct digit *first;
	struct digit *last;
};

void printnum(struct number *num);
void printnumr(struct number *num);
void insertLast(struct number *num, int digit);
void insertFirst(struct number *num, int digit);
void add(struct number *, struct number *);
struct number *new_number(unsigned int num);

int main()
{
	struct number *N = new_number(999);
	add(N, new_number(1));
	printnum(N);

	return 0;
}

void add(struct number *a, struct number *b)
{
	struct digit *ad = a->last, *bd = b->last;

	int sum = 0;

	while(ad != NULL || bd != NULL) {
		sum = (ad == NULL ? 0 : ad->data) + (bd == NULL ? 0 : bd->data) + sum/10; 

		if(ad != NULL)
			ad->data = sum%10;
		else
			insertFirst(a, sum%10);

		if(ad != NULL)
			ad = ad->prev;
		if(bd != NULL)
			bd = bd->prev;
	}

	if(sum/10 != 0)
		insertFirst(a, sum/10);
}

void insertFirst(struct number *num, int digit)
{
	if(digit < 0 || 9 < digit)
		return;

	struct digit *d = malloc(sizeof(struct digit));
	d->data = digit;
	d->prev = NULL;
	d->next = num->first;
	num->first->prev = d;
	num->first = d;
}

void insertLast(struct number *num, int digit)
{
	if(digit < 0 || 9 < digit)
		return;

	struct digit *d = malloc(sizeof(struct digit));
	d->data = digit;
	d->next = NULL;
	d->prev = num->last;
	num->last->next = d;
	num->last = d;
}

struct number *new_number(unsigned int num)
{
	struct number *new = malloc(sizeof(struct number));

	if(num == 0) {
		struct digit *zero = malloc(sizeof(struct digit));
		zero->next = NULL;
		zero->prev = NULL;
		new->first = zero;
		new->last = zero;
	}

	while(num != 0) {
		struct digit *d = malloc(sizeof(struct digit));
		d->data = num%10;

		if(new->first == NULL) {
			new->first = d;
			new->last = d;
			d->next = NULL;
			d->prev = NULL;
		} else {
			d->prev = NULL;
			d->next = new->first;
			new->first->prev = d;
			new->first = d;
		}

		num /= 10;
	}

	return new;
}

void printnum(struct number *num)
{
	struct digit *d = num->first;
	while(d != NULL) {
		printf("%d", d->data);
		d = d->next;
	}
	putchar('\n');
}

void printnumr(struct number *num)
{
	struct digit *d = num->last;
	while(d != NULL) {
		printf("%d", d->data);
		d = d->prev;
	}
	putchar('\n');
}

