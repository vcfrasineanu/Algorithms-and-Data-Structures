/**
 *  Task: Class for representing a linked list
 */ 

// -----------------------------------------------------------------------------

#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------

struct Node
{
	Node* next;
	int data;
};

// -----------------------------------------------------------------------------

class LinkedList 
{
public:
	LinkedList();

	~LinkedList();

	void appendToTail( int newData );

	bool deleteNode( int n );

	void printList();

private:
	Node* root;
};

// -----------------------------------------------------------------------------

LinkedList::LinkedList()
{
	root = new Node;
	root = NULL;
}

// -----------------------------------------------------------------------------

LinkedList::~LinkedList()
{

}

// -----------------------------------------------------------------------------

void LinkedList::appendToTail( int newData )
{
	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->data = newData;

	if ( root == NULL )
	{
		root = newNode;
	}
	else
	{
		Node* it = root;
		while ( it->next != NULL )
		{
			it = it->next;
		}
		it->next = newNode;
	}
}

// -----------------------------------------------------------------------------

bool LinkedList::deleteNode( int n )
{
	if ( root == NULL ) return false;
	if ( root->data == n )
	{
		root = root->next;
		return true;
	}

	Node* it = root;
	while ( it->next != NULL )
	{
		if ( it->next->data == n ) break;
		it = it->next;
	}

	if ( it->next == NULL )
	{
		if ( it->data == n )
		{
			it = NULL;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		it->next = it->next->next;
	}

	return true;
}

// -----------------------------------------------------------------------------

void LinkedList::printList()
{
	Node* it = root;

	while ( it != NULL )
	{
		cout << it->data << " ";
		it = it->next;
	}

	cout << endl;
}

// -----------------------------------------------------------------------------

int main()
{
	LinkedList l;
	Node* node = new Node;
	
	l.appendToTail(5);
	l.printList();

	l.appendToTail(6);
	l.printList();

	l.appendToTail(7);
	l.appendToTail(8);
	l.appendToTail(9);

	l.printList();

	l.deleteNode(8);
	l.printList();

	l.deleteNode(5);
	l.printList();

	l.deleteNode(9);
	l.printList();

	l.deleteNode(6);
	l.printList();

	l.deleteNode(7);
	l.printList();

	cout << l.deleteNode(5) << endl;

	return 0;
}

// -----------------------------------------------------------------------------
