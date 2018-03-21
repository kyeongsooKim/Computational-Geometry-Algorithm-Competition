
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //EXIT_FAILURE

#define HEAP_LEN	100
typedef char HData;

//if priority of d1 is higher than d2, return value > 0,
//lower than d2, then return value < 0,
//same, then return value = 0;
typedef int Operator(HData d1, HData d2);

typedef struct _heap
{
	Operator * comp;
	int numOfData;
	HData heapArr[HEAP_LEN]; //heapArr[0] = dummy node.
} Heap;

void H_Init(Heap * bh, Operator op);
bool H_IsEmpty(Heap * bh);
HData H_Top(Heap * bh);//O(1)
void H_Push(Heap * bh, HData data); //O(logN)
HData H_Pop(Heap * bh); //O(logN)
int myComparator(HData d1, HData d2);


int main(void)
{
	Heap heap;
	H_Init(&heap, myComparator);

	H_Push(&heap, 'A');
	H_Push(&heap, 'B');
	H_Push(&heap, 'C');
	printf("%c \n", H_Pop(&heap));

	H_Push(&heap, 'A');
	H_Push(&heap, 'B');
	H_Push(&heap, 'C');
	printf("%c \n", H_Pop(&heap));

	printf("\nPop out in all the elements in heap : ");
	while (!H_IsEmpty(&heap))
		printf("%c \n", H_Pop(&heap));

	return 0;
}

int myComparator(HData d1, HData d2)
{
	if (d1 >= d2) // max heap
		return d1;
	return d2;
};

void H_Init(Heap * bh, Operator op) {
	bh->comp = op;
	bh->numOfData = 0;
}

bool H_IsEmpty(Heap * bh)
{
	if (bh->numOfData == 0)
		return true;
	else
		return false;
}

HData H_Top(Heap * bh)
{
	if (H_IsEmpty(bh)) {
		exit(EXIT_FAILURE);
	}
	return bh->heapArr[1];
}

int getParentIdx(int child)
{
	return child / 2 ;
}

int getLeftChildIdx(int parent)
{
	return parent * 2;
}

int getRightChildIdx(int parent)
{
	return parent * 2 + 1;
}

int getHiPriChildIdx(Heap * bh, int parent)
{
	if (getLeftChildIdx(parent) > bh->numOfData)
		return 0;
	else if (getLeftChildIdx(parent) == bh->numOfData)
		return getLeftChildIdx(parent);
	else
	{
		if (bh->comp(bh->heapArr[getLeftChildIdx(parent)],
			bh->heapArr[getRightChildIdx(parent)]) >= 0)
			return getLeftChildIdx(parent);
		else
			return getRightChildIdx(parent);
	}
}

void H_Push(Heap * bh, HData data) //O(logN)
{
	int idx = bh->numOfData + 1;

	while ( idx != 1)
	{
		if (bh->comp(data, bh->heapArr[getParentIdx(idx)]) > 0)
		{
			bh->heapArr[idx] = bh->heapArr[getParentIdx(idx)];
			idx = getParentIdx(idx);
		}
		else
			break;
	}

	bh->heapArr[idx] = data;
	(bh->numOfData)++;
}


HData H_Pop(Heap * bh) //O(logN)
{
	HData tmp = H_Top(bh);
	HData LastElem = bh->heapArr[bh->numOfData];
	int parentIdx = 1;
	int childIdx;

	while (childIdx = getHiPriChildIdx(bh, parentIdx))
	{
		if (bh->comp(LastElem, bh->heapArr[childIdx]) >= 0)
		{
			break;
		}
		
		bh->heapArr[parentIdx] = bh->heapArr[childIdx];
		parentIdx = childIdx;
	}

	bh->heapArr[parentIdx] = LastElem;
	(bh->numOfData)--;

	return tmp;
}

