#pragma once

#include "sys_status.h"
#include "specs.h"

/*
* hover
* steep approach
* quick stop
*
*/

class Maneuvers {
    public:
        //Maneuvers();
        Maneuvers(Specs *s, Sys_Status *ss);

        //generate random number for current alt above entered value
        //subtract random number btw 1 and 20 from fuel
        //subtract 100 from alt for maneuver, if alt < min flash warning
        void hover();

        //subtract random speed, if change is >50 then flash warning
        //subtract random number btw 1 and 20 from fuel
        //potential crash - random number being generated is potentially greater than the entered speed
        //in main we can update it and could make it negative, crash if it is
        void steep_approach(int speed);

        //generate random 0 or 1 - if 1, deceleration = true, flash warning
        //subtract random number btw 1 and 20 from fuel
        void quick_stop();

    private:
        Specs *spec;
        Sys_Status *sys;
};



