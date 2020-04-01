#pragma once

#include <string>
#include <istream>
#include <ostream>

const double PI = 4.0 * atan(1.0);
class PassiveResistor
{
private:
    double fBaseValue;

    // normalize base value and unit (object remains unchanged)
    void normalize(double& aNormalizedValue, std::string& aUnit) const;

    // flatten base value and unit
    void flatten(const double& aRawValue, const std::string& aRawUnit);

protected:

    // virtual member functions

    // normalize the value of a register: 56000.0 becomes 56.0 kOhm
    // flatten value of a register: 56.0 kOhm becomes 56000.0

    // must scale: aValue >= 1000.0
    virtual bool mustScale(double aValue) const;

    // scaling multiplier: 0.001  = 1.0/1000.0
    virtual const double getMultiplier() const;

    // major unit: "Ohm"
    virtual const std::string getMajorUnit() const;

    // minor units: "OkM", the first letter means "no minor unit"
    virtual const std::string getMinorUnits() const;

    // non virtual member functions
    // set base value
    void setBaseValue(double aBaseValue);

public:

    // constructor with a default value
    PassiveResistor(double aBaseValue = 0.0);

    // virtual destructor required as we wish to override class Register
    virtual ~PassiveResistor() {}

    // returns base value
    double getBaseValue() const;

    // returns (frequency-dependent) passive resistance value
    virtual double getValue(double aFrequency = 0.0) const;

    // returns (frequency-dependent) voltage drop (using Ohm's law)
    double getPotential(double aCurrent, double aFrequency = 0.0) const;
    // returns (frequency-dependent) current flowing through passive resistor (using Ohm's law)
    double getCurrent(double aVoltage, double aFrequency = 0.0) const;

    // passive resistor I/O
    friend std::istream& operator>>(std::istream& aIStream, PassiveResistor& aObject);
    friend std::ostream& operator<<(std::ostream& aOStream, const PassiveResistor& aObject);
};

