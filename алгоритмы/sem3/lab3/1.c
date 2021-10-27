#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct CharStackType {
	char data;
	struct CharStackType *next;
};

typedef struct CharStackType CharStack;

CharStack *push(CharStack *stack, char c)
{
	CharStack *newCharStack = malloc(sizeof(CharStack));
	newCharStack->next = stack;
	newCharStack->data = c;
	return newCharStack;
}

char pop(CharStack **stack)
{
	char data = (*stack)->data;

	CharStack *_stack = *stack;
	*stack = (*stack)->next;
	free(_stack);

	return data;
}

void print_char_stack(CharStack *stack)
{
	do {
		putchar(pop(&stack));
	} while(stack != NULL);
	putchar('\n');
}

bool is_balanced(char *string)
{
	CharStack *stack = NULL;
	for(int i = 0; string[i] != '\0'; i++) {

		if(string[i] == '(' || string[i] == '[' || string[i] == '{')
			stack = push(stack, string[i]);
		if(string[i] != ')' && string[i] != ']' && string[i] != '}')
			continue;
		if(stack == NULL)
			return false;

		char pop_val = pop(&stack);
		if(string[i] == ')' && pop_val != '(')
			return false;
		if(string[i] == ']' && pop_val != '[')
			return false;
		if(string[i] == '}' && pop_val != '{')
			return false;
	}

	if(stack == NULL)
		return true;
	return false;
}

int main(int argc, char *argv[]) {

	if (argc < 2) {
		puts("you have to provide a string");
		return 1;
	}
	if (argc > 2) {
		puts("you have to provide only one string");
		return 1;
	}

	char *string = argv[1];

	CharStack *stack = push(NULL, string[0]);
	for(int i = 1; string[i] != '\0'; i++) {
		stack = push(stack, string[i]);
	}

	printf("%d\n", is_balanced(string));

	return 0;
}

