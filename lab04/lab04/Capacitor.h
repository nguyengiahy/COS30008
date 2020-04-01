#pragma once
#include "PassiveResistor.h"

class Capacitor : public PassiveResistor
{
protected:

    // normalize the value of a capacitor: 0.0000047 becomes 4.7 uF (object remains unchanged)
    // flatten value of a capacitor: 4.7 uF becomes 0.0000047 (updates object)

    // must scale: aValue < 1.0
    bool mustScale(double aValue) const override;

    // scaling multiplier: 1000.0
    const double getMultiplier() const override;

    // major unit: "F"
    const std::string getMajorUnit() const override;

    // minor units: "Fmunp"
    const std::string getMinorUnits() const override;

public:
    Capacitor(double aBaseValue = 0.0);

    // returns frequency-dependent capacitive reactance value
    double getValue(double aFrequency = 0.0) const override;
};
