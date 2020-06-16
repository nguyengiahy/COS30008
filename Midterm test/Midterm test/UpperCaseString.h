#pragma once
#include <iostream>

class UpperCaseStringIterator;
class UpperCaseString
{
private:
    char* fValue;

public:
    UpperCaseString(const char* aInitialValue = "");
    ~UpperCaseString();

    int size() const;
    const char operator[](int aIndex) const;

    UpperCaseStringIterator begin() const;
    UpperCaseStringIterator end() const;
    UpperCaseStringIterator rbegin() const;
    UpperCaseStringIterator rend() const;

    friend std::ostream& operator<<(std::ostream& aOStream, const UpperCaseString& aString);
};
