#include <stdio.h> //printf
#include <stdlib.h> //NULL, Malloc
#include <stdbool.h> //true, false


typedef struct _node {
	int data;
	struct _node * next;
	struct _node * prev;
} node;

typedef struct _dll {
	node * head;
	//node * tail;
	int numOfNode;
	node * itr;
} list;

void init(list * l) {
	l->head = NULL;
	//l->tail = NULL;
	l->numOfNode = 0;
}

void push_front(list * l, int n) {
	node * newNode = (node *)malloc(sizeof(node));
	
	newNode->data = n;
	newNode->next = l->head;
	newNode->prev = NULL;
	if (l->head != NULL)
		l->head->prev = newNode;
	l->head = newNode;

	l->numOfNode++;
}

void insert_after(list * l, int n) {

}

bool isEmpty(list l){
	if (l.numOfNode == 0)
		return true;
	return false;
}

void itrPlus(list * l) {
	l->itr = l->itr->next;
}

void itrMinus(list * l) {
	l->itr = l->itr->prev;
}

node * erase(list * l, node * itr)
{
	if (l->head == NULL)
		exit(EXIT_FAILURE);

	if (itr == l->head)
		l->head = itr->next;

	if (itr->next != NULL)
		itr->next->prev = itr->next;

	if(itr->prev != NULL)
		itr->prev->next = itr->next;

	node * retNode = itr->next;
	free(itr);
	l->numOfNode -= 1;
	return retNode;
}


int main() {

	list l;
	init(&l);

	
	push_front(&l, 4);
	push_front(&l, 3);
	push_front(&l, 2);
	push_front(&l, 1);

	l.itr = l.head;
	l.itr = erase(&l, l.itr);
	itrPlus(&l);
	l.itr = erase(&l, l.itr);
	
	for (l.itr = l.head; l.itr != NULL; itrPlus(&l))
		printf("%d ", *(l.itr));


	return 0;
}