#pragma once
#include "ArraySorter.h"

class InsertionSort : public ArraySorter
{
public:
    InsertionSort(int aArrayOfNumbers[], unsigned int aArraySize);

    void sort(std::ostream& aOStream) override;
};
