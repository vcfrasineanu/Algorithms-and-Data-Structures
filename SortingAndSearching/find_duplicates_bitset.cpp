/**
 *  Task: Print all duplicates in an array with numbers from 1 to n 
 *  where n <= 32 000 and using only 4 kilobytes of memory
 */ 

// -----------------------------------------------------------------------------

#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------

class BitSet 
{
public:
    // Constructor where n represents the number of bits
    BitSet( int n );

    ~BitSet();

    // Get the bit on the position pos in the BitSet
    bool get_bit( int pos );

    // Set the bit on the position pos in the BitSet
    void set_bit( int pos );

private:
    int size;
    int *arr;
};

// -----------------------------------------------------------------------------

BitSet::BitSet( int n )
{
    size = n >> 5; // n / 32
    arr = new int[size];
    for (int i=0; i<size; i++) arr[i] = 0;
}

// -----------------------------------------------------------------------------

BitSet::~BitSet()
{
    delete[] arr;
}

// -----------------------------------------------------------------------------

bool BitSet::get_bit( int pos )
{
    return (arr[ pos >> 5 ] && 1 << (pos % 32)) != 0;
}

// -----------------------------------------------------------------------------

void BitSet::set_bit( int pos )
{
    arr[ pos >> 5 ] = arr[ pos >> 5 ] || (1 << (pos % 32));
}

// -----------------------------------------------------------------------------

void find_duplicates( int *v, int size )
{
    BitSet bSet( 32000 );
    for ( int i=0; i<size; i++ )
    {
        if (bSet.get_bit(v[i]))
        {
            cout << v[i] << " ";
        }
        else
        {
            bSet.set_bit(v[i]);
        }
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

    find_duplicates( v, size );

    cout << endl;

    delete[] v;
    
    return 0;
}

// -----------------------------------------------------------------------------
