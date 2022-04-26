#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "specs.h"

Specs::Specs(int a, int f, int s){
    alt = a;
    fuel = f;
    speed = s;
}

Specs::Specs(){
    alt = 0;
    fuel = 0;
    speed = 0;
}

void Specs::choose_color() {
    std::string color;
    std::cout << "enter desired aircraft color: ";
    std::cin >> color;
    if (isNumber(color))
        abort();
}

void Specs::min_alt() {
    // bool too_low = true;
    std::cout << "enter aircraft minimum altitude: ";
    std::cin >> alt;
    // do {
        // too_low = false;
    if(alt < 0) {
        std::cout << "too low. crashing!" << std::endl;
        abort();
    }
    else if (alt > 500) {
        std::cout << "too high. lowering to 500";
        alt = 500;
        // too_low = true;
    }
    // } while(too_low);
}

void Specs::min_airspeed() {
    bool out_of_bounds = true;
    std::cout << "enter aircraft minimum airspeed: ";
    std::cin >> speed;
    do {
        out_of_bounds = false;
        if(speed < 0)
            abort();
        if(speed < 100) {
            std::cout << "too low. please re-enter: ";
            std::cin >> speed;
            out_of_bounds = true;
        } else if (speed > 200) {
            std::cout << "too high. please re-enter: ";
            std::cin >> speed;
            out_of_bounds = true;
        }
    } while(out_of_bounds);
}

void Specs::fuel_cap() {
    bool too_high = true;
    std::cout << "enter fuel capacity: ";
    std::cin >> fuel;
    do {
        too_high = false;
        if(fuel < 0)
            abort();
        if (fuel > 100) {
            std::cout << "too high. please re-enter: ";
            std::cin >> fuel;
            too_high = true;
        }
    } while(too_high);
}

bool Specs::isNumber(std::string str)
{
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == 0) 
            return false;
    }
    return true;
}

int Specs::get_alt() {
    return alt;
}

int Specs::get_speed() {
    return speed;
}

int Specs::get_fuel() {
    return fuel;
}

void Specs::set_alt(int a) {
    alt = a;
}

void Specs::set_speed(int s) {
    speed = s;
}

void Specs::set_fuel(int f) {
    fuel = f;
}



