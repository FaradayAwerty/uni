#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct IntStackType {
	int data;
	struct IntStackType *next;
};

typedef struct IntStackType Stack;

Stack *push(Stack *stack, int data)
{
	Stack *_stack = malloc(sizeof(Stack));
	_stack->data = data;
	_stack->next = stack;
	return _stack;
}

float pop(Stack **stack)
{
	int data = (*stack)->data;

	Stack *_stack = *stack;
	*stack = (*stack)->next;
	free(_stack);

	return data;
}

float eval(char *string) {

	for(int i = 0; string[i] != '\0'; i++) {

	}

	return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		puts("you have to provide a string");
		return 1;
	}

	if (argc > 2) {
		puts("you have to provide only one string");
		return 1;
	}

	char *string = argv[1];

	Stack *stack = push(NULL, 1);

	return 0;
}

