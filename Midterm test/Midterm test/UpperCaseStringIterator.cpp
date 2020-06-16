#include "UpperCaseStringIterator.h"
#include <iostream>
using namespace std;

/*Constructor
* Because fString is a reference data member, then it must be initialised before entering the constructor body
*/
UpperCaseStringIterator::UpperCaseStringIterator(const UpperCaseString & aString, int aStart) : fString(aString)  
{
	fIndex = aStart;
}

//Dereference operator, return value at current index
const char UpperCaseStringIterator::operator*() const
{
	return fString[fIndex];
}

//Postfix increment operator
UpperCaseStringIterator UpperCaseStringIterator::operator++(int)
{
	UpperCaseStringIterator temp = *this;
	fIndex++;
	return temp;
}

//Prefix decrement operator
UpperCaseStringIterator UpperCaseStringIterator::operator--()
{
	fIndex--;
	return *this;
}

//Comparing 2 iterators
bool UpperCaseStringIterator::operator==(const UpperCaseStringIterator& aOther) const
{
	return (&fString == &(aOther.fString) && fIndex == aOther.fIndex);
}

bool UpperCaseStringIterator::operator!=(const UpperCaseStringIterator& aOther) const
{
	return !(*this == aOther);
}

UpperCaseStringIterator UpperCaseStringIterator::begin() const
{
	return fString.begin();  //make use of UpperCaseString begin()
}

UpperCaseStringIterator UpperCaseStringIterator::end() const
{
	return fString.end();	//make use of UpperCaseString end()
}

UpperCaseStringIterator UpperCaseStringIterator::rbegin() const
{
	return fString.rbegin(); //make use of UpperCaseString rbegin()
}
UpperCaseStringIterator UpperCaseStringIterator::rend() const
{
	return fString.rend();	//make use of UpperCaseString rend()
}