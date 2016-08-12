/**
 *  Task: Class for representing a queue
 */ 

// -----------------------------------------------------------------------------

#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------

struct nodeQueue
{
	int data;
	nodeQueue* next;
};

// -----------------------------------------------------------------------------

class Queue
{
public:
	Queue();

	~Queue();

	void add( int newData );

	int remove();

	int peek();

	int getSize();

	void printQueue();

private:
	nodeQueue* first;
	nodeQueue* last;
	int size;
};

Queue::Queue()
{
	first = NULL;
	last = NULL;

	size = 0;
}

Queue::~Queue()
{}

void Queue::add( int newData )
{
	if ( size == 0 )
	{
		first = new nodeQueue;
		last = new nodeQueue;

		first->data = newData;
		first->next = NULL;
		last = first;

		size++;
	}
	else
	{
		nodeQueue* newNode = new nodeQueue;
		newNode->data = newData;
		newNode->next = NULL;
		last->next = newNode;

		last = newNode;

		size++;
	}
}

int Queue::remove()
{
	if ( size==0 ) return -1;
	if ( size==1 )
	{
		int oldData = first->data;

		first = NULL;
		last = NULL;
		size--;

		return oldData;
	}

	nodeQueue* oldNode = first;
	int oldData = oldNode->data;

	first = first->next;
	delete oldNode;
	size--;

	return oldData;
}

int Queue::peek()
{
	if ( size==0 ) return -1;
	return first->data;
}

int Queue::getSize()
{
	return size;
}

void Queue::printQueue()
{
	nodeQueue* it = first;
	while (it!=NULL)
	{
		cout << it->data << " ";
		it = it->next;
	}
	cout << endl;
}

// -----------------------------------------------------------------------------

int main()
{
	Queue q;
	
	q.add(5);
	q.printQueue();

	q.add(6);
	q.printQueue();

	q.add(7);
	q.add(8);
	q.add(9);

	q.printQueue();

	q.remove();
	q.printQueue();

	q.remove();
	q.printQueue();

	q.remove();
	q.printQueue();

	cout << q.peek() << endl;

	q.remove();
	q.printQueue();

	cout << q.peek() << endl;

	q.remove();
	q.printQueue();

	cout << q.peek() << endl;

	return 0;
}