
#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Environment.h" 

class TemperatureSensor {
public:
    int read(const Environment& env);
    void update(Environment& env);
};

#endif
