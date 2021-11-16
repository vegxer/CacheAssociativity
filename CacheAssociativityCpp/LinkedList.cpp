#include "LinkedList.h"
#include <cstddef>


LinkedList::LinkedList(int size)
{
	if (size <= 0)
	{
		head = NULL;
		return;
	}

	head = new Node();
	Node* ptr = head;
	for (int i = 0; i < size; ++i)
	{
		ptr->next = new Node();
		ptr = ptr->next;
	}
}

LinkedList::~LinkedList()
{
	deleteList(head);
}

void LinkedList::walk()
{
	for (int k = 0; k < 10000; ++k)
		for (Node* i = head; i->next != NULL; i = i->next)
			for (Node* j = head; j != i; j = j->next);
}

void LinkedList::deleteList(Node* node)
{
	if (node->next != NULL)
		deleteList(node->next);
	delete node;
}
