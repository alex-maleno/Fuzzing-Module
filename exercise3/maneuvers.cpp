#include <iostream>
#include <random>
#include "specs.h"
#include "maneuvers.h"
#include "sys_status.h"

// Maneuvers::Maneuvers(){
//     spec.min_alt();
//     spec.min_airspeed();
//     spec.fuel_cap();
// }

Maneuvers::Maneuvers(Specs *s, Sys_Status *ss){
    spec = s;
    sys = ss;
}

void Maneuvers::hover() {
    int curr_alt = 500 + rand() % ((3000 + 1 ) - 500);
    if(curr_alt  < spec->get_alt()) 
        std::cout << "too low, increase power" << std::endl;
    spec->set_alt(curr_alt);
    int fuel_loss = 1 + rand() % ((20 + 1 ) - 1);
    spec->set_fuel(spec->get_fuel() - fuel_loss);
    sys->check_alt(curr_alt);
    sys->check_fuel(spec->get_fuel());
}

void Maneuvers::steep_approach(int speed) {
    int decel = 150 + rand() % ((200 + 1 ) - 50);
    speed = speed - decel;
    if (decel > 50) {
        std::cout << "warning! rapid deceleration. add power" << std::endl;
    }
    int fuel_loss = 1 + rand() % ((20 + 1 ) - 1);
    spec->set_fuel(spec->get_fuel() - fuel_loss);
    sys->check_speed(speed);
    sys->check_fuel(spec->get_fuel());
}

void Maneuvers::quick_stop(){
    int test = 0 + rand() % ((1 + 1) - 0);
    int fuel_loss = 1 + rand() % ((20 + 1 ) - 1);
    spec->set_fuel(spec->get_fuel() - fuel_loss);
    bool decel;
    if (test == 1) {
        decel = true;
        std::cout << "warning! rapid deceleration. add power" << std::endl;
    }
    sys->check_fuel(spec->get_fuel());
}