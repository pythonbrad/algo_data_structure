/*
	Implementation of an dynamic integer stack
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct $ {
	unsigned int top;
	int *datas;
} Stack;

// This function permit to create a stack
Stack *create() {
	// We init the stack
	Stack *stack = malloc(sizeof(Stack));

	// We init the top
	stack->top = 0;

	// We alloc memory
	stack->datas = calloc(1, sizeof(int));

	return stack;
}

// This function permit to push data in the stack
void push(Stack *stack, int data) {
	// We alloc memory to push this data
	stack->datas = realloc(stack->datas, (++stack->top + 1) * sizeof(int));

	// We save the data
	stack->datas[stack->top] = data;
}

// This function permit to get the size of the stack
unsigned int sizeOfStack(Stack *stack) {
	return stack->top;
}

// This function permit to know if the stack is empty of not
bool stackIsEmpty(Stack *stack) {
	if (sizeOfStack(stack) == 0) {
		return true;
	} else {
		return false;
	}
}

// This function permit to get the data stored in the top
int topOfStack(Stack *stack) {
	return stack->datas[stack->top];
}

// This function permit to remove the data in the top and return it
int pop(Stack *stack) {
	// We verify if it's possible to pop
	if(!stackIsEmpty(stack)) {
		// We get the value in the top
		int top_data = topOfStack(stack);

		// We realloc memory to remove the value in the top
		stack->datas = realloc(stack->datas, --stack->top * sizeof(int));

		// We return the value removed
		return top_data;
	} else {
		fprintf(stderr, "Overflow Error: The stack is empty\n");
		return 0;
	}
}

// This function permit to display the stack
void display(Stack *stack) {
	unsigned int i;
	printf("%10s\n", "__________");
	printf("%10s\n", "| STACK  |");
	printf("%10s\n", "----------");

	for(i=1; i<=stack->top; i++) {
		printf("|%8i|\n", stack->datas[i]);
		printf("%10s\n", "----------");
	}

	if (i==1) {
		printf("%10s\n", "| EMPTY  |");
		printf("%10s\n", "----------");
	}

	printf("%10s\n", "|  TOP   |");
	printf("%10s\n", "----------");
}

int main() {
	Stack *stack;
	int i;

	puts("# We create the stack...");
	stack = create();

	puts("# We push data in the stack...");
	for(i=0; i<5; i++) {
		printf("We push: %i\n", i);
		push(stack, i);
		display(stack);
		puts("");
	}

	puts("# We remove data in the stack...");
	for(i=0; i<7; i++) {
		printf("We poped: %i\n", pop(stack));
		display(stack);
		puts("");
	}
	
	return 0;
}