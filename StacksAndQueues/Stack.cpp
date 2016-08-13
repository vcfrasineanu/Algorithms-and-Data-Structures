/**
 *  Task: Class for representing a stack
 */ 

// -----------------------------------------------------------------------------

#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------

struct nodeStack
{
	int data;
	nodeStack* next;
};

// -----------------------------------------------------------------------------

class Stack
{
public:
	Stack();

	~Stack();

	void push( int newData );

	int pop();

	int peek();

	int getSize();

	void printStack();

private:
	nodeStack* top;
	int size;
};

Stack::Stack()
{
	//top = new nodeStack;
	top = NULL;

	size = 0;
}

Stack::~Stack()
{

}

void Stack::push( int newData )
{
	if ( size==0 )
	{
		top = new nodeStack;
		top->data = newData;
		top->next = NULL;
		size++;
	}
	else
	{
		nodeStack* newNode = new nodeStack;
		newNode->data = newData;
		newNode->next = top;
		top = newNode;
		size++;
	}
}

int Stack::pop()
{
	if ( size == 0 ) return -1;
	nodeStack* oldNode = top;
	top = top->next;

	int oldData = oldNode->data;
	delete oldNode;

	size--;
	return oldData;
}

int Stack::peek()
{
	if ( size == 0 ) return -1;
	return top->data;
}

int Stack::getSize()
{
	return size;
}

void Stack::printStack()
{
	nodeStack* it = top;
	while ( it!=NULL )
	{
		cout << it->data << " ";
		it = it->next;
	}
	cout << endl;
}

Stack sortStack( Stack a )
{
	Stack aux;

	while ( a.getSize() > 0 )
	{
		int current = a.pop();
		if ( aux.getSize() == 0 ) aux.push( current );
		else
		{
			int cnt = 0;
			if (aux.peek() < current)
			{
				while ( (aux.peek() < current) && (aux.getSize() != 0) )
				{
					a.push(aux.pop());
					cnt++;
				}
			}
			aux.push(current);
			while ( cnt>0 )	
			{
				aux.push(a.pop());
				cnt--;
			}
		}
	}

	return aux;
}

// -----------------------------------------------------------------------------

int main()
{
	Stack s;
	
	s.push(6);
	s.printStack();

	s.push(6);
	s.printStack();

	s.push(5);
	s.push(9);
	s.push(8);
	s.push(7);
	
	s = sortStack(s);
	cout << endl;
	s.printStack();
	cout << endl;
	s.pop();
	s.printStack();

	s.pop();
	s.printStack();

	s.pop();
	s.printStack();

	s.pop();
	s.printStack();

	s.pop();
	s.printStack();

	cout << s.pop() << endl;

	return 0;
}