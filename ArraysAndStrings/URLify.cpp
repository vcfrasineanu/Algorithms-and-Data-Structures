/**
 *  Task: Write a method to replace all spaces in a string with '%20'
 *  The string has sufficient space at the end to hold additional characters
 *  and the 'true' length of the string is given
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

// -----------------------------------------------------------------------------

string change_string( string word, int true_size )
{
	unsigned int count_spaces = 0; 
	unsigned int i = 0;

	for ( i=0; i<true_size; i++ )
	{
		if ( word[i] == ' ' ) count_spaces++;
	}
	
	unsigned int j = true_size + count_spaces*2 - 1;
	
	for ( i=true_size-1; i>0; i-- )
	{
		if ( word[i] != ' ' )
		{
			word[j] = word[i];
			j--;
		}
		else
		{
			word[j] = '0'; j--;
			word[j] = '2'; j--;
			word[j] = '%'; j--;
		}
	}
	
	return word;
}

// -----------------------------------------------------------------------------

int main()
{
	string word;
	getline( cin, word );
	
	int true_size;
	cin >> true_size;

	word = change_string( word, true_size );

	cout << word << endl;

	return 0;
}

// -----------------------------------------------------------------------------
