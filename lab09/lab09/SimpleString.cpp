#include "SimpleString.h"
#include<iostream>
using namespace std;


SimpleString::SimpleString()
{
	fChacracters = new char[1];
	*fChacracters = '\0';
}

SimpleString::~SimpleString()
{
	cout << "Destroy: \"" << fChacracters << "\"" << endl;
	delete[] fChacracters;
}

#if TEST >= 1
SimpleString::SimpleString(const SimpleString& aOtherString)
{
	cout << "In copy constructor, set fCharacters to: \"" << aOtherString.fCharacters << "\"" << endl;
	
	int lLength = strlen(aOtherString.fChacracters) + 1;
	fChacracters = new char[lLength];
	for (int i = 0; i < lLength; i++)
	{
		fChacracters[i] = aOtherString.fChacracters[i];
	}
}
#endif

#if TEST >= 3
SimpleString& SimpleString::operator=(const SimpleString& aOtherString)
{
	// assign to an initialized object
	// prevent self-assignment
	if (&aOtherString != *this)
	{
		cout << "In =, override \"" << fCharacters << "\" with \"" << aOtherString.fCharacters << "\"" << endl;

		// delete part of SimpleString
		cout << "In =, destroy: \"" << fCharacters << "\"" << endl;

		delete[] fCharacters;
		int lLength = strlen(aOtherString.fChacracters) + 1;
		fChacracters = new char[lLength];
		for (int i = 0; i < lLength; i++)
		{
			fChacracters[i] = aOtherString.fChacracters[i];
		}
	}

	return *this;
}
#endif


#if TEST >= 5
SimpleString* SimpleString::clone()
{
	return new SimpleString(*this);
}
#endif

SimpleString& SimpleString::operator+(const char aCharacter)
{
	char* temp = new char[strlen(fChacracters) + 2];
	int i = 0;
	for (; i < strlen(fChacracters); i++)
	{
		temp[i] = fChacracters[i];
	}
	temp[i++] = aCharacter;
	temp[i] = '\0';

	cout << "In +, override \"" << fChacracters << "\" with \"" << temp << "\"" << endl;
	cout << "In +, destroy: \"" << fChacracters << "\"" << endl;
	delete[] fChacracters;
	fChacracters = temp;
	return *this;
}

const char* SimpleString::operator*() const
{
	return fChacracters;
}