#include <iostream>
#include <vector>
#include <algorithm> //make_heap()
#include <functional> //greater<int>
#include <cstdbool>
using namespace std;

class minHeap
{
	vector<char> heap;
public :
	void init()
	{
		// Converting vector into a heap using make_heap()
		make_heap(heap.begin(), heap.end(), greater<char>());
	}

	char Top()
	{
		return heap.front();
	}

	void Push(char val)
	{
		heap.push_back(val); 	// Enter element to the end of the vector.
		push_heap(heap.begin(), heap.end(), greater<char>()); // Reorder elements.
	}

	char Pop() {
		int val = Top();

		//Move the smallest element to the end of the vector
		pop_heap(heap.begin(), heap.end(), greater<int>());

		//Remove the last element from vector, which is the smallest element
		heap.pop_back();
		return val;
	}

	bool isEmpty() {
		if (heap.empty())
			return true;
		return false;
	}
};



int main()
{
	minHeap heap;
	heap.init();

	
	heap.Push('A');
	heap.Push('B');
	heap.Push('C');
	cout << "The minimum element of heap is : " << heap.Pop() << endl;

	heap.Push('A');
	heap.Push('B');
	heap.Push('C');
	cout << "The minimum element of heap is : " << heap.Pop() << endl;
	
	cout << "Pop out in all the elements in heap : ";
	while (!heap.isEmpty())
	{
		cout << heap.Pop() << " ";
	}
		


}