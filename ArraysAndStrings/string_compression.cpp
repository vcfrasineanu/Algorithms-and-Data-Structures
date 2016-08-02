/**
 *  Task: Method to perform basic string compression using the counts of 
 *  repeated characters (ex: aabccccaaa becomes a2b1c4a3)
 *  If the string does not become smaller than the original string, then the 
 *  original string should be returned 
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// -----------------------------------------------------------------------------

string compress( string word )
{
	stringstream ss;
	unsigned int count = 0, i;
	bool ok = false;

	for ( i=0; i<word.size()-1; i++ )
	{
		ok = true;
		count = 1;
		while ( word[i] == word[i+1] && i<word.size() )
		{
			count++;
			i++;
			if ( i == word.size()-1 ) break;
		}
		ss << word[i] << count;
		if ( i == word.size() - 1 && word[i-1] == word[i] ) break;
		ok = false;
	}
	if ( !ok ) ss << word[i] << 1;
	
	if ( word.size() > ss.str().size() ) return ss.str();
	else return word;
}

// -----------------------------------------------------------------------------

int main()
{
	string word;
	getline( cin, word );

	word = compress( word );

	cout << word << endl;

	return 0;
}

// -----------------------------------------------------------------------------
