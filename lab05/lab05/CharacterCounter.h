#pragma once
#include <iostream>
class CharacterCounter
{
private:
	int fTotalNumberOfCharacters;
	int fCharacterCounts[256];
public:
	CharacterCounter();
	void count(unsigned char aCharacter);
	friend std::ostream& operator<<(std::ostream& aOStream, const CharacterCounter& aCharacterCounter);
	const int operator[](unsigned char aCharacter) const;
};
