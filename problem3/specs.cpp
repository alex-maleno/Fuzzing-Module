#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "specs.h"

Specs::Specs(){
    alt = 100;
    fuel = 50;
    speed = 7;
}

void Specs::choose_color() {
    std::string color;
    std::cout << "enter desired aircraft color: ";
    std::cin >> color;
    if (isNumber(color))
        abort();
}

void Specs::min_alt() {
    std::cout << "enter aircraft minimum altitude: " << std::endl;
    std::cin >> Specs::alt;
    while(Specs::alt < 500) {
        std::cout << "too low. please re-enter " << std::endl;
        std::cin >> Specs::alt;
        if(Specs::alt < 0)
            abort();
    }
}

void Specs::min_airspeed() {
    std::cout << "enter aircraft minimum airspeed: " << std::endl;
    std::cin >> Specs::speed;
    while(Specs::speed < 140 || Specs::speed > 160) {
        if(Specs::speed < 140) {
            std::cout << "too low. please re-enter " << std::endl;
            std::cin >> Specs::speed;
        } else if (Specs::speed > 160) {
            std::cout << "too high. please re-enter " << std::endl;
            std::cin >> Specs::speed;
        }
        if(Specs::speed < 0)
            abort();
    }
}

void Specs::fuel_cap() {
    std::cout << "enter fuel capacity: " << std::endl;
    std::cin >> Specs::fuel;
    while(Specs::fuel > 30) {
        std::cout << "too high. please re-enter " << std::endl;
        std::cin >> Specs::fuel;
        if(Specs::fuel < 0)
            abort();
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



