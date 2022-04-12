/*
 * George Sidamon-Eristoff
 * 30 March 2022
 * Comp 98 - Senior Capstone, 2nd Semester
 * airplane_object.cpp contains the function contracs and definitions for the Airplane class
 *
 * Note: there are purposely not many comments so the bug is more difficult to find
 */

#include <iostream>
#include <string>

#include "airplane_object.hpp"


Airplane::Airplane(){
    crew.num = 2;
    crew.captain_name = "Captain";
    crew.copilot_name = "CoPilot";
}


void Airplane::takeoff(){
    if (crew.num >= 1) {
        std::cout << "Takeoff!\n";
    } else {
        std::cout << "Nobody to fly the plane!\n";
    }
    return;
}

void Airplane::land(){
    if (crew.num >= 1) {
        std::cout << "Landed safely!\n";
    } else {
        std::cout << "Nobody left to land the plane!\n";
    }
    return;
}

void Airplane::hire(){
    crew.num += 1;
    std::cout << "Welcome aboard!\n";
    return;
}


void Airplane::fire(){
    crew.num -= 1;
    std::cout << "You're out of here!\n";
    return;
}

void Airplane::interact() {
    std::string input  = "";
    getline(std::cin, input);
    int input_length = input.length();
    if (input.empty()) {
        std::cout << "No command.\n";
    } else {
        int i = 0;
        while (input[i] != 'q' and i < input_length) {
            // std::cout << "i = " << i << "  input[i] =" << input[i] << "\n";
            if (input[i] == 't') {
                takeoff();
            } else if (input[i] == 'l') {
                if (crew.num == 0) {
                    abort();
                }
                land();
            } else if (input[i] == 'h') {
                hire();
            } else if (input[i] == 'f') {
                fire();
            }
            i++;
        }
    }
    return;
}
