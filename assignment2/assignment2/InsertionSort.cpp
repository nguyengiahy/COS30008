#include "InsertionSort.h"
using namespace std;

InsertionSort::InsertionSort(int aArrayOfNumbers[], unsigned int aArraySize) : ArraySorter::ArraySorter(aArrayOfNumbers, aArraySize)
{}

void InsertionSort::sort(ostream& aOStream)
{
	int i = 1;
	while (i < getRange())
	{
		int j = i;
		while (j > 0 && at(j - 1) > at(j))
		{
			swapElements(j, j - 1);
			j--;
		}
		i++;
		stepCompleted(aOStream);
	}
}