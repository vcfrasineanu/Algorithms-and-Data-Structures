/**
 *  Task: Write an algorithm such that if an element in a n*m matrix is 0,
 *  then its entire row and column are set to zero 
 */ 

// -----------------------------------------------------------------------------

#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------

void modify_martix( int** v, int n, int m )
{
	int i,j,line,column;
	bool ok = false;

	for ( i=0; i<n; i++ )
	{
		for ( j=0; j<m; j++ )
		{
			if ( v[i][j] == 0 && !ok )
			{
				ok = true;
				line = i;
				column = j;
			}
			else
			{
				if ( v[i][j] == 0 && ok )
				{
					v[line][j] = 0;
					v[i][column] = 0;
				}
			}
		}
	}

	if (ok)
	{
		for ( i=0; i<n; i++ )
		{
			if ( v[i][column] == 0 && i != line ) 
			{
				for ( j=0; j<m; j++) v[i][j] = 0;
			}
		}
		for ( j=0; j<m; j++ )
		{
			if ( v[line][j] == 0 && j != column )
			{
				for ( i=0; i<n; i++) v[i][j] = 0;
			}
		}

		for ( i=0; i<n; i++) v[i][column] = 0;
		for ( j=0; j<m; j++) v[line][j] = 0;
	}
}

// -----------------------------------------------------------------------------

int main()
{
	int n,m;
	cin >> n >> m;

	int** v;
	v = new int*[n];
	int i,j;
	for ( i=0; i<n; i++ ) v[i] = new int[m];

	for ( i=0; i<n; i++ )
		for ( j=0; j<m; j++ ) cin >> v[i][j];

	modify_martix( v, n, m );

	for ( i=0; i<n; i++ )
	{
		for ( j=0; j<m; j++ ) cout << v[i][j] << " ";
		cout << endl;
	}

	for ( i=0; i<n; i++ ) delete[] v[i];
	delete[] v;

	return 0;
}

// -----------------------------------------------------------------------------
