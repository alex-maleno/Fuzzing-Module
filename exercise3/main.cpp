#include "specs.h"
#include <iostream>
#include <stdio.h>
#include "sys_status.h"
#include "maneuvers.h"

// There are many opportunities in the code we wrote for the
// code to crash! Just look for places where an abort() exists
// and try to call those specific functions using AFL++ to
// find a crash. In our code, it is obvious what values
// will make it crash, but in other targets it will be 
// less obvious and there won't be aborts scattered throughout
// the code.

int main() {

    Specs *s = new Specs();
    s->choose_color();
    s->min_alt();
    s->min_airspeed();
    s->fuel_cap();
    
    Sys_Status sys(s);
    
    Maneuvers man(s, &sys);
    
    man.hover();
    man.quick_stop();

    return 0;
}
