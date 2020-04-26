#include "CharacterCounter.h"

CharacterCounter::CharacterCounter() : fTotalNumberOfCharacters(0), fCharacterCounts()
{
}

void CharacterCounter::count(unsigned char aCharacter)
{
	fCharacterCounts[aCharacter]++;
	fTotalNumberOfCharacters++;
}

std::ostream& operator<<(std::ostream& aOStream, const CharacterCounter& aCharacterCounter)
{
	aOStream << "Character counts for "
		<< aCharacterCounter.fTotalNumberOfCharacters << " characters:" << std::endl;
	for (int i = 0; i < 256; i++)
	{
		aOStream << (char)i << ":\t" << aCharacterCounter.fCharacterCounts[i] << std::endl;
	}
	return aOStream;
}

const int CharacterCounter::operator[](unsigned char aCharacter) const
{
	return fCharacterCounts[aCharacter];
}