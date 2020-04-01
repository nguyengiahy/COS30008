#include "SelectionSort.h"
using namespace std;

SelectionSort::SelectionSort(int aArrayOfNumbers[], unsigned int aArraySize) : ArraySorter::ArraySorter(aArrayOfNumbers, aArraySize)
{}

void SelectionSort::sort(ostream& aOStream)
{
	for (int i = 0; i < getRange() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < getRange(); j++)
			if (at(j) < at(min))
				min = j;
		if (min != i)
			swapElements(i, min);
		stepCompleted(aOStream);
	}
}