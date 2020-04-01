#pragma once
#include "ArraySorter.h"

class SelectionSort : public ArraySorter
{
public:
    SelectionSort(int aArrayOfNumbers[], unsigned int aArraySize);

    void sort(std::ostream& aOStream) override;
};
