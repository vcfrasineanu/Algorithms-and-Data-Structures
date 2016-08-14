/**
 *  Task: Return all permutations of a string with unique characters
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> insertion( string word, char c )
{
	vector<string> result;
	unsigned int i = 0, j = 0;

	for ( i=0; i<=word.size(); i++ )
	{
		stringstream ss;
		for ( j=0; j<i; j++ ) ss << word[j];
		ss << c;
		for ( j=i; j<word.size(); j++ ) ss << word[j];

		result.push_back( ss.str() );
	}

	return result;
}

vector<string> getPermutations( string s )
{
	vector<string> permutations;
	string empty = "";
	permutations.push_back(empty);

	unsigned int i, j, k;
	for ( i=0; i<s.size(); i++ )
	{
		unsigned int oldSize = permutations.size();
		vector<string> newPermutations;

		for ( j=0; j<oldSize; j++ )
		{
			vector<string> newPerm = insertion( permutations[j], s[i] );
			for ( k=0; k<newPerm.size(); k++ )
			{
				newPermutations.push_back( newPerm[k] );
			}
		}

		permutations = newPermutations;
	}

	return permutations;
}

int main()
{
	string s;
	cin >> s;

	vector<string> permutations = getPermutations(s);

	unsigned int i = 0;
	for ( i=0; i<permutations.size(); i++ )
	{
		cout << permutations[i] << endl;
	}

	return 0;
}