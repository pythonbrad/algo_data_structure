/*
	Implementation of an sequential search using linked list
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/

#include <stdio.h>
#include <malloc.h>

// We define our node structure
typedef struct $ {
	int value;
	struct $ *next;
} Node;

// This function create a node
Node *create() {
	Node *node = malloc(sizeof(Node));
	node->value = 0;
	node->next = NULL;
	return node;
}

// This function permit to insert an element in our linked list
void insert(Node *root_node, int value) {
	Node *curr_node = root_node;

	// We go to the last node
	while(curr_node->next != NULL) {
		curr_node = curr_node->next;
	}

	// We insert the value
	curr_node->next = create();
	curr_node->next->value = value;
}

// This function permit to search an element in a linked list
// put the search item in the top of the list
Node *search1(Node *root_node, int element) {
	int i;

	Node *curr_node = root_node;

	// We verify if the element is present in the linked list 
	while(curr_node->next != NULL) {
		if(curr_node->next->value == element) {
			// We put the search item in the top
			curr_node->next->value = root_node->next->value;
			root_node->next->value = element;
			return curr_node->next;
		} else {
			curr_node = curr_node->next;
		}
	}

	// In this point, the element is not found
	return NULL;
}

// This function permit to search an element in a linked list
// advance the search item one step toward the top of the list
Node *search2(Node *root_node, int element) {
	int i;

	Node *curr_node = root_node;

	// We verify if the element is present in the linked list 
	while(curr_node->next != NULL) {
		if(curr_node->next->value == element) {
			// If the element is locate to the first node, no need to advance
			if(curr_node==root_node) {
				return curr_node->next;
			} else {
				// We advance the search item
				curr_node->next->value = curr_node->value;
				curr_node->value = element;
				return curr_node->next;
			}
		} else {
			curr_node = curr_node->next;
		}
	}

	// In this point, the element is not found
	return NULL;
}

int main() {
	int i;

	// We create the root_node
	Node *root_node = create();

	// We build our linked list
	for(i=0; i<100; i++) {
		insert(root_node, i);
	}

	printf("31 found at the node %p\n", search1(root_node, 31));
	printf("31 found at the node %p\n", search1(root_node, 31));
	printf("31 found at the node %p\n", search1(root_node, 31));
	printf("41 found at the node %p\n", search2(root_node, 41));
	printf("41 found at the node %p\n", search2(root_node, 41));
	printf("41 found at the node %p\n", search2(root_node, 41));
	printf("41 found at the node %p\n", search2(root_node, 41));
	printf("41 found at the node %p\n", search2(root_node, 41));
	printf("41 found at the node %p\n", search2(root_node, 41));
	printf("41 found at the node %p\n", search2(root_node, 41));
	printf("41 found at the node %p\n", search2(root_node, 41));
	
	return 0;
}