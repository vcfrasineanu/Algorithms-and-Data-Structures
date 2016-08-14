/**
 *  Task: Return all valid combinations of n pairs of parentheses
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector< string > validParens;

void generateParens( int n, int left, int right, string current )
{
	if ( left == right && left == n )
	{
		validParens.push_back( current );
	}
	else
	{
		if ( left == right )
		{
			generateParens( n, left+1, right, current+'(' );
		}
		else
		{
			if ( left == n )
			{
				generateParens( n, left, right+1, current+")");
			}
			else
			{
				if ( left > right )
				{
					generateParens( n, left+1, right, current+"(");
					if (right < n) generateParens( n, left, right+1, current+")");
				}
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;

	generateParens( n, 0, 0, "" );

	unsigned int i;
	for ( i=0; i<validParens.size(); i++ ) cout << validParens[i] << endl;

	return 0;
}