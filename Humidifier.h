// Humidifier.h

#ifndef HUMIDIFIER_H
#define HUMIDIFIER_H

#include "Environment.h"

class Humidifier {
public:
    // Kurucu i�lev
    Humidifier(const Environment& env);

    // Nem seviyesine g�re humidifier'� kontrol eden i�lev
    void controlHumidifier();

    // Nem seviyesine g�re dehumidifier'� kontrol eden i�lev
    void controlDehumidifier();

private:
    const Environment& env;
};

#endif
