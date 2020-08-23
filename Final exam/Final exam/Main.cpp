
// COS30008, Final Exam, 2020

#include <iostream>
#include <string>
#include <stdexcept>

#include "Stages.h"

#include "TTree.h"

using namespace std;

#ifdef P1

void runP1()
{
    string s1("A");
    string s2("B");
    string s3("C");
    string s4("D");

    TTree<string> treeA(s1);
    TTree<string>* treeB = new TTree<string>(s2);
    TTree<string>* treeC = new TTree<string>(s3);
    TTree<string>* treeD = new TTree<string>(s4);

    cout << "The payload of treeA: " << treeA.getKey() << endl;

    try
    {
        treeA.getMiddle().getKey();

        cout << "You should not see this output." << endl;
    }
    catch (domain_error e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    treeA.addLeft(*treeB);
    treeA.addMiddle(*treeC);
    treeA.addRight(*treeD);

    cout << "Trees attached" << endl;

    cout << "Use copy constructor." << endl;

    try
    {
        TTree<string> No = treeA.getLeft().getLeft();

        cout << "You should not see this output." << endl;
    }
    catch (domain_error e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    TTree<string> tree_copy = treeA;
    TTree<string> B(tree_copy);

    cout << "Copy constructors used." << endl;

    cout << "Use assignment operator." << endl;

    try
    {
        B = treeA.getLeft().getLeft();

        cout << "You should not see this output." << endl;
    }
    catch (domain_error e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    const TTree<string>* lRight = &treeA.getRight();

    B = treeA;

    if (&B.getRight() != lRight)
    {
        cout << "You should not see this output." << endl;
    }

    cout << "Assignment operator used." << endl;

    const TTree<string>* lLeft = &B.getLeft();

    B = B;

    if (&B.getLeft() != lLeft)
    {
        cout << "You should not see this output." << endl;
    }

    cout << "Self assigned used." << endl;
}

#endif

#ifdef P3

#include "LinearVisitor.h"

void runP3()
{
    string s1("A");
    string s2("B");
    string s3("C");
    string s4("D");
    string s5("E");
    string s6("F");

    TTree<string> treeA(s1);
    TTree<string>* treeB = new TTree<string>(s2);
    TTree<string>* treeC = new TTree<string>(s3);
    TTree<string>* treeD = new TTree<string>(s4);
    TTree<string>* treeE = new TTree<string>(s5);
    TTree<string>* treeF = new TTree<string>(s6);

    treeA.addLeft(*treeB);
    treeA.addMiddle(*treeC);
    treeA.addRight(*treeD);
    ((TTree<string>&)treeA.getLeft()).addMiddle(*treeE);
    ((TTree<string>&)treeA.getRight()).addMiddle(*treeF);

    LinearVisitor<string> lVisitor;

    cout << "Visitor test:";

    treeA.traverseDepthFirst(lVisitor);

    cout << endl;
}

#endif

int main()
{
#ifdef P1
    runP1();
#endif

#ifdef P3
    runP3();
#endif

    return 0;
}

