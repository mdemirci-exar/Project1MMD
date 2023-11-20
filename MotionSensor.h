
#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include "Environment.h"

class MotionSensor {
public:
    MotionSensor();

    int read(const Environment& env);

    void update(Environment& env, bool motionDetected);
};

#endif
