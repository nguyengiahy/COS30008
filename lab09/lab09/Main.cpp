
// COS30008, Tutorial 9, 2020

#include "SimpleString.h"

#if TEST >= 6

#include "Handle.h"

#endif

#include <iostream>

using namespace std;

// Test harnesses

#if TEST == 0 || TEST == 1

void testCC()
{
    SimpleString s1;
    s1 + 'A';
    SimpleString s2 = s1;
    s2 + 'B';

    cout << "S1: " << *s1 << endl;
    cout << "S2: " << *s2 << endl;
}

#endif

#if TEST == 2 || TEST == 3

void testAO()
{
    SimpleString s1;
    s1 + 'A';
    SimpleString s2 = s1;
    s2 + 'B';

    s1 = s2;

    cout << "S1: " << *s1 << endl;
    cout << "S2: " << *s2 << endl;
}

#endif

#if TEST == 4

void testPA()
{
    SimpleString* ps1 = new SimpleString();
    (*ps1) + 'A';
    SimpleString* ps2 = ps1;
    (*ps2) + 'B';

    cout << "S1: " << **ps1 << endl;
    cout << "S2: " << **ps2 << endl;

    delete ps1;
    delete ps2;
}

#endif

#if TEST == 5

void testClone()
{
    SimpleString* ps1 = new SimpleString();
    (*ps1) + 'A';
    SimpleString* ps2 = ps1->clone();
    (*ps2) + 'B';

    cout << "S1: " << **ps1 << endl;
    cout << "S2: " << **ps2 << endl;

    delete ps1;
    delete ps2;
}

#endif

#if TEST == 6

void testHandle()
{
    Handle<SimpleString> hs1(new SimpleString());
    *hs1 + 'A';
    Handle<SimpleString> hs2(hs1->clone());
    *hs2 + 'B';
    Handle<SimpleString> hs3 = hs1;

    cout << "HS1: " << **hs1 << endl;
    cout << "HS2: " << **hs2 << endl;
    cout << "HS3: " << **hs3 << endl;
}

#endif

int main()
{
#if TEST == 0

    cout << "Testing default behavior..." << endl;
    testCC();

#endif

#if TEST == 1

    cout << "Testing deep-copy copy constructor..." << endl;
    testCC();

#endif

#if TEST == 2

    cout << "Testing default assignment operator..." << endl;
    testAO();

#endif

#if TEST == 3

    cout << "Testing deep-copy assignment operator..." << endl;
    testAO();

#endif

#if TEST == 4

    cout << "Testing pointer aliases..." << endl;
    testPA();

#endif

#if TEST == 5

    cout << "Testing clone..." << endl;
    testClone();

#endif

#if TEST == 6

    cout << "Testing handles..." << endl;
    testHandle();

#endif

    return 0;
}
