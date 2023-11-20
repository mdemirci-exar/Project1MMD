#include "TemperatureSensor.h"

int TemperatureSensor::read(const Environment& env) {
    return env.getTemperature();
}

void TemperatureSensor::update(Environment& env) {
    int currentTemp = env.getTemperature();
    int idealTempMax = env.getIdealTemperatureMax();
    int idealTempMin = env.getIdealTemperatureMin();

    if (currentTemp < idealTempMin && env.getEnergySave() == "Off") {
        env.setHeating("On");
    }
    else if (currentTemp > idealTempMax) {
        env.setHeating("Off");
    }

    if (currentTemp > idealTempMax) {
        env.setCooling("On");
    }
    else if (currentTemp < idealTempMin) {
        env.setCooling("Off");
    }
}