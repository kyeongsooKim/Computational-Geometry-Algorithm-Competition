/*
#include <iostream>


using namespace std;

template <class T>
struct Node {
	T value;
	Node *left;
	Node *right;

	Node() {
		this->left = NULL;
		this->right = NULL;
	}

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

public:

	Node<T> * MakeNode()
	{

		Node<T> * nd = new Node<T>();
		nd->left = NULL;
		nd->right = NULL;
		return nd;
	}

	Node<T> * MakeNode(T val)
	{

		Node<T> * nd = new Node<T>(val);
		nd->left = NULL;
		nd->right = NULL;
		return nd;
	}

	T GetData(Node<T> * bt)
	{
		return bt->value;
	}

	void SetData(Node<T> * bt, T data)
	{
		bt->value = data;
	}

	Node<T> * GetLeftSubTree(Node<T> * bt)
	{
		return bt->left;
	}

	Node<T> * GetRightSubTree(Node<T> * bt)
	{
		return bt->right;
	}

	void MakeLeftSubTree(Node<T> * main, Node<T> * sub)
	{
		if (main->left != NULL)
			free(main->left);

		main->left = sub;
	}

	void MakeRightSubTree(Node<T> * main, Node<T> * sub)
	{
		if (main->right != NULL)
			free(main->right);

		main->right = sub;
	}

	void PreorderTraverse(Node<T> * bt, void(*action)(T))
	{
		if (bt == NULL)
			return;

		action(bt->value);
		PreorderTraverse(bt->left, action);
		PreorderTraverse(bt->right, action);
	}

	void InorderTraverse(Node<T> * bt, void(*action)(T))
	{
		if (bt == NULL)
			return;

		InorderTraverse(bt->left, action);
		action(bt->value);
		InorderTraverse(bt->right, action);
	}

	void PostorderTraverse(Node<T> * bt, void(*action)(T))
	{
		if (bt == NULL)
			return;

		PostorderTraverse(bt->left, action);
		PostorderTraverse(bt->right, action);
		action(bt->value);
	}

	void DeleteTree(Node<T> * bt)
	{
		if (bt == NULL)
			return;

		DeleteTree(bt->left);
		DeleteTree(bt->right);

		cout << "del tree data: " << bt->value << endl;
		delete bt;
	}


};

template <class T>
void ShowIntData(T data)
{
	printf("%d ", data);
}


int main(void)
{
	BST<int> *bst = new BST<int>();
	
	Node<int> * bt1 = bst->MakeNode(1);
	Node<int> * bt2 = bst->MakeNode(2);
	Node<int> * bt3 = bst->MakeNode(3);
	Node<int> * bt4 = bst->MakeNode();
	Node<int> * bt5 = bst->MakeNode();
	Node<int> * bt6 = bst->MakeNode();

	bst->SetData(bt4, 4);
	bst->SetData(bt5, 5);
	bst->SetData(bt6, 6);

	bst->MakeLeftSubTree(bt1, bt2);
	bst->MakeRightSubTree(bt1, bt3);
	bst->MakeLeftSubTree(bt2, bt4);
	bst->MakeRightSubTree(bt2, bt5);
	bst->MakeRightSubTree(bt3, bt6);

	cout << "preorder traverse : ";
	bst->PreorderTraverse(bt1, ShowIntData);
	cout << endl;

	cout << "inorder traverse : ";
	bst->InorderTraverse(bt1, ShowIntData);
	cout << endl;

	cout << "postorder traverse : ";
	bst->PostorderTraverse(bt1, ShowIntData);
	cout << "\n\n";

	bst->DeleteTree(bt1); // insert the root node.

	return 0;
}


*/