#include <iostream>

using namespace std;

int main()
{
	cout << "Bool: " << sizeof( bool ) << endl; 					// 1
	cout << "Int: " << sizeof( int ) << endl;						// 4
	cout << "Unsigned int: " << sizeof( unsigned int ) << endl;		// 4
	cout << "Long: " << sizeof( long ) << endl;						// 8
	cout << "Char: " << sizeof( char ) << endl;						// 1
	cout << "Long long: " << sizeof( long long ) << endl;			// 8
	
	return 0;
}
