#include <iostream>
#include <random>
#include "specs.h"
#include "maneuvers.h"
#include "sys_status.h"



void Maneuvers::hover() {
    int alt = Specs::alt;
    int curr_alt = 500 + rand() % ((3000 + 1 ) - 500);
    alt = Specs::alt - 100;
    if(alt < Specs::alt) 
        std::cout << "too low, increase power" << std::endl;
    Specs::alt = alt;
    int fuel_loss = 1 + rand() % ((20 + 1 ) - 1);
    Specs::fuel = Specs::fuel - fuel_loss;
    Sys_Status::check_alt(alt);
    Sys_Status::check_fuel(fuel);
}

void Maneuvers::steep_approach(int speed) {
    int decel = 150 + rand() % ((200 + 1 ) - 50);
    speed = speed - decel;
    if (decel > 50) {
        std::cout << "warning! rapid deceleration. add power" << std::endl;
    }
    int fuel_loss = 1 + rand() % ((20 + 1 ) - 1);
    Specs::fuel = Specs::fuel - fuel_loss;
    Sys_Status::check_speed(speed);
    Sys_Status::check_fuel(fuel);
}

void Maneuvers::quick_stop(){
    int test = 0 + rand() % ((1 + 1) - 0);
    int fuel_loss = 1 + rand() % ((20 + 1 ) - 1);
    Specs::fuel = Specs::fuel - fuel_loss;
    bool decel;
    if (test == 1) {
        decel = true;
        std::cout << "warning! rapid deceleration. add power" << std::endl;
    }
    Sys_Status::check_fuel(fuel);
}