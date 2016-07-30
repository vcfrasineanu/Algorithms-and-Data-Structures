/**
 *  Task: Find an element in a sorted array which was rotated
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

// -----------------------------------------------------------------------------

int binary_search( int* v, int left, int right, int number )
{
	if ( left <= right )
	{
		int mid = (left+right) / 2;
		
		if ( v[mid] == number ) return mid;
		if ( v[left] == number ) return left;
		if ( v[right] == number ) return right;

		if ( v[mid] == left && v[mid] == right )
		{
			int x = binary_search( v, left, mid-1, number );
			int y = binary_search( v, mid+1, right, number );
			if (x == -1)
			{
				return y;
			}
			else
			{
				return x;
			}
		}

		if ( v[mid] == v[left] )
		{
			return binary_search( v, mid+1, right, number );
		}
		if ( v[mid] == v[right] )
		{
			return binary_search( v, left, mid-1, number );
		}

		if ( v[mid] < number && v[left] < number )
		{
			return binary_search( v, mid+1, right, number );
		}
		if ( v[mid] < number && v[left] > number )
		{
			return binary_search( v, mid+1, right, number );
		}
		if ( v[mid] > number && v[right] > number )
		{
			return binary_search( v, left, mid-1, number );
		}
		if ( v[mid] > number && v[right] < number )
		{
			return binary_search( v, left, mid-1, number );
		}
	}
	else
	{
		return -1;
	}
}

// -----------------------------------------------------------------------------

int find_element( int* v, int size, int number)
{
	return binary_search( v, 0, size-1, number );
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

    int number;
    cout << "Number you are looking for: "; cin >> number;

    cout << find_element( v, size, number ) << endl;

    delete[] v;

	return 0;
}

// -----------------------------------------------------------------------------
