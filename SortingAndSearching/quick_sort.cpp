/**
 *  Task: Quick sort ( partition afer the first element )
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

// -----------------------------------------------------------------------------

int partition( int* v, int left, int right )
{
	int pivot = v[left];
	int temp;
	int index = left+1;
	
	for ( int i=left; i <= right; i++ )
	{
		if ( pivot > v[i] )
		{
			swap( v[index], v[i] );
			index++; 
		}
	}
	
	swap( v[index-1], v[left] );
	
	return index-1;
}

// -----------------------------------------------------------------------------

void quick_sort( int* v, int left, int right )
{
	if ( left < right )
	{
		int p = partition( v, left, right );
		quick_sort( v, left, p-1 );
		quick_sort( v, p+1, right );
	}
}

// -----------------------------------------------------------------------------

void sort_vector( int* v, int size )
{
	quick_sort( v, 0, size-1 );
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

    sort_vector( v, size );

    for ( unsigned int i = 0; i < size; i++ )
    {
        cout << v[i] << " ";
    }

    cout << endl;

    delete[] v;
    
    return 0;
}

// -----------------------------------------------------------------------------
