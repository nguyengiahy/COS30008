#include "CharacterCounter.h"
#include "CharacterFrequencyIterator.h"
#include "CharacterMap.h"
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "Argumens missing" << endl; 
		cerr << "Usage: FileCharacterCounter infile" << endl; 
		return 1; // program failed
	}
	// set up input file
	ifstream lInput;						// declare an input file variable
	lInput.open( argv[1], ifstream::in);	// open an input text file

	if (!lInput.good()) {
		cerr << "Cannot open input file: " << argv[1] << endl; 
		return 2; // program failed (input)
	}

	CharacterCounter lCounter; 
	unsigned char lChar;
	while (lInput >> lChar)
	{
		// count the character
		lCounter.count(lChar);
	}
	lInput.close();

	// test iterator
	cout << "The frequencies (unsorted): "<< endl;
	// C++11
	// This line executes: CharacterFrequencyIterator( lCounter ).begin()
	// sets cm to *(CharacterFrequencyIterator( lCounter ).begin())
	for (CharacterMap cm : CharacterFrequencyIterator(lCounter)) 
	{ 
		cout << cm.getCharacter() << ": " << cm.getFrequency() << endl; 
	}

	return 0;
}