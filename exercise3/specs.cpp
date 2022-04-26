#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "specs.h"

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
    std::cout << "enter aircraft minimum altitude: ";
    std::cin >> alt;
    while(alt < 500) {
        if(alt < 0)
            abort();
        std::cout << "too low. please re-enter: ";
        std::cin >> alt;
    }
}

void Specs::min_airspeed() {
    std::cout << "enter aircraft minimum airspeed: ";
    std::cin >> speed;
    while(speed < 100 || speed > 200) {
        if(speed < 0)
            abort();
        if(speed < 100) {
            std::cout << "too low. please re-enter: ";
            std::cin >> speed;
        } else if (speed > 200) {
            std::cout << "too high. please re-enter: ";
            std::cin >> speed;
        }
    }
}

void Specs::fuel_cap() {
    std::cout << "enter fuel capacity: ";
    std::cin >> fuel;
    while(fuel > 100) {
        if(fuel < 0)
            abort();
        std::cout << "too high. please re-enter: ";
        std::cin >> fuel;
    }
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



