/*
#include <iostream>
#include <algorithm> // for max()
using namespace std;

template <class T>
struct Node {
	T value;
	Node *left;
	Node *right;

	Node(T val) {
		this->value = val;
		this->left = NULL;
		this->right = NULL;
	}

	Node(T val, Node<T> left, Node<T> right) {
		this->value = val;
		this->left = left;
		this->right = right;
	}
};

template <class T>
class BST {

private:
	Node<T> *root;

	void insertHelper(Node<T> *root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				insertHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				insertHelper(root->right, val);
			}
		}
	}

	void printHelper(Node<T> *root) { //inorder
		if (!root) return;
		printHelper(root->left);
		cout << root->value << ' ';
		printHelper(root->right);
	}

	int nodesCountHelper(Node<T> *root) {
		if (!root) return 0;
		else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
	}

	int heightHelper(Node<T> *root) {
		if (!root) return 0;
		else return 1 + max(heightHelper(root->left), heightHelper(root->right));
	}

	void printMaxPathHelper(Node<T> *root) {
		if (!root) return;
		cout << root->value << ' ';
		if (heightHelper(root->left) > heightHelper(root->right)) {
			printMaxPathHelper(root->left);
		}
		else {
			printMaxPathHelper(root->right);
		}
	}

	bool removeHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == NULL || current->right == NULL) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else { //when current node is root node
					this->root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return removeHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return removeHelper(current, current->left, value) ||
			removeHelper(current, current->right, value);
	}

public:
	void insert(T val) {
		if (root) {
			this->insertHelper(root, val);
		}
		else {
			root = new Node<T>(val);
		}
	}

	void printNodes() {
		printHelper(this->root);
	}

	int nodesCount() {
		return nodesCountHelper(root);
	}

	int height() {
		return heightHelper(this->root);
	}

	void printMaxPath() {
		printMaxPathHelper(this->root);
	}

	bool remove(T value) {
		return this->removeHelper(NULL, this->root, value);
	}
};

int main() {
	BST<int> *bst = new BST<int>();
	bst->insert(11); //root
	bst->insert(1);
	bst->insert(6);
	bst->insert(-1);
	bst->insert(-10);
	bst->insert(100);
	bst->printNodes();
	cout << endl;
	cout << "Nodes count: " << bst->nodesCount();
	cout << endl;
	cout << "Height: " << bst->height();
	cout << endl;
	cout << "Max path: ";
	bst->printMaxPath();
	cout << endl;
	bst->remove(11);
	cout << "11 removed: ";
	bst->printNodes();
	cout << endl;
	cout << "1 removed: ";
	bst->remove(1);
	bst->printNodes();
	cout << endl;
	cout << "-1 removed: ";
	bst->remove(-1);
	bst->printNodes();
	cout << endl;
	cout << "6 removed: ";
	bst->remove(6);
	bst->printNodes();
	cout << endl;
	cout << "-10 removed: ";
	bst->remove(-10);
	bst->printNodes();
	cout << endl;
	cout << "100 removed, node count:	 ";
	bst->remove(100);
	cout << bst->nodesCount() << endl;
	return 0;
}


*/