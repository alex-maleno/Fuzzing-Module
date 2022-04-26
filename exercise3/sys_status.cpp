#include <iostream>
#include <random>
#include "sys_status.h"
#include "specs.h"

Sys_Status::Sys_Status(Specs *s){
    spec = s;
}

int Sys_Status::check_alt(int alt) {
    if (alt < spec->get_alt() && alt > 0) {
        std::cout << "warning! critical altitude" << std::endl;
        alt = spec->get_alt();
    }
    if (alt < 0) {
        abort();
    }
    return alt;
}

//check if airspeed is too low based on value entered in specs
//abort if negative
//fuel subtracted for every maneuver
int Sys_Status::check_fuel(int fuel) {
    if (fuel < spec->get_fuel() && fuel > 0) {
        std::cout << "warning! critical fuel level. refuel now" << std::endl;
        fuel = spec->get_fuel();
    }
    if (fuel < 0)
        abort();
    return fuel;
}

//randomly generate number to represent temp, if too low aircraft must land
//set bool to true and return
bool Sys_Status::check_weather() {
    int temp = 0 + rand() % ((100 + 1 ) - 0);
    if (temp < 15) {
        std::cout << "temperature low, icing possible. land immediately" << std::endl;
        return true;
    }
    return false;
}

//check if airspeed is too low based on value entered in specs
//abort if negative
//this func used in maneuvers, where airspeed is subtracted
int Sys_Status::check_speed(int speed) {
    if (speed < spec->get_speed() && speed > 0) {
        std::cout << "warning! low airspeed." << std::endl;
        speed = spec->get_speed();
    }
    if (speed < 0)
        abort();
    return speed;
}