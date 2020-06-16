
// COS30008, Problem Set 7, 2020

#include <iostream>
#include <string>
#include "List.h"

#include "Stages.h"

#if P>=1
#include "Queue.h"
#endif

#if P>=2
#include "NTree.h"
#endif

using namespace std;

#if P==1

void testQueue()
{
    Queue<int> lQueue;

    lQueue.enqueue(1);
    lQueue.enqueue(2);
    lQueue.enqueue(3);
    lQueue.enqueue(4);
    lQueue.enqueue(5);
    lQueue.enqueue(6);

    // iterate from the top
    cout << "A - Top to bottom: " << lQueue.size() << " elements" << endl;

    for (const int& item : lQueue)
    {
        cout << "A queue element: " << item << endl;
    }

    // iterate from the bottom
    cout << "B - Bottom to top: " << lQueue.size() << " elements" << endl;

    for (Queue<int>::Iterator iter = lQueue.rbegin();
        iter != iter.rend(); iter--)
    {
        cout << "A queue element: " << *iter << endl;
    }

    cout << "Queue elements:" << endl;

    for (; !lQueue.isEmpty(); lQueue.dequeue())
    {
        cout << "value: " << lQueue.top() << endl;
    }
}

#endif

#if P==2

void testDepthFirstTraversal()
{
    string A("A");
    string A1("AA");
    string A2("AB");
    string A3("AC");
    string AA1("AAA");
    string AB1("ABA");
    string AB2("ABB");

    typedef NTree<string, 3> NS3Tree;

    NS3Tree lTree(A);

    lTree.attachNTree(0, *(new NS3Tree(A1)));
    lTree.attachNTree(1, *(new NS3Tree(A2)));
    lTree.attachNTree(2, *(new NS3Tree(A3)));

    lTree[0].attachNTree(0, *(new NS3Tree(AA1)));
    lTree[1].attachNTree(0, *(new NS3Tree(AB1)));
    lTree[1].attachNTree(1, *(new NS3Tree(AB2)));

    cout << "Depth-first traversal:" << endl;

    lTree.traverseDepthFirst(PreOrderVisitor<string>());

    cout << endl << "Success." << endl;
}

#endif

#if P==3

void testBreadthFirstTraversal()
{
    string A("A");
    string A1("AA");
    string A2("AB");
    string A3("AC");
    string AA1("AAA");
    string AB1("ABA");
    string AB2("ABB");

    typedef NTree<string, 3> NS3Tree;

    NS3Tree lTree(A);

    lTree.attachNTree(0, *(new NS3Tree(A1)));
    lTree.attachNTree(1, *(new NS3Tree(A2)));
    lTree.attachNTree(2, *(new NS3Tree(A3)));

    lTree[0].attachNTree(0, *(new NS3Tree(AA1)));
    lTree[1].attachNTree(0, *(new NS3Tree(AB1)));
    lTree[1].attachNTree(1, *(new NS3Tree(AB2)));

    cout << "Breadth-first traversal:" << endl;

    lTree.traverseBreadthFirst(TreeVisitor<string>());

    cout << endl << "Success." << endl;
}

#endif

int main()
{
#if P==1
    testQueue();
#endif

#if P==2
    testDepthFirstTraversal();
#endif

#if P==3
    testBreadthFirstTraversal();
#endif

    return 0;
}
