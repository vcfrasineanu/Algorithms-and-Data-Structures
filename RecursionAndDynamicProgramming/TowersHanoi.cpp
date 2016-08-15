/**
 *  Task: Towers of Hanoi
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <stack>

using namespace std;

int count;

void towersHanoi( int n, int start, int buffer, int end )
{
	if ( n > 0 )
	{
		towersHanoi( n-1, start, end, buffer );
		count++;	
		cout << "Move " << n << " from " << start << " to " << end << endl;

		towersHanoi( n-1, buffer, start, end );
	}
}

int main()
{
	int n,i;
	cin >> n;

	count = 0;
	towersHanoi( n, 1, 2, 3 );

	cout << "Steps: " << count << endl;

	return 0;
}
