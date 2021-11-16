#pragma once
class LinkedList
{
public:
	LinkedList(int);
	~LinkedList();

	void walk();

private:
	struct Node
	{
		Node* next;
	};

	Node* head;

	void deleteList(Node*);
};

