#include "SelectionSort.h"
using namespace std;


//Constructor
SelectionSort::SelectionSort(int aArrayOfNumbers[], unsigned int aArraySize) : ArraySorter::ArraySorter(aArrayOfNumbers, aArraySize)
{}

//Overriding sort method to apply selection sort
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
		//stepCompleted(aOStream);
		ArraySorter::sort(aOStream);
	}
}