#include "FibonacciSequenceIterator.h"
#include "FibonacciSequence.h"

//Constructor
FibonacciSequenceIterator::FibonacciSequenceIterator(FibonacciSequence& aSequenceObject, unsigned long aStart) : fSequenceObject(aSequenceObject), fIndex(aStart)
{}

//Dereference operator, returning the value of the current iterator
const unsigned long& FibonacciSequenceIterator::operator*() const
{
	return fSequenceObject.current();
}

//Prefix increment for iterator
FibonacciSequenceIterator& FibonacciSequenceIterator::operator++()
{
	fSequenceObject.advance();
	fIndex++;
	return *this;
}

//Postfix increment for iterator
FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int)
{
	FibonacciSequenceIterator temp = *this;
	++(*this);
	return temp;
}

//Comparing 2 iterators
bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const
{
	return (fIndex == aOther.fIndex)
			&& fSequenceObject.current() == aOther.fSequenceObject.current()
			&& fSequenceObject.getLimit() == aOther.fSequenceObject.getLimit();
}

//Comparing 2 iterators
bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const
{
	return !(*this == aOther);
}

//Return the iterator pointing to the first fibonacci 
FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
	return fSequenceObject.begin();
}

//Return an iterator pointing to the last fibonacci within the range
FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
	return fSequenceObject.end();
}