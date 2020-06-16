#pragma once
#include<string>
#include "Test.h"
class SimpleString {
private:
	char* fChacracters;
public:
	SimpleString();
	virtual ~SimpleString();
#if TEST >= 1
	SimpleString(const SimpleString& aOtherString);
#endif
#if TEST >= 3    
	SimpleString& operator=( const SimpleString& aOtherString );
#endif
#if TEST >= 5
	virtual SimpleString* clone();
#endif
	SimpleString& operator+(const char aCharacter);
	const char* operator*() const;
};
