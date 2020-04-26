#include "ifstream12.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Reading 12 Bit codes:" << endl;

    ifstream12 lInput("sample.lzw");

    if (!lInput.good())
    {
        cerr << "Error: Unable to open input file!" << endl;
        return 2;
    }

    size_t l12BitValue;

    while (lInput >> l12BitValue)
    {
        if (l12BitValue == 0x0A)
        {
            cout << endl;
        }
        else
        {
            cout << (char)l12BitValue;
        }
    }

    cout << "SUCCESS" << endl;

    return 0;
}
