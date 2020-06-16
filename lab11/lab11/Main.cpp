
// COS30008, Tutorial 11, 2020

#include "NTree.h"

#include <iostream>
#include <string>

#include "Stages.h"

using namespace std;

#if S==1

void testNTree()
{
    cout << "Test basic tree construction." << endl;

    string A1("A");
    string AA1("AA");
    string AA2("AB");
    string AA3("AC");
    string AAA1("AAA");

    typedef NTree<string, 3> NS3Tree;

    // build simple NTrees (test constructor)
    NS3Tree root(A1);
    NS3Tree nodeA1(AA1);
    NS3Tree nodeA2(AA2);
    NS3Tree nodeA3(AA3);
    NS3Tree nodeAA1(AAA1);

    // test attach trees, operator[], and key()
    root.attachNTree(0, nodeA1);
    root.attachNTree(1, nodeA2);
    root.attachNTree(2, nodeA3);
    root[0].attachNTree(0, nodeAA1);

    cout << "root:       " << root.key() << endl;
    cout << "root[0]:    " << root[0].key() << endl;
    cout << "root[1]:    " << root[1].key() << endl;
    cout << "root[2]:    " << root[2].key() << endl;
    cout << "root[0][0]: " << root[0][0].key() << endl;

    // test detachNTree
    root[0].detachNTree(0);

    if (&root[0][0] == &NS3Tree::NIL)
        cout << "Detach succeeded [0][0]." << endl;
    else
        cout << "Detach failed." << endl;

    root.detachNTree(0);
    root.detachNTree(1);
    root.detachNTree(2);

    if (&root[0] == &NS3Tree::NIL)
        cout << "Detach succeeded [0]." << endl;
    else
        cout << "Detach failed." << endl;
}

#endif

#if S==2

void testTreeBug()
{
    cout << "Test memory bug." << endl;

    string A1("A");
    string AA1("AA");
    string AA2("AB");
    string AA3("AC");
    string AAA1("AAA");

    typedef NTree<string, 3> NS3Tree;

    NS3Tree root(A1);
    NS3Tree nodeA1(AA1);
    NS3Tree nodeA2(AA2);
    NS3Tree nodeA3(AA3);
    NS3Tree nodeAA1(AAA1);

    root.attachNTree(0, nodeA1);
    root.attachNTree(1, nodeA2);
    root.attachNTree(2, nodeA3);
    root[0].attachNTree(0, nodeAA1);

    cout << "root:       " << root.key() << endl;
    cout << "root[0]:    " << root[0].key() << endl;
    cout << "root[1]:    " << root[1].key() << endl;
    cout << "root[2]:    " << root[2].key() << endl;
    cout << "root[0][0]: " << root[0][0].key() << endl;

    cout << "Here a memory bug occurs: We free trees that we have not allocated." << endl;
}

#endif

#if S==3

void testNTreeCopyControl()
{
    cout << "Test copy semantics." << endl;

    string A1("A");
    string AA1("AA");
    string AA2("AB");
    string AA3("AC");
    string AAA1("AAA");

    typedef NTree<string, 3> NS3Tree;

    NS3Tree root(A1);

    root.attachNTree(0, *(new NS3Tree(AA1)));
    root.attachNTree(1, *(new NS3Tree(AA2)));
    root.attachNTree(2, *(new NS3Tree(AA3)));

    root[0].attachNTree(0, *(new NS3Tree(AAA1)));

    cout << "root:       " << root.key() << endl;
    cout << "root[0]:    " << root[0].key() << endl;
    cout << "root[1]:    " << root[1].key() << endl;
    cout << "root[2]:    " << root[2].key() << endl;
    cout << "root[0][0]: " << root[0][0].key() << endl;

    NS3Tree copy = root;
    NS3Tree* clone = copy.clone();

    cout << "copy:       " << copy.key() << endl;
    cout << "copy[0]:    " << copy[0].key() << endl;
    cout << "copy[1]:    " << copy[1].key() << endl;
    cout << "copy[2]:    " << copy[2].key() << endl;
    cout << "copy[0][0]: " << copy[0][0].key() << endl;

    delete clone;

    cout << "All trees are going to be deleted now!" << endl;
}

#endif

int main()
{
#if S==1

    testNTree();

#endif

#if S==2

    testTreeBug();

#endif

#if S==3

    testNTreeCopyControl();

#endif

    return 0;
}
