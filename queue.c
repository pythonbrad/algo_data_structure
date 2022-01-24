/*
	Implementation of an dynamic integer queue
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct $ {
	int end;
	int *datas;
} Queue;

// This function permit to create a queue
Queue *create() {

	// We init the queue
	Queue *queue = malloc(sizeof(Queue));

	// We init the end
	queue->end = -1;

	// We alloc memory
	queue->datas = calloc(1, sizeof(int));

	return queue;
}

// This function permit to push data in the queue
void enqueue(Queue *queue, int data) {
	int i;

	// We alloc memory to push this data
	queue->datas = realloc(queue->datas, (++queue->end + 1) * sizeof(int));

	// We shift all data in the right
	for(i=queue->end; i>0; i--) {
		queue->datas[i] = queue->datas[i-1];
	}

	// We save the data
	queue->datas[0] = data;
}

// This function permit to get the size of the queue
unsigned int sizeOfQueue(Queue *queue) {
	return queue->end + 1;
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
	return queue->datas[0];
}

// This function permit to get the data stored in the end
int endOfQueue(Queue *queue) {
	return queue->datas[queue->end];
}

// This function permit to remove the data in the end and return it
int dequeue(Queue *queue) {
	int head_data;

	// We verify if it's possible to pop
	if(!queueIsEmpty(queue)) {
		// We get the value in the head
		head_data = endOfQueue(queue);

		// We realloc memory to remove the data stored in the end
		queue->datas = realloc(queue->datas, queue->end-- * sizeof(int));

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
	printf("%10s\n", "|  END   |");
	printf("%10s\n", "----------");

	for(i=0; i<=queue->end && !queueIsEmpty(queue) ; i++) {
		printf("|%8i|\n", queue->datas[i]);
		printf("%10s\n", "----------");
	}

	if (i==0) {
		printf("%10s\n", "| EMPTY  |");
		printf("%10s\n", "----------");
	}

	printf("%10s\n", "|  HEAD  |");
	printf("%10s\n", "----------");
}

int main() {
	Queue *queue;
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