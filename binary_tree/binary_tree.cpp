#include <iostream>
#include <fstream>
using namespace std;

class Node {
	public:
		string data;
		unsigned short freq;
		Node* left;
		Node* right;
		
		Node() {
			// We init datas
			this->data = "";
			this->freq = 0;
			this->left = NULL;
			this->right = NULL;
		};

		// This module insert a word
		void insert(string word) {
			// We analyse the position of the word
			if (this->freq == 0) {
				this->data = word;
				this->freq = 1;
			} else if (word.compare(this->data) < 0) {
				// if the left node not exists, we create it
				if (!this->left) {
					this->left = new Node();
				} else {};
				// We enter in this node
				this->left->insert(word);
			} else if (word.compare(this->data) > 0) {
				// if the right node not exists, we create it
				if (!this->right) {
					this->right = new Node();
				} else {};
				// We enter in this node
				this->right->insert(word);
			} else {
				// We increment the frequency
				this->freq++;
			};
		};

		// This module print the branch of this node
		void print() {
			// We print the left node if exists
			if (this->left) {
				this->left->print();
			};

			cout << this->data << endl;

			// We print the right if exists
			if (this->right) {
				this->right->print();
			};
		};
};

int main () {
	// We declare a pointet to the root node
	Node* tree_root = new Node;

	// We variable wil contains the character to analyse
	char curr_char;

	// This variable will  contains the word to analyse
	string curr_word = "";

	// This variable permit to know if the word can be got or not
	bool word_got = 0;

	// We the declare the file pointer
	ifstream file;

	// We open the file
	file.open("complete-shakespeare.txt", ios::app);

	// We analyse the content of the file
	while (1) {
		file.read(&curr_char, 1);

		// We build the word just with letters
		if (isalpha(curr_char)) {
			curr_word = curr_word + curr_char;
			word_got = 1;
		} else {
			// If the word not yet got, we insert it in the tree
			if (word_got) {
				tree_root->insert(curr_word);
				/// We mark the word get and empty the word
				word_got = 0;
				curr_word = "";
			} else {};
		};

		// We end the loop if all characters is got
		if (file.eof()) {
			break;
		} else {};
	};

	// We print the binary tree
	tree_root->print();

	file.close();

	return 0;
};