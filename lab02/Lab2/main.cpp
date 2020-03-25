#include "CharacterCounter.h"
#include <fstream>
using namespace std;

int main( int argc, char* argv[] )
{    
	if ( argc < 2 )    
	{        
		cerr << "Argument missing." << endl;        
		// return failure, not enough arguments        
		return 1;    
	} 

	ifstream lInput;    
	lInput.open(argv[1], ifstream::in);
	
	if (!lInput.good())
	{
		cerr << "Cannot open the file";
		return 2;
	}  

	CharacterCounter lCounter;    
	unsigned char lChar;    

	while ( lInput >> lChar )
	{        
		// count the character
		lCounter.count( lChar );
	}    

	cout << lCounter;    
	return 0;
}