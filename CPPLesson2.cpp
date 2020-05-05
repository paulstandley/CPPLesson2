// CPPLesson2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CPPLesson.h"
#include <cmath> // std::abs
#include <algorithm> // std::max

void typeAliases()
{
    typedef long miles_t;
    typedef long speed_t;

    miles_t distance{ 5 };
    speed_t mhz{ 3200 };

    // The following is valid, because distance and mhz are both actually type long
    distance = mhz;


    typedef double distance_t1;
    // define distance_t1 as an alias for type double
    using distance_t2 = double;
    // define distance_t2 as an alias for type double
    /*
      Favor type aliases over typedefs,
      and use them liberally to document the meaning of your types.
    */
}

int main()
{ 



    return 0;
} 

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
