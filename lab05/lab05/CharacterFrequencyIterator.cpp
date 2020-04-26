#include "CharacterFrequencyIterator.h"

CharacterFrequencyIterator::CharacterFrequencyIterator(const CharacterCounter& aCounter, bool aSort)
{
	if (aSort)
		sort();
	for (int i = 0; i < 256; i++)
		fMap[i] = aCounter[i];
	fIndex = 0;
	advanceIndex();
}

void CharacterFrequencyIterator::advanceIndex()
{
	while (fIndex < 257)
	{
		if (fMap[fIndex].getFrequency() != 0)
			break;
		fIndex++;
	}
}

//Bubble sort
void CharacterFrequencyIterator::sort()
{
	int i, j;
	for (i = 0; i < 255; i++) 
		for (j = 0; j < 255 - i; j++)
			if (fMap[j].getFrequency() < fMap[j + 1].getFrequency())
			{
				CharacterMap temp = fMap[j];
				fMap[j] = fMap[j + 1];
				fMap[j + 1] = temp;
			}
}

const CharacterMap& CharacterFrequencyIterator::operator* () const
{
	return fMap[fIndex];
}

CharacterFrequencyIterator& CharacterFrequencyIterator::operator++ ()
{
	advanceIndex();
	return *this;
}

CharacterFrequencyIterator CharacterFrequencyIterator::operator++ (int)
{
	CharacterFrequencyIterator temp = *this;
	++(*this);
	return temp;
}

bool CharacterFrequencyIterator::operator==(const CharacterFrequencyIterator& aOther) const
{
	return (fMap == aOther.fMap && fIndex == aOther.fIndex);
}

bool CharacterFrequencyIterator::operator!=(const CharacterFrequencyIterator& aOther) const
{
	return !(*this == aOther);
}

CharacterFrequencyIterator CharacterFrequencyIterator::begin() const
{
	CharacterFrequencyIterator Clone = *this;
	Clone.fIndex = 0;
	Clone.advanceIndex();
	return Clone;
}

CharacterFrequencyIterator CharacterFrequencyIterator::end() const
{
	CharacterFrequencyIterator Clone = *this;
	Clone.fIndex = 256;
	return Clone;
}