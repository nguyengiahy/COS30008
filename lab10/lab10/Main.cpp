
// COS30008, Tutorial 10, 2020

#include <iostream>
#include <string>

#include "Stages.h"
#include "List.h"

using namespace std;

int main()
{
#ifdef A
	// Step 1:
	// implement:
	// - default constructor
	// - getIterator

	string s1("AAAA");
	string s2("BBBB");
	string s3("CCCC");
	string s4("DDDD");

	List<string> lList;

	lList.push_front(s4);
	lList.push_front(s3);
	lList.push_front(s2);
	lList.push_front(s1);

	// iterate from the top
	cout << "Top to bottom: " << lList.size() << " elements" << endl;
	for (const string& item : lList)
	{
		cout << "A list element: " << item << endl;
	}

#endif

#ifdef B
	// Step 2:
	// implement:
	// - push_back

	string s5("EEEE");
	string s6("FFFF");

	lList.push_back(s5);
	lList.push_back(s6);

	// iterate from the last
	cout << "Bottom to top: " << lList.size() << " elements" << endl;
	for (List<string>::Iterator iter = lList.rbegin(); iter != iter.rend(); iter--)
	{
		cout << "A list element: " << *iter << endl;
	}

#endif

#ifdef C
	// Step 3:
	// implement:
	// - remove

	lList.remove(s3);
	lList.remove(s1);
	lList.remove(s6);

	// iterate from the top
	cout << "Top to bottom: " << lList.size() << " elements" << endl;
	for (List<string>::Iterator iter = lList.begin(); iter != iter.end(); iter++)
	{
		cout << "A list element: " << *iter << endl;
	}

#endif

#ifdef D
	// Step 4:
	// implement:
	// - operator[]

	cout << "Element at index 2: " << lList[2] << endl;

#endif

	return 0;
}
