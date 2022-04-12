/*
 * George Sidamon-Eristoff
 * 30 March 2022
 * Comp 98 - Senior Capstone, 2nd Semester
 * main.cpp is the file through which the user will interact with this program
 *
 * The goal of this program is to serve as a "medium-complexity" target to fuzz
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "airplane_object.hpp"


int main(int argc, char* argv[]){
  if (argc != 1) {
    std::cout << "Error" << std::endl;
  } else {
    std::cout << "\nInput a string made of the following characters: 't', 'l', 'h', and 'f'" << std::endl;
    std::cout << "Any / all other characters will be ignored.  'q' quits the application." << std::endl;
    std::cout << "t == take off, l == land, h == hire a crew member, f == fire one.\n" << std::endl;
    Airplane* my_airplane = new Airplane();
    my_airplane->interact();
    delete my_airplane;
  }

  return 0;
}
