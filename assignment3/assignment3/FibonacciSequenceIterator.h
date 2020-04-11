#pragma once

// forward declaration to break mutual recursion of
// FibonacciSequence and FibonacciSequence
class FibonacciSequence;

class FibonacciSequenceIterator
{
private:
    FibonacciSequence& fSequenceObject;         // reference to sequence object
    unsigned long fIndex;                       // current iterator position

public:

    // iterator constructor, takes a reference to a FibonacciSequence object
    // and aStart set by default to 1
    FibonacciSequenceIterator(FibonacciSequence& aSequenceObject, unsigned long aStart = 1);

    // iterator methods

    const unsigned long& operator*() const;      // return current Fibonacci number
    FibonacciSequenceIterator& operator++();     // prefix, next Fibonacci number
    FibonacciSequenceIterator operator++(int); // postfix (extra unused argument)
    bool operator==(const FibonacciSequenceIterator& aOther) const;
    bool operator!=(const FibonacciSequenceIterator& aOther) const;

    // iterator methods

    // return new iterator positioned at start
    FibonacciSequenceIterator begin() const;

    // return new iterator positioned at limit
    FibonacciSequenceIterator end() const;
};
