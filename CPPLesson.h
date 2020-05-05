#ifndef CPPLESSON_H
#define CPPLESSON_H

/*
#ifdef INT_2_BYTES
using int8_t = char;
using int16_t = int;
using int32_t = long;
#else
using int8_t = char;
using int16_t = short;
using int32_t = int;
#endif // INT_2_BYTES
*/

// define your own namespace to hold constants
namespace constants1
{
    // constants have internal linkage by default
    constexpr double pi{ 3.14159 };
    constexpr double avogadro{ 6.0221413e23 };
    constexpr double my_gravity{ 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}

// define your own namespace to hold constants
namespace constants2
{
    inline constexpr double pi{ 3.14159 }; // note: now inline constexpr
    inline constexpr double avogadro{ 6.0221413e23 };
    inline constexpr double my_gravity{ 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}

/*
    namespace // unnamed namespace
{
    void doSomething1() // can only be accessed in this file
    {
        std::cout << "v1\n";
    }
}

    static void doSomething2() // can only be accessed in this file
{
    std::cout << "v1\n";
}

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

*/

void radius();

void isOddEven();
void post_pre_fix();

bool approximatelyEqual(double a, double b, double epsilon);
void appEqu();
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);
void appEquAB();

void block_scope();
void shadowing();
void shadow_v();

void global_variables_internal_linkage();

void global_variables_external_linkage();

void incrementAndPrint();
int generateID();

void usingDeclarations();
void usingDirective();

void typeAliases();
void auto_values();

void max_class_size1();

bool passOrFail();
void displayPassOrFail();

#endif // CPPLESSON_H

