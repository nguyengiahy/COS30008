#include <iostream>
#include <iomanip>

#include "PassiveResistor.h"
#include "Capacitor.h"

using namespace std;

int main()
{
    // Problem 1
    PassiveResistor lR;

    cout << "Enter resistor value: ";
    cin >> lR;
    cout << "Passive resistor value: " << lR << endl;
    cout << "Current at 9.0V: " << lR.getCurrent(9.0) << "A" << endl;
    cout << "Voltage drop at 200mA: " << lR.getPotential(0.2) << "V" << endl;
    
    // Problem 2
    Capacitor lC;

    cout << "Enter capacitor value: ";
    cin >> lC;
    cout << "Capacitor value: " << lC << endl;
    // create a temporary passive resistor object to properly format value
    cout << "XC at 60Hz: " << PassiveResistor(lC.getValue(60.0)) << endl;
    cout << "Current at 9V and 60Hz: " << lC.getCurrent(9.0, 60.0) << "A" << endl;
    cout << "Voltage drop at 2mA and 60Hz: " << lC.getPotential(0.002, 60.0) << "V" << endl;
    
    // Problem 3
    double lXC = 0.0;
    double lFrequency = 50.0;

    do
    {
        lXC = lC.getValue(lFrequency);
        cout << "XC at " << setw(5) << lFrequency << "Hz:\t" << PassiveResistor(lXC) << endl;
        lFrequency += 50.0;
    } while (lXC > 1.0);

    return 0;
}
