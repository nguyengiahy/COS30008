
// COS30008, Problem Set 6, 2020

#include <iostream>
#include <string>

#include "Stages.h"
#include "List.h"

#ifdef B
#include "Stack.h"
#endif

using namespace std;

#ifdef A

void testCopyControl()
{
    string s1("AAAA");
    string s2("BBBB");
    string s3("CCCC");
    string s4("DDDD");
    string s5("EEEE");

    List<string> lList;

    lList.push_front(s4);
    lList.push_front(s3);
    lList.push_front(s2);

    List<string> copy(lList);

    // iterate from the top
    cout << "A - Top to bottom: " << copy.size() << " elements" << endl;

    for (const string& element : copy)
    {
        cout << "A list element: " << element << endl;
    }

    // override list
    lList = copy;

    lList.push_front(s1);
    lList.push_back(s5);

    // iterate from the top
    cout << "B – Bottom to top: " << lList.size() << " elements" << endl;

    for (List<string>::Iterator iter = lList.rbegin();
        iter != iter.rend(); iter--)
    {
        cout << "A list element: " << *iter << endl;
    }
}

#endif

#ifdef B

void testStack()
{
    Stack<string> lStack;

    lStack.push("AAAA");
    lStack.push("BBBB");
    lStack.push("CCCC");
    lStack.push("DDDD");

    // iterate from the top
    cout << "A – Top to bottom: " << lStack.size() << " elements" << endl;

    for (const string& item : lStack)
    {
        cout << "A stack element: " << item << endl;
    }

    // iterate from the bottom
    cout << "B – Bottom to top: " << lStack.size() << " elements" << endl;

    for (Stack<string>::Iterator iter = lStack.rbegin();
        iter != iter.rend(); iter--)
    {
        cout << "A list element: " << *iter << endl;
    }

    cout << "3rd element from the top: " << lStack[2] << endl;

    cout << "Stack functions: " << endl;

    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    cout << "size: " << lStack.size() << endl;
    cout << "is empty: " << (lStack.isEmpty() ? "T" : "F") << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "is empty: " << (lStack.isEmpty() ? "T" : "F") << endl;
}

#endif

int main()
{
#ifdef A
    testCopyControl();
#endif

#ifdef B
    testStack();
#endif

    return 0;
}
