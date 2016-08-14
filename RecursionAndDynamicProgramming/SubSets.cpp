/**
 *  Task: Return all subsets of a set
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > getSubSets( vector<int> set )
{
	unsigned int i,j, oldSize;
	vector< vector<int> > subsets;
	vector< int > emptySet;
	subsets.push_back( emptySet );
	
	vector< int > aux;

	for ( i=0; i<set.size(); i++ )
	{
		oldSize = subsets.size();
		for ( j=0; j < oldSize; j++ )
		{
			aux = subsets[j];
			aux.push_back( set[i] );
			subsets.push_back( aux );
		}
	}

	return subsets;
}

int main()
{
	vector< int > set;
	vector< vector<int> > subsets;

	set.push_back(1);
	set.push_back(2);
	set.push_back(3);
	set.push_back(4);
	set.push_back(5);

	subsets = getSubSets(set);

	unsigned int i,j;

	for ( i=0; i<subsets.size(); i++ )
	{
		for ( j=0; j<subsets[i].size(); j++ )
		{
			cout << subsets[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}