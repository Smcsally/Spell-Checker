// bst.cpp

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include "String.h"
using namespace std;

template <typename type>
class BinarySearchTree {
private:
	struct Node {
		type data;
		Node* left;
		Node* right;
	};

	Node* root;

	// recursive function to insert at a particular node
	void insertAt(type number, Node*& node) {
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
	Node*& searchAt(type number, Node*& node) {
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
			type temp = least->data;
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

	int recursiveHeight(Node* node) const{
		int count = 1;
		if (node == 0) {
			return 0;
		}

		int left = recursiveHeight(node->left);
		int right = recursiveHeight(node->right);

		if (left > right) {
			return 1 + left;
		}	
		else {
			return 1 + right;
		}
	}

public:
	// set the whole tree to NULL
	BinarySearchTree() {
		root = NULL;
	}

	// insert a number calls recursive function to insert at the root
	void insert(type number) {
		insertAt(number, root);
	}

	// search for a number in the tree
	type* search(type number) {
		Node* target = searchAt(number, root);
		if (target == NULL) {
			return NULL;
		}
		else {
			return &target->data;
		}
	}

	// remove a particular data item from the tree
	void remove(type number) {
		Node*& to_remove = searchAt(number, root);
		if (to_remove != NULL) {
			removeNode(to_remove);
		}
	}

	// print the nodes inorder
	void print() const {
		inorder(root);
	}

	//return the height of the tree
	int height() const {
		return recursiveHeight(root);
	}
};

int main(int argc, char* argv[]) {
	BinarySearchTree<String> tree;
	char filename[50];
	char user_input[100];
	if (argc < 1) {
		cout << "Error, no parameter.  1 parameter must be supplied with the name of the dictionary file." << endl;
	}
	else if (argc > 2) {
		cout << "Error, too many parameters.  1 parameter must be supplied with the name of the dictionary file." << endl;
	}
	else {
		strcpy(filename, argv[1]);

		char temp[100];
		//open the input stream
		ifstream fin(filename);
		if (fin.is_open()) {
			// the file opened fine! Set our first client to the first line in the file
			fin >> temp;
		}
		String word(temp);
		
		//insert all words into the tree
		while (word.length() > 0) {
			tree.insert(word);
			fin >> temp;
			String t(temp);
			word = t;
		}

		int height = tree.height();
		cout << "All words successfully inserted into the tree! It has " << height << " levels" << endl;
		cout << "Please enter a sentence: ";
		cin.getline(user_input, 100);

		char temp1[50];
		char temp2[50];
		for (int i = 0; i < strlen(user_input); i++) {
			while () {
				cout << index << endl;
			}
			/*if (strcmp(user_input, "\n") == 0) {
				break;
			}
			
			String temp(user_input);
			if (tree.search(temp) == NULL) {
				cout << temp << " is spelled wrong!" << endl;
			}
			else {
				cout << temp << " ";
			}*/
		}
		cin >> user_input;
		cin >> user_input;
	}

	/*// build a BST from a set of numbers
	type nums[] = { 32, 12, 44, 99, 76, 36, 9, 81, 65, 72 };
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
	tree.print();*/

	return 0;
}
