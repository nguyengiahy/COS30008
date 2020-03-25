#pragma once
#include <iostream>

class CharacterCounter
{
private:
int fTotalNumberOfCharacters;
int fCharacterCounts[256];
public:  
	CharacterCounter();  
	void count( unsigned char aCharacter );      // We count all 256 byte values  
	friend std::ostream& operator<<( std::ostream& aOStream, const CharacterCounter& aCharacterCounter );
};