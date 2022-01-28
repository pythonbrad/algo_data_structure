#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_WORD_LENGTH 255
#define MAX_FILENAME 255

struct Node {
	char data[MAX_WORD_LENGTH];
	unsigned short freq;
	unsigned int id;
	struct Node* right;
	struct Node* left;
} root_node;

unsigned int node_next_id = 0;

// This function permit to know is a character is a letter or not
// And lowerlize it
bool is_alpha(char* character) {
	// 0 to 255
	unsigned char id;
	char alphas[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for (id = 0; id < 52; id++) {
		if (alphas[id] == *character) {
			// We get the lower character
			*character = alphas[id % 26];
			return 1;
		} else {};
	};

	return 0;
};

// This function create a new node
struct Node* new_node() {
	struct Node* node = calloc(1, sizeof(struct Node));

	// We verify if memory allowed
	if (new_node == NULL) {
		fprintf(stderr, "No memory free to create a new node.\n");
		exit(-1);
	} else {
		// We assign the id
		node->id = ++node_next_id;
	};

	return node;
};

// This function insert a word in a node
void insert_word(char* word) {
	struct Node* curr_node = &root_node;
	while (1) {
		// We config the current node if empty
		if (curr_node->freq == 0) {
			strcpy(curr_node->data, word);
			curr_node->freq = 1;
			break;
		}
		// If the word is to left or right
		else if (strcmp(word, curr_node->data) < 0) {
			// We create a new node if the left node not exists
			if (curr_node->left == NULL) {
				curr_node->left = new_node();
			} else {};

			// We enter in this node
			curr_node = curr_node->left;
		} else if (strcmp(word, curr_node->data) > 0) {
			// We create a new node if the right node not exists
			if (curr_node->right == NULL) {
				curr_node->right = new_node();
			} else {};
			
			// We enter in this node
			curr_node = curr_node->right;
		}
		// If the word is already used, we increment his frequenciy
		else {
			curr_node->freq++;
			break;
		};
	};
};

// This function show the words from the last left to the last right word.
void print_tree(struct Node* node, bool header) {
	// We print the header
	if (header) {
		printf("%-10s %-30s %-10s\n", "S/N", "WORD", "FREQUENCY");
	} else {};

	// We print the left node
	if (node->left != NULL) {
		print_tree(node->left, 0);
	} else {};

	// We print the word of the current node
	printf("%-10d %-30s %-10d\n", node->id, node->data, node->freq);

	// We print the right node
	if (node->right != NULL) {
		print_tree(node->right, 0);
	} else {};
};

int main(int argc, char const *argv[]) {
	char filename[MAX_FILENAME] = "";
	// This variable permit to know if the word is already got
	bool word_get = 0;
	char curr_char;

	// 0 to 255
	unsigned char word_length = 0;
	char curr_word[MAX_WORD_LENGTH] = "";
	FILE* file;

	// We get the filename
	if (argc == 2) {
		// We get the filename by argument
		strcpy(filename, argv[1]);
	} else {
		// We get the filename by input
		printf("Enter the filename: ");
		scanf("%s", filename);
	};

	// We open the data
	file = fopen(filename, "r");

	// We read the file character by character
	while (1) {

		curr_char = fgetc(file);

		if (is_alpha(&curr_char)) {
			// We build the word
			curr_word[word_length++] = curr_char;
			curr_word[word_length] = '\0';
			word_get = 0;
		} else {

			// We get the word, if not already get and save it
			if (word_get == 0) {
				// We save the word
				insert_word(curr_word);
				word_get = 1;
				word_length = 0;
			} else {};
		};

		// We break if it's the end of the file
		if (curr_char == EOF) {
			break;
		} else {};
	};

	fclose(file);
	print_tree(&root_node, 1);

	return 0;
};