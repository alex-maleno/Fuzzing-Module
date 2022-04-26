#pragma once
#include <string>
class Specs {
    /*
    * color
    * enter minimum airspeed ~140
    * enter minimum altitude ~500
    * enter max fuel capacity ~26 gallons
    *
    * lots of user input, collects specs about the aircraft
    * which will get updated in the maneuvers section and 
    * will be checked in the sys-status section
    */
    public:
        
        Specs(int a, int f, int s);
        Specs();

        // user chooses color, pointless function
        void choose_color();

        //user enters minmum altitude for aircraft
        //has to be reasonable so they keep choosing within the limit
        void min_alt();

        //user enters minmum airspeed for aircraft
        //has to be reasonable so they keep choosing within the limit
        void min_airspeed();

        //user enters max fuel capacity for aircraft
        //has to be reasonable so they keep choosing within the limit
        void fuel_cap();

        int get_alt();
        int get_speed();
        int get_fuel();

        void set_alt(int a);
        void set_speed(int s);
        void set_fuel(int f);

        //helper
        bool isNumber(std::string str);

    private:
        int alt;
        int speed;
        int fuel;
    
    
};
