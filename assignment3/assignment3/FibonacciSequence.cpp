#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"
#include <stdexcept>  //for exception

//Constructor
FibonacciSequence::FibonacciSequence(unsigned long aLimit)
{
	fLimit = aLimit;
	fPrevious = 0;
	fCurrent = 1;
	fPosition = 1;
}

//Return the current fibonacci number
const unsigned long& FibonacciSequence::current() const
{
	return fCurrent;
}

//Calculating the next fibonacci number, also checking range for the limit
void FibonacciSequence::advance()
{
	if (fLimit > 0 && fPosition > getLimit())
	{
		throw std::out_of_range("Out of limit");
	}
	fPosition++;
	unsigned long next = fCurrent + fPrevious;
	fPrevious = fCurrent;
	fCurrent = next;
}

//Return limit
const unsigned long& FibonacciSequence::getLimit() const
{
	return fLimit;
}

//Return an iterator pointing to the first fibonacci
FibonacciSequenceIterator FibonacciSequence::begin()
{
	this->fPrevious = 0;
	this->fCurrent = 1;
	this->fPosition = 1;
	return FibonacciSequenceIterator(*this, 1);
}

//Return an iterator pointing to the last fibonacci within the range
FibonacciSequenceIterator FibonacciSequence::end()
{
	return FibonacciSequenceIterator(*this, getLimit()+1);
}