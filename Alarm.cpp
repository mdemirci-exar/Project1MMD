#include "Alarm.h"

Alarm::Alarm() : activated(false) {}

void Alarm::checkAndActivate(Environment& env) {
    if (!activated) {
        if (env.getSecurity() == "On") {
            if (env.getMotionSens() == "1") {
                activated = true;

                env.setAlarm("Activated");

            }
            else if (env.getContact() == "On") {
                activated = true;

                env.setAlarm("Activated");

            }
        }
    }
    else {
        if (!(env.getSecurity() == "On" && (env.getMotionSens() == "1" || env.getContact() == "On"))) {
            deactivateAlarm(env);
        }
    }
}

void Alarm::deactivateAlarm(Environment& env) {
    if (activated) {
        activated = false;

        env.setAlarm("Deactivated");

    }
}
