#include "UpperCaseString.h"
#include "UpperCaseStringIterator.h"
#include <iostream>
#include <cctype>
#include <stdexcept>
using namespace std;

//Constructor
UpperCaseString::UpperCaseString(const char* aInitialValue)
{
    // a C-string contains at least one character: '\0'.
    size_t lLength = 1;

    // compute the length + 1 of aInitialValue
    for (int i = 0; aInitialValue[i] != '\0'; i++)
    {
        lLength++;
    }

    // allocate memory
    fValue = new char[lLength];

    // copy aInitialValue to fValue and make it upper case
    for (int i = 0; i < lLength; i++)
    {
        fValue[i] = toupper(aInitialValue[i]);
    }
}

//Destructor, free the memory for fValue
UpperCaseString::~UpperCaseString()
{
    delete[] fValue;
}

//Return the size of the string
int UpperCaseString::size() const
{
    int result = 0;
    for (int i = 0; fValue[i] != '\0'; i++)
        result++;
    return result;
}

//Return the value at given index, also checking out of range exception
const char UpperCaseString::operator[](int aIndex) const
{
    if (aIndex < size())
        return fValue[aIndex];
    else
        throw out_of_range("The entered index is out of range.");       //out of range exception
}

//The first element
UpperCaseStringIterator UpperCaseString::begin() const
{
    return UpperCaseStringIterator(*this, 0);
}

//Element after the last element
UpperCaseStringIterator UpperCaseString::end() const
{
    return UpperCaseStringIterator(*this, size());
}

//The last element
UpperCaseStringIterator UpperCaseString::rbegin() const
{
    return UpperCaseStringIterator(*this, size() - 1);
}

//Element before the first element
UpperCaseStringIterator UpperCaseString::rend() const
{
    return UpperCaseStringIterator(*this, -1);
}

ostream& operator<<(ostream& aOStream, const UpperCaseString& aString)
{
    aOStream << aString.fValue;
    return aOStream;
}