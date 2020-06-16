
// COS30008, Problem Set 5, 2020

#include "DoublyLinkedNodeIterator.h"

#include <iostream>
#include <string>

using namespace std;

void testDoublyLinkedNodeIterator()
{
    typedef DoublyLinkedNode<string> StringNode;
    typedef DoublyLinkedNodeIterator<string> StringIterator;

    StringNode n1("One");
    StringNode n2("Two");
    StringNode n3("Three");
    StringNode n4("Four");
    StringNode n5("Five");
    StringNode n6("Six");

    n1.push_back(n6);
    n1.push_back(n5);
    n1.push_back(n4);
    n1.push_back(n3);
    n1.push_back(n2);

    StringIterator iter(n4);

    iter--;

    cout << "Forward iteration I:" << endl;
    for (iter++; iter != iter.end(); iter++)
        cout << *iter << endl;

    cout << "Backward iteration I:" << endl;
    for (iter--; iter != iter.rend(); iter--)
        cout << *iter << endl;

    cout << "Forward iteration II:" << endl;
    for (iter = iter.begin(); iter != iter.end(); ++iter)
        cout << *iter << endl;

    cout << "Backward iteration II:" << endl;
    for (iter = iter.rbegin(); iter != iter.rend(); --iter)
        cout << *iter << endl;

    StringIterator iter2(StringNode::NIL);

    if (iter2 == iter2.end())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (iter2.begin() == iter2.end())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (iter2.rbegin() == iter2.rend())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    testDoublyLinkedNodeIterator();

    return 0;
}
