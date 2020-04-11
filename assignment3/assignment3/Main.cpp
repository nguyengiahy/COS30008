#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "Missing argument!" << endl;
        cerr << "Usage: FibonacciIterator number" << endl;
        return 1;
    }

    cout << "Fibonacci sequence up to " << argv[1] << ":" << endl;

    FibonacciSequence lSequence(atoi(argv[1]));

    // test problem 1
    // (not including iterator methods begin() and end())

    for (unsigned long i = 1; i <= lSequence.getLimit(); i++)
    {
        cout << i << ":\t" << setw(5) << lSequence.current() << endl;
        lSequence.advance();
    }

    // test problem 2 as well as begin() and end() of problem 1

    // C++11 range loop

    cout << "Fibonacci sequence 1..20:" << endl;
    unsigned long i = 1;
    for (const unsigned long& n : lSequence)
    {
        cout << i++ << ":\t" << setw(5) << n << endl;
    }

    // Old-style loops

    cout << "Fibonacci sequence 1..20 (old-style):" << endl;

    FibonacciSequenceIterator lIteratorA = lSequence.begin();
    unsigned long a = 1;

    for (; lIteratorA != lIteratorA.end(); lIteratorA++)
    {
        cout << a++ << ":\t" << setw(5) << *lIteratorA << endl;
    }

    cout << "Once more:" << endl;

    FibonacciSequenceIterator lIteratorB = lIteratorA.begin();
    unsigned long b = 1;

    for (; lIteratorB != lIteratorB.end(); ++lIteratorB)
    {
        cout << b++ << ":\t" << setw(5) << *lIteratorB << endl;
    }

    cout << "Fibonacci sequence 1..21?:" << endl;

    FibonacciSequenceIterator lIteratorC = lIteratorB.begin();
    unsigned long c = 1;

    while (lIteratorC != lIteratorC.end())
    {
        cout << c++ << ":\t" << setw(5) << *lIteratorC++ << endl;
    }

    return 0;
}
