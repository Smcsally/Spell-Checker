// bst.cpp

#include <cstdlib>
#include <iostream>
using namespace std;

class BinarySearchTree {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;
	};

	Node* root;

	// recursive function to insert at a particular node
	void insertAt(int number, Node*& node) {
		if (node == NULL) {
			node = new Node;
			node->data = number;
			node->left = NULL;
			node->right = NULL;
		}
		else if (node->data < number) {
			insertAt(number, node->right);
		}
		else {
			insertAt(number, node->left);
		}
	}

	// recursive function to search starting at a particular node it
	// returns a pointer to the node or NULL for not found
	Node*& searchAt(int number, Node*& node) {
		if (node == NULL) {
			return node;
		}
		else if (node->data == number) {
			return node;
		}
		else if (node->data < number) {
			return searchAt(number, node->right);
		}
		else {
			return searchAt(number, node->left);
		}
	}

	// find smallest node in a tree
	Node*& min(Node*& node) {
		// if the tree is empty there is no min
		if (node == NULL) {
			return node;
		}

		// if there are none to the left, return this one
		else if (node->left == NULL) {
			return node;
		}

		// if there are some to the left, smallest is there
		else {
			return min(node->left);
		}
	}

	// remove a particular node
	void removeNode(Node*& node) {
		// if the node we are removing has no children, just delete it!
		if ((node->left == NULL) && (node->right == NULL)) {
			delete node;
			node = NULL;
		}

		// if the node has one child, just skip over it!
		else if ((node->left == NULL) && (node->right != NULL)) {
			Node* rest = node->right;
			delete node;
			node = rest;
		}
		else if ((node->left != NULL) && (node->right == NULL)) {
			Node* rest = node->left;
			delete node;
			node = rest;
		}

		// if the node has 2 children, find the smallest in the right subtree
		// swap it, and delete smallest in right subtree
		else {
			Node*& least = min(node->right);
			int temp = least->data;
			least->data = node->data;
			node->data = temp;
			removeNode(least);
		}
	}

	// an in-order tree traversal
	void inorder(Node* node) const {
		if (node != NULL) {
			inorder(node->left);
			cout << node->data << endl;
			inorder(node->right);
		}
	}

public:
	// set the whole tree to NULL
	BinarySearchTree() {
		root = NULL;
	}

	// insert a number calls recursive function to insert at the root
	void insert(int number) {
		insertAt(number, root);
	}

	// search for a number in the tree
	int* search(int number) {
		Node* target = searchAt(number, root);
		if (target == NULL) {
			return NULL;
		}
		else {
			return &target->data;
		}
	}

	// remove a particular data item from the tree
	void remove(int number) {
		Node*& to_remove = searchAt(number, root);
		if (to_remove != NULL) {
			removeNode(to_remove);
		}
	}

	// print the nodes inorder
	void print() const {
		inorder(root);
	}
};

int main() {
	BinarySearchTree tree;

	// build a BST from a set of numbers
	int nums[] = { 32, 12, 44, 99, 76, 36, 9, 81, 65, 72 };
	for (int i = 0; i < 10; i++) {
		tree.insert(nums[i]);
	}

	// print it out
	cout << "Original tree:" << endl;
	tree.print();

	// remove some nodes
	tree.remove(9);
	tree.remove(44);
	tree.remove(65);

	// print it out
	cout << "After removing nodes:" << endl;
	tree.print();

	return 0;
}
