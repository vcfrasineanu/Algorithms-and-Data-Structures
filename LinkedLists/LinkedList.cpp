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

	Node* getRoot();

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

Node* LinkedList::getRoot()
{
	return root;
}

// -----------------------------------------------------------------------------

/**
 * Task: Compute sum of two linked lists
 */
LinkedList computeSum( LinkedList a, LinkedList b )
{
	LinkedList s;

	Node* rootA = a.getRoot();
	Node* rootB = b.getRoot();

	int sum, mem;
	sum = 0;
	mem = 0;

	while ( rootA != NULL && rootB != NULL )
	{
		sum = mem + rootA->data + rootB->data;
		mem = sum / 10;
		sum = sum % 10;

		s.appendToTail(sum);

		rootA = rootA->next;
		rootB = rootB->next;
	}

	if ( rootA != NULL )
	{
		while ( rootA != NULL )
		{
			sum = mem + rootA->data;
			mem = sum / 10;
			sum = sum % 10;

			s.appendToTail(sum);

			rootA = rootA->next;	
		}
	}

	if ( rootB != NULL )
	{
		while ( rootB != NULL )
		{
			sum = mem + rootB->data;
			mem = sum / 10;
			sum = sum % 10;

			s.appendToTail(sum);

			rootB = rootB->next;	
		}
	}

	if ( mem!=0 ) s.appendToTail(mem);

	return s;
}

// -----------------------------------------------------------------------------

int main()
{
	LinkedList l;
	
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

	LinkedList a;
	LinkedList b;

	a.appendToTail(7);
	a.appendToTail(1);
	a.appendToTail(6);

	b.appendToTail(5);
	b.appendToTail(9);
	b.appendToTail(5);

	LinkedList s = computeSum( a, b );
	s.printList();

	return 0;
}

// -----------------------------------------------------------------------------
