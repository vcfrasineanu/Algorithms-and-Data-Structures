/**
 *  Task: Given a list of strings (only lowercase letters), sort all strings
 *  such that all anagrams are next to each other
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include <stdio.h>

using namespace std;

string get_key( string word )
{
	int v[30];
	unsigned int i;
	for ( i=0; i<30; i++ ) v[i] = 0;
	for ( i=0; i<word.size(); i++ ) v[(int)word[i] - 97]++;

	stringstream ss;
	for ( i=0; i<30; i++ )
	{
		if ( v[i] != 0 ) ss << ((char)(i+97))*v[i];
	}

	return ss.str();
}

// -----------------------------------------------------------------------------

void sort_anagrams( vector<string> vec )
{
	map< string, vector<string> > mymap;
	unsigned int i;
	for ( i=0; i<vec.size(); i++ )
	{
		mymap[ get_key( vec[i] ) ].push_back( vec[i] );
	}

	map< string, vector<string> >::iterator it = mymap.begin();
	while( it!=mymap.end() )
	{
		for ( i=0; i<it->second.size(); i++ )
		{
			cout << it->second[i] << " ";
		}
		it++;
	}

	cout << endl;
}

// -----------------------------------------------------------------------------

int main()
{
	int size;
	vector<string> vec;
	string word;

	cout << "Number of words: "; cin >> size;
	
	getchar();

	for ( int i=0; i<size; i++ )
	{
		getline( cin, word );
		vec.push_back( word );
	}
	
	sort_anagrams( vec );

	return 0;
}

// -----------------------------------------------------------------------------
