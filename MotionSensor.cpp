
#include "MotionSensor.h"

MotionSensor::MotionSensor() {}

int MotionSensor::read(const Environment& env) {
    if (env.getMotionSens() == "1") {
        return 1; 
    }

    return -1; 
}

void MotionSensor::update(Environment& env, bool motionDetected) {
    if (motionDetected) {
        env.setMotionSens("1");
    }
    else {
        env.setMotionSens("-1");
    }
}
