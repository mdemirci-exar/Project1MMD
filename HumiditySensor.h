
#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H

#include "Environment.h"

class HumiditySensor {
public:
    int read(const Environment& env);
    void update(Environment& env);
};

#endif
