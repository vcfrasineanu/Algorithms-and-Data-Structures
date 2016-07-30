/**
 *  Task: Insertion sort
 */ 

// -----------------------------------------------------------------------------

#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------

void insert_number( int* v, int pos )
{
	while ( v[pos] < v[pos-1] && pos > 0)
	{
		swap( v[pos], v[pos-1] );
		pos--;
	}
}

// -----------------------------------------------------------------------------

void insertion_sort( int* v, int size )
{
	for ( int i=0; i<size-1; i++ )
	{
		if ( v[i+1] < v[i] ) insert_number( v, i+1 );
	}
}

// -----------------------------------------------------------------------------

int main()
{
	int size;
    cout << "Size of the array: "; cin >> size;
    int *v = new int[size];

    cout << "Insert " << size << " numbers: ";
    for ( unsigned int i = 0; i < size; i++ )
    {
        cin >> v[i];
    }

    insertion_sort( v, size );

    for ( unsigned int i = 0; i < size; i++ )
    {
        cout << v[i] << " ";
    }

    cout << endl;

    delete[] v;
    
    return 0;
}

// -----------------------------------------------------------------------------
