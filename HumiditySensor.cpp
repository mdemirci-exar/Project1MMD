
#include "HumiditySensor.h"

int HumiditySensor::read(const Environment& env) {
    return env.getHumidity();
}

void HumiditySensor::update(Environment& env) {
    int currentHumidity = env.getHumidity();

    if (currentHumidity > 60 && env.getDehumidifer() == "Off") {
        env.setDehumidifer("On");
    }
    else if (currentHumidity <= 60 && env.getDehumidifer() == "On") {
        env.setDehumidifer("Off");
    }

    if (currentHumidity < 55 && env.getHumidifer() == "Off") {
        env.setHumidifer("On");
    }
    else if (currentHumidity >= 55 && env.getHumidifer() == "On") {
        env.setHumidifer("Off");
    }
}
