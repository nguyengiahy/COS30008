#pragma once
class CharacterMap
{
private:
	unsigned char fCharacter; 
	int fFrequency; 
public:
	// constructor with default arguments, it becomes a default constructor
	CharacterMap( unsigned char aCharacter = '\0', int aFrequency = 0 );
	// binary greater than operator, this is left, compare frequencies only
	bool operator>( const CharacterMap& aRight ) const;
	// getters for character and frequency
	const unsigned char getCharacter() const;
	const int getFrequency() const;
};