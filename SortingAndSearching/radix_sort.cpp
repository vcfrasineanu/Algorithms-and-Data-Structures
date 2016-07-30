/**
 *  Task: Radix sort 
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

// -----------------------------------------------------------------------------

int find_max( int* v, int size )
{
	int max = v[0];
	for (int i=0; i<size; i++)
	{
		if ( max < v[i] ) max = v[i];
	}
	return max;
}

// -----------------------------------------------------------------------------

void count_sort( int* v, int size, int digit )
{
	int *count = new int[10];
	int i = 0;

	int *temp = new int[size];

	for ( i=0; i<10; i++ ) count[i] = 0;

	for ( i=0; i<size; i++ ) count[ (v[i] % digit) / (digit / 10) ]++;

	for ( i=0; i<9; i++) count[i+1] += count[i];

	for ( i=size-1; i>=0; i-- ) 
	{
		temp[ count[ (v[i] % digit) / (digit / 10) ] - 1 ] = v[i];
		count[ (v[i] % digit) / (digit / 10) ]--;
	}

	for ( i=0; i<size; i++ ) v[i] = temp[i];
}

// -----------------------------------------------------------------------------

void radix_sort( int* v, int size )
{
	int max = find_max( v, size );
	
	int digit = 10; 
	/** we take the xth digit using this formula:
	 * ( number % digit ) / ( digit / 10 ) where digit = 10 ^ (x+1)
	 * ( for ex first digit is the least significant digit and it will be 
	 *   number % 10 )
	 */

	while ( max != 0 )
	{
		count_sort( v, size, digit );
		digit *= 10;
		max = max / 10;
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

    radix_sort( v, size );

    for ( unsigned int i = 0; i < size; i++ )
    {
        cout << v[i] << " ";
    }

    cout << endl;

    delete[] v;
    
    return 0;
}

// -----------------------------------------------------------------------------
