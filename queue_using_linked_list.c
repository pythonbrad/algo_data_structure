/*
	Implementation of an dynamic Queue with linked list
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// We declare the Node
typedef struct $ {
	int value;
	struct $ *next;
} Node;

// We init an Node
Node *create() {
	Node *node = malloc(sizeof(Node));
	node->value = 0;
	node->next = NULL;
	return node;
}

// We add a value in the end of the Queue
void enqueue(Node *queue, int value) {
	// The curent position
	Node *curr = queue;

	// We go to the end
	while(curr->next != NULL) {
		curr = curr->next;
	}

	// We insert the value at the next position
	curr->next = create();
	curr->next->value = value;
}

// This function permit to know if the queue is empty of not
bool queueIsEmpty(Node *queue) {
	if (queue->next == NULL) {
		return true;
	} else {
		return false;
	}
}

// We dequeue the data at the head
int dequeue(Node *queue) {
	Node *curr = queue->next;
	int value;

	if(queueIsEmpty(queue)) {
		fprintf(stderr, "Overflow Error: The queue is empty\n");
		return 0;
	} else {
		value = curr->value;

		// We go to the next position
		queue->next = curr->next;

		// We free the old
		free(curr);

		return value;
	}
}

// We display the Queue
void display(Node *queue) {
	Node *curr = queue;
	puts("---------");
	puts("| Queue |");
	puts("---------");
	puts("| HEAD  |");
	puts("---------");

	if (queue->next == NULL) {
		puts("| EMPTY |");
		puts("---------");
	} else {
		while((curr = curr->next) != NULL) {
			printf("|%7i|\n", curr->value);
			puts("--------");
		}
	}

	puts("|  END  |");
	puts("---------");
}

int main() {
	Node *queue;
	int i;

	puts("# We create the queue...");
	queue = create();

	puts("# We enqueue data in the queue...");
	for(i=0; i<5; i++) {
		printf("We enqueue: %i\n", i);
		enqueue(queue, i);
		display(queue);
		puts("");
	}

	puts("# We dequeue data in the queue...");
	for(i=0; i<7; i++) {
		printf("We dequeued: %i\n", dequeue(queue));
		display(queue);
		puts("");
	}
	
	return 0;
}