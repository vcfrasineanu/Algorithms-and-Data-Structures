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

	int getSize();

private:
	Node* root;
	int size;
};

// -----------------------------------------------------------------------------

LinkedList::LinkedList()
{
	root = new Node;
	root = NULL;
	size = 0;
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
		size++;
	}
	else
	{
		Node* it = root;
		while ( it->next != NULL )
		{
			it = it->next;
		}
		it->next = newNode;
		size++;
	}
}

// -----------------------------------------------------------------------------

bool LinkedList::deleteNode( int n )
{
	if ( root == NULL ) return false;
	if ( root->data == n )
	{
		root = root->next;
		size--;
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
			size--;
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
	size--;
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

int LinkedList::getSize()
{
	return size;
}

// -----------------------------------------------------------------------------

/**
 * Task: Compute sum of two linked lists
 * Ex: ( 7->1->6 ) + ( 5->9->2 ) = ( 2->1->9 ) // 617+295 = 912
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

int mem;

/**
 * Task: Compute sum of two linked lists recursively
 * Ex: ( 6->1->7 ) + ( 2->9->5 ) = ( 9->1->2 ) // 617+295 = 912
 */
 
Node* computeSum( Node* a, Node* b )
{
	if ( a->next == NULL && b->next == NULL )
	{
		Node* newNode = new Node;
		newNode->data = (a->data + b->data) % 10;
		mem = (a->data + b->data) / 10;

		return newNode;
	}
	else
	{
		Node* newNode = new Node;
		newNode->next = computeSum( a->next, b->next );

		newNode->data = (a->data + b->data + mem) % 10;
		mem = (a->data + b->data) / 10;

		return newNode;
	}
}

LinkedList computeSumRec( LinkedList a, LinkedList b )
{
	mem = 0;

	int sizeA, sizeB;
	sizeA = a.getSize();
	sizeB = b.getSize();

	Node *rootA, *rootB;
	
	rootA = a.getRoot();
	rootB = b.getRoot();

	if ( sizeA!=sizeB )
	{
		if (sizeA>sizeB)
		{
			while ( sizeA>sizeB )
			{
				Node* temp = new Node;
				temp->data = 0;
				temp->next = rootB;
				rootB = temp;
				sizeB++;
			}
		}
		else
		{
			while ( sizeB>sizeA )
			{
				Node* temp = new Node;
				temp->data = 0;
				temp->next = rootA;
				rootA = temp;
				sizeA++;
			}
		}
	}

	Node* s = computeSum( rootA, rootB );
	LinkedList sum;

	while (s!=NULL)
	{
		sum.appendToTail( s->data );
		s = s->next;
	} 

	return sum;
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
	b.appendToTail(2);

	LinkedList s = computeSum( a, b );
	s.printList();

	LinkedList a1;
	LinkedList b1;

	a1.appendToTail(6);
	a1.appendToTail(1);
	a1.appendToTail(7);

	b1.appendToTail(9);
	b1.appendToTail(5);

	LinkedList s1 = computeSumRec( a1, b1 );
	s1.printList();

	return 0;
}

// -----------------------------------------------------------------------------
