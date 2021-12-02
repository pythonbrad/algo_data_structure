/*
	Implementation of an dynamic Stack with linked list
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// We declare the node
typedef struct $ {
	int value;
	struct $ *next;
} Node;

// We init an node
Node *create() {
	Node *node = malloc(sizeof(Node));
	node->value = 0;
	node->next = NULL;
	return node;
}

// We add a value in the top of the stack
void push(Node *stack, int value) {
	// The prev position
	Node *prev = stack;
	// The current position
	Node *curr;
	// The next position
	Node *next;
	// We insert the current data between the prev position and the current
	curr = create();
	// We insert the value
	curr->value = value;
	// We backup the previous top
	next = prev->next;
	// We save the current top
	prev->next = curr;
	// We save the previous top
	curr->next = next;
}

// This function permit to know if the stack is empty of not
bool stackIsEmpty(Node *stack) {
	if (stack->next == NULL) {
		return true;
	} else {
		return false;
	}
}

// We pop the data at the top
int pop(Node *stack) {
	Node *curr = stack->next;
	int value;
	if(stackIsEmpty(stack)) {
		fprintf(stderr, "Overflow Error: The stack is empty\n");
		return 0;
	} else {
		value = curr->value;
		// We go to the next position
		stack->next = curr->next;
		// We free the old
		free(curr);
		return value;
	}
}

// We display the stack
void display(Node *stack) {
	Node *curr = stack;
	puts("---------");
	puts("| STACK |");
	puts("---------");
	puts("|  TOP  |");
	puts("---------");
	if (stack->next == NULL) {
		puts("| EMPTY |");
		puts("---------");
	} else {
		while((curr = curr->next) != NULL) {
			printf("|%7i|\n", curr->value);
			puts("--------");
		}
	}
}

int main() {
	Node *stack;
	int i;
	puts("# We create the stack...");
	stack = create();
	puts("# We push data in the stack...");
	for(i=0; i<5; i++) {
		printf("We pushed: %i\n", i);
		push(stack, i);
		display(stack);
		puts("");
	}
	puts("# We pop data in the stack...");
	for(i=0; i<7; i++) {
		printf("We poped: %i\n", pop(stack));
		display(stack);
		puts("");
	}
	return 0;
}