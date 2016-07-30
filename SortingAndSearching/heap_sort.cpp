/**
 *  Task: Heap sort
 *  (maintain a max-heap using array representation)
 *  - Children of index i are 2i+1 and 2i+2
 */ 

// -----------------------------------------------------------------------------

#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------

void heapify( int* v, int size, int index )
{
	int max = index;
	int left = 2*index + 1;
	int right = 2*index + 2;

	if ( v[max] < v[right] && right <size ) max = right;
	if ( v[max] < v[left] && left < size ) max = left;

	if ( max != index )
	{
		swap( v[max], v[index] );
		heapify( v, size, max );
	}
}

// -----------------------------------------------------------------------------

void heap_sort( int* v, int size )
{
	for ( int i = (size-3)/2; i>=0; i-- ) heapify( v, size, i );

	while ( size > 0 ) 
	{
		swap(v[0],v[size-1]);
		size--;
		heapify( v, size, 0 );
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

    heap_sort( v, size );

    for ( unsigned int i = 0; i < size; i++ )
    {
        cout << v[i] << " ";
    }

    cout << endl;

    delete[] v;
    
    return 0;
}

// -----------------------------------------------------------------------------
