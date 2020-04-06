#include "ArraySorter.h"
using namespace std;

//Constructor
ArraySorter::ArraySorter(const int aArrayOfNumbers[], unsigned int aArraySize)
{
    // copy array into sorter
    fArrayOfNumbers = new int[aArraySize];

    for (unsigned int i = 0; i < aArraySize; i++)
    {
        fArrayOfNumbers[i] = aArrayOfNumbers[i];
    }

    fArraySize = aArraySize;
}

//Destructor
ArraySorter::~ArraySorter()
{
    // delete memory associated with array
    delete[] fArrayOfNumbers;
}

//Showing the sorted array after each stage
void ArraySorter::stepCompleted(ostream& aOStream)
{
    aOStream << "State: " << *this <<endl;
}

//Swap the value between 2 elements
void ArraySorter::swapElements(unsigned int aSourcIndex, unsigned int aTargetIndex)
{
    //make use of at() method to detect range error
    unsigned int lTemp;
    lTemp = at(aSourcIndex);
    fArrayOfNumbers[aSourcIndex] = at(aTargetIndex);
    fArrayOfNumbers[aTargetIndex] = lTemp;
}

//Return value at specific index, also check for range error
const unsigned int ArraySorter::at(unsigned int aIndex) const
{
    //error handling
    if (aIndex > fArraySize)
    {
        throw range_error("Invalid index. The index must be within the array's length");
    }
    return  fArrayOfNumbers[aIndex];
}

//Return the array's length
const unsigned int ArraySorter::getRange() const
{
    return fArraySize;
}


//Virtual method to be overriden by subclasses
void ArraySorter::sort(ostream& aOStream)
{
    stepCompleted(aOStream);
}


//Operator overloading to display an array
ostream& operator<<(ostream& aOStream, const ArraySorter& aObject)
{
    aOStream << "[";
    for (int i = 0; i < aObject.getRange(); i++)
    {
        aOStream << aObject.at(i);
        if (i < aObject.getRange() - 1)
            aOStream << ", ";
    }
    aOStream << "]";
    return aOStream;
}
