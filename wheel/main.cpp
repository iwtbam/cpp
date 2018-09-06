#include "Ini.hpp"
#include <iostream>


int main()
{
    iwtbam::Ini ini = 
    {
        {
            "config",
            {
                {"ip", "127.0.0.1"},
                {"port", "8800"}
            }
        },
        {
            "config2",
            {
                {"ip", "127.0.0.1"},
                {"port", "8800"}
            }
        }
    };

    // std::cout << ini;

    ini.write("1.txt");

    iwtbam::Ini ini2("1.txt");
    std::cout << ini;

    return 0;
}