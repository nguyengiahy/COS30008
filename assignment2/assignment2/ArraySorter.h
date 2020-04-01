#pragma once
#include <ostream>

class ArraySorter
{
private:
    int* fArrayOfNumbers;
    unsigned int fArraySize;

protected:

    // service member function to be called once a sorting step has been finished
    void stepCompleted(std::ostream& aOStream);

    // swap elements in the underlying array
    void swapElements(unsigned int aSourcIndex, unsigned int aTargetIndex);

public:
    // array sorter constructor
    ArraySorter(const int aArrayOfNumbers[], unsigned int aArraySize);

    // array sorter destructor
    virtual ~ArraySorter();

    // return array element at index
    const unsigned int at(unsigned int aIndex) const;

    // return size of underlying array
    const unsigned int getRange() const;

    // polymorphic sort function
    virtual void sort(std::ostream& aOStream);

    // output operator for array sorters
    friend std::ostream& operator<<(std::ostream& aOStream, const ArraySorter& aObject);
};
