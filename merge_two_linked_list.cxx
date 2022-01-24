#include <iostream>

using namespace std;

int main() {
	class Node {
		public:
			int val;
			Node *next;
			Node (int _val, Node *_next=0) {
				val = _val;
				next = _next;
			};
			Node *mergeTwoLists(Node *a, Node *b) {
				if (a && b) {
					if (a->val < b->val) {
						return new Node(a->val, mergeTwoLists(b, a->next));
					} else {
						return new Node(b->val, mergeTwoLists(a, b->next));
					};
				} else {
					if (a) {
						return a;
					} else {
						return b;
					};
				};
			};
	};
	Node node1(1);
	node1.next = new Node(3);
	node1.next->next = new Node(5);
	Node node2(2);
	
	node2.next = new Node(4);
	node2.next->next = new Node(6);
	Node *node3;
	node3 = node3->mergeTwoLists(&node1, &node2);

	while (node3) {
		cout << node3->val << " ";
		node3 = node3->next;
	};
};
