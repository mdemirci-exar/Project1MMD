#pragma once

#include "Environment.h"

class Alarm {
public:
   
    Alarm();

    void checkAndActivate(Environment& env);

   
    void deactivateAlarm(Environment& env);

private:
    bool activated; 
};
