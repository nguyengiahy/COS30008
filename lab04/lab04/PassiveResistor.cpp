#include "PassiveResistor.h"
using namespace std;

void PassiveResistor::normalize(double& aNormalizedValue, string& aUnit) const
{
	aNormalizedValue = getBaseValue();
	string lPrefixes = getMinorUnits();

	for (int i = 0; i < lPrefixes.size(); i++)
	{
		//stop scaling at maximum unit
		if (mustScale(aNormalizedValue) && (i < lPrefixes.size() - 1))
		{
			aNormalizedValue *= getMultiplier();
		}
		else
		{
			if (i > 0)
			{
				aUnit += lPrefixes[i];
			}
			aUnit += getMajorUnit();
			break;
		}
	}
}

void PassiveResistor::flatten(const double& aRawValue, const string& aRawUnit)
{
    string lMajorUnit = getMajorUnit();
    string lMinorUnits = getMinorUnits();

    // error handling
    // test basic features (raw unit too long and not containing major unit)
    if ((aRawUnit.size() > lMajorUnit.size() + 1) ||
        (aRawUnit.find(getMajorUnit()) == string::npos))
    {
        throw invalid_argument("Invalid unit specification");
    }

    // test scale features, aRawUnit[0] must be contained in minor units
    if ((aRawUnit.size() == lMajorUnit.size() + 1) &&
        lMinorUnits.find(aRawUnit[0]) == string::npos)
    {
        throw invalid_argument("Invalid unit scale specification");
    }

    // adjust base value
    double lMultiplier = 1.0;

    size_t i = lMinorUnits.find(aRawUnit[0]);
    double lRawValue = aRawValue;

    // scale raw value first
    for (; i > 0; i--)
    {
        if (mustScale(lRawValue))
        {
            lRawValue /= getMultiplier();
        }
        else
        {
            break;
        }
    }

    // adjust multiplier
    for (; i > 0; i--)
    {
        lMultiplier *= 1.0 / getMultiplier();
    }

    setBaseValue(lRawValue * lMultiplier);
}

bool PassiveResistor::mustScale(double aValue) const
{
    return (aValue >= 1000.0);
}

const double PassiveResistor::getMultiplier() const
{
    return 0.001;
}

const string PassiveResistor::getMajorUnit() const
{
    return "Ohm";
}

const string PassiveResistor::getMinorUnits() const
{
    return "OkM";
}

void PassiveResistor::setBaseValue(double aBaseValue)
{
    fBaseValue = aBaseValue;
}

PassiveResistor::PassiveResistor(double aBaseValue)
{
    setBaseValue(aBaseValue);
}

double PassiveResistor::getBaseValue() const
{
    return fBaseValue;
}

double PassiveResistor::getValue(double aFrequency) const
{
    return 0.0;
}

double PassiveResistor::getPotential(double aCurrent, double aFrequency) const
{
    //if resistor
    if (aFrequency == 0.0)
        return getBaseValue() * aCurrent;

    //if capacitor
    else
        return (1 / (2 * PI * aFrequency * getBaseValue())) * aCurrent;
}

double PassiveResistor::getCurrent(double aVoltage, double aFrequency) const
{
    //if resistor
    if (aFrequency == 0.0)
        return aVoltage / getBaseValue();

    //if capacitor
    else
        return aVoltage / (1 / (2 * PI * aFrequency * getBaseValue()));
}

istream& operator>>(istream& aIStream, PassiveResistor& aObject)
{
    aIStream >> aObject.fBaseValue;
    return aIStream;
}

ostream& operator<<(ostream& aOStream, const PassiveResistor& aObject)
{
    double lValue = aObject.getBaseValue();
    string lUnit = "";
    aObject.normalize(lValue,lUnit);
    

    aOStream << lValue << lUnit <<endl;
    return aOStream;
}