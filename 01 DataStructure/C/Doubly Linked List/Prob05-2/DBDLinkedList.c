typedef struct _list{
	node * head;
	int numOfdata;
} list;

typedef struct _node{
	int data;
	node * next;
} node;

void reverse_list(list * l){
	node * prev;
	node * tmp = l.head->next;

	while (head->next != NULL)
	{
		prev = l.head;
		l.head = tmp;

		if (l.head->next != NULL)
			tmp = l.head->next;
		l.head->next = prev;
	}
}

int main()
{

	list l;
	reverse_list(l);
}