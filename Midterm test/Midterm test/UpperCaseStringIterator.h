#pragma once

#include "UpperCaseString.h";

class UpperCaseString;

class UpperCaseStringIterator
{
private:
    const UpperCaseString & fString;
    int fIndex;

public:
    UpperCaseStringIterator(const UpperCaseString & aString, int aStart);

    const char operator*() const;               // element at current position
    UpperCaseStringIterator operator++(int);     // postfix increment
    UpperCaseStringIterator operator--();       // prefix decrement

    bool operator==(const UpperCaseStringIterator& aOther) const;
    bool operator!=(const UpperCaseStringIterator& aOther) const;

    // iterator positioned at first element: forward iteration
    UpperCaseStringIterator begin() const;

    // iterator after the last element: forward iteration
    UpperCaseStringIterator end() const;

    // iterator positioned at last element: backwards iteration
    UpperCaseStringIterator rbegin() const;

    // iterator before the first element: backwards iteration
    UpperCaseStringIterator rend() const;
};
