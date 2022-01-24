/*
	Implementation of an dynamic Array
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/

#include <stdio.h>
#include <malloc.h>


// We declare the Node
typedef struct $ {
	int value;
	struct $ *next;
} Node;

// We init an Node
Node *init_array() {
	Node *arr = malloc(sizeof(Node));
	arr->value = 0;
	arr->next = NULL;

	return arr;
}

// We add a value in the end of the Array
void append(Node *arr, int value) {
	// The curent position
	Node *curr = arr;

	// We go to the end
	while(curr->next != NULL) {
		curr = curr->next;
	}

	// We insert the value at the next position
	curr->next = init_array();
	curr->next->value = value;
}

// We insert a value in a specific position
void insert(Node *arr, int value, unsigned int pos) {
	// The prev position
	Node *prev = arr;

	// The current position
	Node *curr;

	// The next position
	Node *next;

	// We go to the position
	while(pos > 0) {
		prev = prev->next;
		pos--;
	}

	// We insert the current data between the prev position and the current
	curr = init_array();

	// We insert the value
	curr->value = value;

	// We backup the previous next position
	next = prev->next;

	// We save the current next position
	prev->next = curr;

	// We save the previous next position
	curr->next = next;
}

// We pop the data at the beginning
int pop(Node *arr) {
	Node *curr = arr->next;
	int value = curr->value;

	// We go to the next position
	arr->next = curr->next;

	// We free the old
	free(curr);

	return value;
}

// We remove the data at a specific position
void _remove(Node *arr, unsigned int pos) {
	// The prev position
	Node *prev = arr;

	// The current position
	Node *curr;

	// The next position
	Node *next;

	// We go to the position
	while(pos > 0) {
		prev = prev->next;
		pos--;
	}

	// We remove the data
	curr = prev->next;
	prev->next = curr->next;

	free(curr);
}

// We show the Array
void show(Node *arr) {
	Node *curr = arr;

	while((curr = curr->next) != NULL) {
		printf("%i\n", curr->value);
	}
}

int main() {
	Node *arr = init_array();

	append(arr, 2);
	append(arr, 7);
	append(arr, 1);
	insert(arr, 4, 1);
	append(arr, 5);

	show(arr);

	puts("pop");
	pop(arr);
	show(arr);

	puts("remove");
	_remove(arr, 1);
	_remove(arr, 1);
	show(arr);
	
	printf("ok\n");
	return 0;
}