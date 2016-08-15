/**
 *  Task: You have an integer and you can flip exactly one bit from a 0 to a 1
 *  => find the length of the longest sequence of 1s you can create
 *  ex: 1775 ( 11011101111 ) => 8
 */ 

// -----------------------------------------------------------------------------

#include <iostream>

using namespace std;

int main()
{
	int n, max, cur;
	bool ok;
	
	cin >> n;
	
	max = 0;
	cur = 0;
	ok = false;
	
	while ( n!=0 )
	{
		if ( n&1 == 1 )
		{
			cur++;
			if (max<cur) max = cur;
		}
		else
		{
			if ( !ok )
			{
				cur++;
				ok = true;
				if (max<cur) max = cur;
			}
			else
			{
				cur = 0;
				ok = false;
			}
		}
		n = n >> 1;
	}

	cout << max << endl;

	return 0;
}
