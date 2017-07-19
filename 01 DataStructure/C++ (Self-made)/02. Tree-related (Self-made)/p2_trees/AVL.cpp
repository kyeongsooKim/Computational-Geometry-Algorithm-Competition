
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

protected:
	Node<T> *root;

	virtual void insertHelper(Node<T> ** root, T val) {
		if (*root == NULL) {
			*root = new Node<T>(val);
		}
		else if ((*root)->value > val) {
			insertHelper(&((*root)->left), val);	
		}
		else if ((*root)->value < val) {
			insertHelper(&((*root)->right), val);
		}
		else {
			cerr << "no same key value" << endl;
		}
	}

	virtual bool removeHelper(Node<T>* parent, Node<T>* current, T value) {
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

	void printHelper(Node<T> *root) { //inorder
		if (!root)
			return;
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

public:
	void insert(T val) {
		cout << "insert : " << val << endl;
		this->insertHelper(&root, val);
	}

	bool remove(T val) {
		cout << "remove : " << val << endl;
		return this->removeHelper(NULL, this->root, val);
	}

	void printNodes() {

		if (this->root == NULL) {
			cout << "no node exists" << endl;
			return;
		}
		else {
			cout << "Nodes: ";
			printHelper(this->root);
		}
		
	}

	int nodesCount() {
		return nodesCountHelper(root);
	}

	int height() {
		return heightHelper(this->root);
	}

	int height(Node<T> * root) {
		return heightHelper(root);
	}

	void printMaxPath() {
		printMaxPathHelper(this->root);
	}

	int getHeightDiff() {
		int lsh; //left subtree height
		int rsh; //right subtree height

		if (this->root == NULL)
			return 0;
		lsh = height(this->root->left);
		rsh = height(this->root->right);

		return lsh - rsh; // balance factor
	}

	int getHeightDiff(Node<T> * root) {
		int lsh; //left subtree height
		int rsh; //right subtree height

		if (root == NULL)
			return 0;
		lsh = height(root->left);
		rsh = height(root->right);

		return lsh - rsh; // balance factor
	}

};

template <class T>
class AVL : public BST<T> {

private:
	//overriding
	void insertHelper(Node<T> ** root, T val) {
		if (*root == NULL) {
			*root = new Node<T>(val);
		}
		else if((*root)->value > val) {
			insertHelper(&((*root)->left), val);
			*root= rebalance(root); //add rebalancing process.	
		}
		else if ((*root)->value < val) {
			insertHelper(&((*root)->right), val);
			*root = rebalance(root); //add rebalancing process.	
		}
		else {
			cerr << "no same key value" << endl;
		}
	}

	//overriding
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
			rebalance(&root); //add rebalancing process.
			return true;
		}
		return removeHelper(current, current->left, value) ||
			removeHelper(current, current->right, value);
	}

	Node<T> * rotateLL(Node<T> * root) {
		Node<T> * pNode;
		Node<T> * cNode;

		pNode = root;
		cNode = pNode->left;

		pNode->left = cNode->right;
		cNode->right = pNode;
		return cNode;
	}

	Node<T> * rotateRR(Node<T> * root) {
		Node<T> * pNode;
		Node<T> * cNode;

		pNode = root;
		cNode = pNode->right;

		pNode->right = cNode->left;
		cNode->left = pNode;
		return cNode;
	}

	Node<T> * rotateLR(Node<T> * root) {
		Node<T> * pNode;
		Node<T> * cNode;

		pNode = root;
		cNode = pNode->left;

		//make LL first using partial rotateRR
		pNode->left = rotateRR(cNode);
		return rotateLL(pNode);
	}

	Node<T> * rotateRL(Node<T> * root) {
		Node<T> * pNode;
		Node<T> * cNode;

		pNode = root;
		cNode = pNode->right;

		//make RR first using partial rotateLL
		pNode->right = rotateLL(cNode);
		return rotateRR(pNode);
	}

public:
	Node<T> * rebalance(Node<T> ** root) {
		int hDiff = getHeightDiff(*root);

		//if tree is inclined leftward with more than 2 of balcance factor
		if (hDiff > 1)  
		{
			if (getHeightDiff((*root)->left) > 0)
				*root = rotateLL(*root);
			else
				*root = rotateLR(*root);
			cout << "rebalance process done" << endl;
		}

		//if tree is inclined rightward with more than 2 of balcance factor
		if (hDiff < -1)  
		{
			if (getHeightDiff((*root)->right) < 0)
				*root = rotateRR(*root);
			else
				*root = rotateRL(*root);
			cout << "rebalance process done" << endl;
		}

		return *root;
	}


};

int main() {

	cout << "AVL example\n\n";
	AVL<int> *avl = new AVL<int>();
	avl->insert(11); //root
	avl->insert(1);
	avl->insert(6);
	avl->insert(-1);
	avl->insert(-10);
	avl->insert(100);

	cout << "\n"; avl->printNodes();

	cout << "\nNodes count: " << avl->nodesCount() << endl;

	cout << "Height: " << avl->height() << endl;

	cout << "Height Difference: " << avl->getHeightDiff() << endl;

	cout << "Max path: "; avl->printMaxPath(); cout << "\n\n";

	avl->remove(11);
	avl->remove(100); 
	avl->remove(-1); 
	avl->remove(6);  
	avl->remove(-10); 
	avl->remove(1);  

	cout << "\n----------------------------------------------------------\n";
	cout << "BST example\n\n";

	BST<int> * bst = new BST<int>();
	bst->insert(11); //root
	bst->insert(1);
	bst->insert(6);
	bst->insert(-1);
	bst->insert(-10);
	bst->insert(100);

	cout << "\n"; bst->printNodes();

	cout << "\nNodes count: " << bst->nodesCount() << endl;

	cout << "Height: " << bst->height() << endl;

	cout << "Height Difference: " << bst->getHeightDiff() << endl;

	cout << "Max path: "; bst->printMaxPath(); cout << endl;

	bst->remove(11);
	bst->remove(1);
	bst->remove(-1);
	bst->remove(6);
	bst->remove(-10);
	bst->remove(100);
	return 0;
}


