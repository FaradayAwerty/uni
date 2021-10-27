#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct FloatStackType {
	float data;
	struct FloatStackType *next;
};

typedef struct FloatStackType FloatStack;

FloatStack *push(FloatStack *stack, float f)
{
	FloatStack *newStack = malloc(sizeof(FloatStack));
	newStack->data = f;
	newStack->next = stack;
	return newStack;
}

float pop(FloatStack **stack)
{
	float data = (*stack)->data;

	FloatStack *_stack = *stack;
	*stack = (*stack)->next;
	free(_stack);

	return data;
}

float eval(char *string)
{
	FloatStack *stack = NULL;

	for(int i = 0; string[i] != '\0';) {

		if(string[i] == '+' && stack != NULL && stack->next != NULL)
			;
		if(string[i] == '-' && stack != NULL && stack->next != NULL)
			;
		if(string[i] == '*' && stack != NULL && stack->next != NULL)
			;
		if(string[i] == '/' && stack != NULL && stack->next != NULL)
			;
		if(string[i] == '%' && stack != NULL && stack->next != NULL)
			;
		if(string[i] == '^' && stack != NULL && stack->next != NULL)
			;

		float num = 0, p = 1, sign = 1;
		if(string[i++] == '-')
			sign *= -1;
		while('0' <= string[i] && string[i] <= '9')
			num = num*10 + string[i++] - '0';
		if(string[i] == '.')
			while('0' <= string[++i] && string[i] <= '9')
				num = num + (string[i] - '0') * (p *= 0.1);
		stack = push(stack, num);
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

	eval("123.4 12 1233.45 1 12.001 12.0");
}

