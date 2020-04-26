#include "CharacterMap.h"

CharacterMap::CharacterMap(unsigned char aCharacter, int aFrequency)
{
	fCharacter = aCharacter;
	fFrequency = aFrequency;
}

bool CharacterMap::operator>(const CharacterMap& aRight) const
{
	return (fFrequency > aRight.fFrequency);
}

const unsigned char CharacterMap::getCharacter() const
{
	return fCharacter;
}
const int CharacterMap::getFrequency() const
{
	return fFrequency;
}