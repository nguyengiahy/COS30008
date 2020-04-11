#pragma once

// forward declaration to break mutual recursion of
// FibonacciSequence and FibonacciSequence
class FibonacciSequenceIterator;

class FibonacciSequence
{
private:
    unsigned long fPrevious;    // previous Fibonacci number (initially 0)
    unsigned long fCurrent;     // current Fibonacci number (initially 1)
    unsigned long fPosition;    // position in the sequence (starts with 1)
    unsigned long fLimit;       // set limit for sequence (0 for no limit)

public:

    // Default constructor to set up a Fibonacci sequence (aLimit = 0 means infinite)
    FibonacciSequence(unsigned long aLimit = 20);

    // get current Fibonacci number
    const unsigned long& current() const;

    // advance to next Fibonacci number, may throw out_of_range exception on
    // exceeding limit
    void advance();

    // extract sequence limit
    const unsigned long& getLimit() const;

    // return new iterator positioned at start
    FibonacciSequenceIterator begin();

    // return new iterator positioned at a desired limit
    FibonacciSequenceIterator end();
};
