#include "Capacitor.h"
#include <cmath>
using namespace std;


bool Capacitor::mustScale(double aValue) const
{
	return (aValue < 1.0);
}

const double Capacitor::getMultiplier() const
{
	return 1000;
}

const string Capacitor::getMajorUnit() const
{
	return "F";
}

const string Capacitor::getMinorUnits() const
{
	return "Fmunp";
}

Capacitor::Capacitor(double aBaseValue)
{
	setBaseValue(aBaseValue);
}

double Capacitor::getValue(double aFrequency) const
{
	double lValue = 1 / (2 * PI * aFrequency * getBaseValue());
	return lValue;
}