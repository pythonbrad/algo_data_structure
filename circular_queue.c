/*
	Implementation of a static circular integer queue
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10

typedef struct $ {
	unsigned int head;
	int end;
	int datas[LENGTH];
} Queue;

// This function permit to create a queue
Queue *create() {
	// We init queue
	Queue *queue = malloc(sizeof(Queue));
	queue->head = 0;
	queue->end = -1;
	return queue;
}

// This function permit to get the size of the queue
unsigned int sizeOfQueue(Queue *queue) {
	return queue->end - queue->head + 1;
}

// This function permit to know if the queue is full or not
bool queueIsFull(Queue *queue) {
	if (sizeOfQueue(queue) == LENGTH) {
		return true;
	} else {
		return false;
	}
}

// This function permit to push data in the queue
void enqueue(Queue *queue, int data) {
	// We verify if it's possible to pop
	if(!queueIsFull(queue)) {
		// We save the data
		++queue->end;
		queue->datas[queue->end % LENGTH] = data;
	} else {
		printf("%i", queue->end);
		fprintf(stderr, "Overflow Error: The queue is full\n");
	}
}

// This function permit to know if the queue is empty of not
bool queueIsEmpty(Queue *queue) {
	if (sizeOfQueue(queue) == 0) {
		return true;
	} else {
		return false;
	}
}

// This function permit to get the data stored in the head
int headOfQueue(Queue *queue) {
	return queue->datas[queue->head % LENGTH];
}

// This function permit to get the data stored in the end
int endOfQueue(Queue *queue) {
	return queue->datas[queue->end % LENGTH];
}

// This function permit to remove the data in the end and return it
int dequeue(Queue *queue) {
	int head_data;
	// We verify if it's possible to pop
	if(!queueIsEmpty(queue)) {
		// We get the value in the head
		head_data = headOfQueue(queue);
		++queue->head;
		// We return the value removed
		return head_data;
	} else {
		fprintf(stderr, "Overflow Error: The queue is empty\n");
		return 0;
	}
}

// This function permit to display the queue
void display(Queue *queue) {
	unsigned int i;
	printf("%10s\n", "__________");
	printf("%10s\n", "| QUEUE  |");
	printf("%10s\n", "----------");
	for(i=0; i < ((queue->end < LENGTH) ? (queue->end+1) : LENGTH) && !queueIsEmpty(queue); i++) {
		if ((queue->head % LENGTH) == (queue->end % LENGTH) && (queue->head % LENGTH) == i) {
			printf("%10s\n", "|HEAD&END|");
			printf("%10s\n", "----------");
		} else if(i==(queue->head % LENGTH)) {
			printf("%10s\n", "|  HEAD  |");
			printf("%10s\n", "----------");
		} else if(i==(queue->end % LENGTH)) {
			printf("%10s\n", "|  END   |");
			printf("%10s\n", "----------");
		} else {};
		printf("|%8i|\n", queue->datas[i]);
		printf("%10s\n", "----------");
	}
	if (i==0) {
		printf("%10s\n", "| EMPTY  |");
		printf("%10s\n", "----------");
	}
}

int main() {
	int i;
	puts("# We create the queue...");
	Queue *queue = create();
	puts("# We enqueue data in the queue...");
	for(i=0; i<LENGTH+2; i++) {
		printf("We enqueue: %i\n", i);
		enqueue(queue, i);
		display(queue);
		puts("");
	}
	puts("# We dequeue data in the queue...");
	for(i=0; i<LENGTH+1; i++) {
		printf("We dequeued: %i\n", dequeue(queue));
		display(queue);
		puts("");
	}
	puts("# We enqueue data in the queue...");
	for(i=0; i<LENGTH/2; i++) {
		printf("We enqueue: %i\n", i+LENGTH);
		enqueue(queue, i+LENGTH);
		display(queue);
		puts("");
	}
	puts("# We dequeue data in the queue...");
	for(i=0; i<LENGTH/4; i++) {
		printf("We dequeued: %i\n", dequeue(queue));
		display(queue);
		puts("");
	}
	return 0;
}