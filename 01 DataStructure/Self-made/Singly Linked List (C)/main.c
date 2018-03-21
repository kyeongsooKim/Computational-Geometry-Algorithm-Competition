#include <stdio.h> //printf
#include <stdlib.h> //NULL, Malloc
#include <stdbool.h> //true, false


typedef struct _node {
	int data;
	struct _node * next;
} node;

typedef struct _dll {
	node * head;
	int numOfNode;
	node * itr;
} SinglyLinkedList;

typedef SinglyLinkedList list;

void init(list * l) {
	l->head = NULL;
	l->numOfNode = 0;
}

void push_front(list * l, int n) {
	node * newNode = (node *)malloc(sizeof(node));

	newNode->data = n;
	newNode->next = l->head;
	l->head = newNode;
	l->numOfNode++;
}

bool isEmpty(list l) {
	if (l.numOfNode == 0)
		return true;
	return false;
}

void itrPlus(list * l) {
	l->itr = l->itr->next;
}

node * erase(list * l, node * itr)
{
	if (l->head == NULL)
		exit(EXIT_FAILURE);


	if (itr == l->head)
		l->head = itr->next;
	else
	{
		node * prev = l->head;
		while (prev->next != itr)
			prev = prev->next;
		prev->next = itr->next;
	}
		

	node * retNode = itr->next;
	free(itr);
	l->numOfNode -= 1;
	return retNode;
}

void reverse_list(list * l) {

	node * prev;
	node * cur = l->head;
	node * tmp = cur->next;

	while (tmp != NULL)
	{
		prev = cur;
		cur = tmp;
		tmp = cur->next;
		cur->next = prev;
	}
	l->head->next = NULL;
	l->head = cur;
}

int main() {

	list l;
	init(&l);

	push_front(&l, 6);
	push_front(&l, 4);
	push_front(&l, 3);
	push_front(&l, 2);
	push_front(&l, 1);

	l.itr = l.head;
	l.itr = erase(&l, l.itr);
	itrPlus(&l);
	l.itr = erase(&l, l.itr);
	push_front(&l, 0);

	for (l.itr = l.head; l.itr != NULL; itrPlus(&l))
		printf("%d ", l.itr->data);

	reverse_list(&l);
	printf("\n\nafter reverse the direction : \n");
	for (l.itr = l.head; l.itr != NULL; itrPlus(&l))
		printf("%d ", l.itr->data);
	printf("\n");


	return 0;
}