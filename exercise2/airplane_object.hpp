/*
 * George Sidamon-Eristoff
 * 30 March 2022
 * Comp 98 - Senior Capstone, 2nd Semester
 * airplane_object.hpp is the header file for the Airplane class
 */

#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP

// #include <string>

class Airplane {
public :
    Airplane();
    // ~Airplane();

    void interact();

    void takeoff();
    void land();
    void hire();
    void fire();

private:
    struct cabin_crew {
    	int num;
    	std::string captain_name;
    	std::string copilot_name; 
    } crew;
};

#endif
