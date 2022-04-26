/*
 *
 *
 * This file isolates the Specs class and tests out the 
 * choose_color function specifically.
 * 
 * 
 * 
 */

#include "specs.h"

int main(int argc, char** argv) {
    // In order to call any functions in the Specs class, a Specs
    // object is necessary. This is using one of the constructors
    // found in the Specs class.
    Specs spec(505, 110, 50);
    // By looking at all the code in our project, this is all the 
    // necessary setup required. Most projects will have much more
    // that is needed to be done in order to properly setup objects.

    // This section should be in your code that you write after all the 
    // necessary setup is done. It allows AFL++ to start from here in 
    // your main() to save time and just throw new input at the target.
    #ifdef __AFL_HAVE_MANUAL_CONTROL
        __AFL_INIT();
    #endif

    spec.choose_color();
    //spec.min_alt();

    return 0;
}