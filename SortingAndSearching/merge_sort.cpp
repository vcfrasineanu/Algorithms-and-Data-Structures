/**
 *  Task: Merge sort
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

// -----------------------------------------------------------------------------

void merge( int *v, int left, int mid, int right )
{
    vector<int> temp;

    unsigned int i = left;
    unsigned int j = mid+1;
    
    while ( i <= mid && j <= right )
    {
        if ( v[i] < v[j] ) 
        {
            temp.push_back( v[i] );
            i++;
        }
        else
        {
            temp.push_back( v[j] );
            j++;
        }
    }

    while ( i <= mid )
    {
        temp.push_back( v[i] );
        i++;
    }

    while ( j <= right )
    {
        temp.push_back( v[j] );
        j++;
    }

    for ( i = left; i <= right; i++ ) v[i] = temp[i-left];
}

// -----------------------------------------------------------------------------

void mergeSort( int *v, int left, int right )
{
    if (left < right )
    {
        int mid = ( left + right ) / 2;
        mergeSort( v, left, mid );
        mergeSort( v, mid+1, right );
        merge( v, left, mid, right );
    }
}

// -----------------------------------------------------------------------------

void sort_vector( int *v, int size )
{
    mergeSort( v, 0, size - 1 );
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

    return 0;
}

// -----------------------------------------------------------------------------
