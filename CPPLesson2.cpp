// CPPLesson2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CPPLesson.h"
#include <cmath> // std::abs
#include <algorithm> // std::max
#include <typeinfo> // for typeid()

inline namespace v1 // declare an inline namespace named v1
{
    void doSomethingv()
    {
        std::cout << "v1\n";
    }
}

namespace v2 // declare a normal namespace named v2
{
    void doSomethingv()
    {
        std::cout << "v2\n";
    }
}

void inlineNamespaces()
{
    v1::doSomethingv(); // calls the v1 version of doSomething()
    v2::doSomethingv(); // calls the v2 version of doSomething()
    doSomethingv(); // calls the inline version of doSomething() (which is v1)
}

int main()
{ 
 
    inlineNamespaces();

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
