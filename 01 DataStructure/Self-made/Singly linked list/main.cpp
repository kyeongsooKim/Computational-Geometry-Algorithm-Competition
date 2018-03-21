#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;

	node(int n) : data(n), next(NULL) {}
};

class SinglyLinkedList
{
private:
	node* head;
public:
	SinglyLinkedList() : head(NULL) {};
	void Insert(int n);
	node* Search(int n, node** previousNode);
	bool Delete(int n);
	void Print();
};

void SinglyLinkedList::Insert(int n) {

}

int main() {

	SinglyLinkedList list;
	list.Insert(1);
	list.Insert(2);
	list.Insert(3);

	cout << "Print List : ";
	list.Print();

	cout << endl << "Check if Search Activates" << endl;
	cout << "Result for 1 : " << list.Search(1) << endl;
	cout << "Result for 4 : " << list.Search(4) << endl;

	cout << endl << "Result for Deleting 4 : " << list.Delete(4) << endl;
	cout << "Result for Deleting 2 : " << list.Delete(2) << endl;
	cout << "Print List : ";
	list.Print();

	cout << endl << "Result for Deleting 1 : " << list.Delete(1) << endl;
	cout << "Print List : ";
	list.Print();

	cout << endl << "Result for Deleting 3 : " << list.Delete(3) << endl;
	cout << "Result for Deleting 3 : " << list.Delete(3) << endl;
	cout << "Print List : ";
	list.Print();

	return 0;
}