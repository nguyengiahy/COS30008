#include "CharacterCounter.h"
using namespace std;

CharacterCounter::CharacterCounter()
{    
	for ( int i = 0; i < 256; i++ )    
	{        
		fCharacterCounts[i] = 0;    
	}    
	fTotalNumberOfCharacters = 0;
}

void CharacterCounter::count( unsigned char aCharacter )
{
	fCharacterCounts[aCharacter]++;
	fTotalNumberOfCharacters++;
}

ostream& operator<<( ostream& aOStream, const CharacterCounter& aCharacterCounter )
{
	aOStream << "Character counts for "      
			<< aCharacterCounter.fTotalNumberOfCharacters << " characters:" <<endl;
	for ( int i = 0; i < 256; i++ )
	{
		if ( aCharacterCounter.fCharacterCounts[i] != 0 )
		{
			aOStream << (char)i << ":\t" << aCharacterCounter.fCharacterCounts[i] << endl;
		}
	}
	return aOStream;
}