#pragma once

#include "specs.h"

/*
* check altitude
* fuel status
* check weather
* check airspeed
*
*
*/
class Sys_Status {
    public:

        //Sys_Status();

        Sys_Status(Specs *s);

        //check if alt is too low based on value entered in specs, flash warning 
        //abort if negative, if too low set back to original
        //this func used in maneuvers, where alt is subtracted when maneuver is executed
        int check_alt(int alt);

        //check if airspeed is too low based on value entered in specs
        //abort if negative
        //fuel subtracted for every maneuver
        int check_fuel(int fuel);

        //randomly generate number to represent temp, if too low aircraft must land
        //set bool to true and return
        bool check_weather();

        //check if airspeed is too low based on value entered in specs
        //abort if negative
        //this func used in maneuvers, where airspeed is subtracted
        int check_speed(int speed);
    private:
        Specs *spec;
};


