// Humidifier.h

#ifndef HUMIDIFIER_H
#define HUMIDIFIER_H

#include "Environment.h"

class Humidifier {
public:
    // Kurucu iþlev
    Humidifier(const Environment& env);

    // Nem seviyesine göre humidifier'ý kontrol eden iþlev
    void controlHumidifier();

    // Nem seviyesine göre dehumidifier'ý kontrol eden iþlev
    void controlDehumidifier();

private:
    const Environment& env;
};

#endif
