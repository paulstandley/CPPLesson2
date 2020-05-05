#include "pch.h"
#include <iostream>
#include "CPPLesson.h"
#include <cmath> // std::abs
#include <algorithm> // std::max
#include <typeinfo> // for typeid()

void isOddEven()
{
    std::cout << "Enter an integer: " << std::endl;
    int x{ 0 };
    std::cin >> x;
    if ((x % 2) != 0)
        std::cout << x << " is odd" << std::endl;
    else
        std::cout << x << " is even" << std::endl;
}

void post_pre_fix()
{
    std::cout << "Postfix Prefix " << std::endl;
    int x{ 5 };
    int y{ 5 };
    std::cout << x << "         " << y << '\n';
    std::cout << ++x << "         " << --y << '\n'; // prefix
    std::cout << x << "         " << y << '\n';
    std::cout << x++ << "         " << y-- << '\n'; // postfix
    std::cout << x << "         " << y << '\n';
}

// return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqual(double a, double b, double epsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
}

void appEqu()
{
    // a is really close to 1.0, but has rounding errors, so it's slightly smaller than 1.0
    double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    // First, let's compare a (almost 1.0) to 1.0.
    std::cout << approximatelyEqual(a, 1.0, 1e-8) << '\n';

    // Second, let's compare a-1.0 (almost 0.0) to 0.0
    std::cout << approximatelyEqual(a - 1.0, 0.0, 1e-8) << '\n';
}

/*
You can see that with an appropriately picked absEpsilon,
approximatelyEqualAbsRel() handles the small inputs correctly.

Comparison of floating point numbers is a difficult topic,
and there's no "one size fits all" algorithm that works for every case.
However, the approximatelyEqualAbsRel()
should be good enough to handle most cases you'll encounter.
*/

// return true if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    double diff{ std::abs(a - b) };
    if (diff <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

void appEquAB()
{
    // a is really close to 1.0, but has rounding errors
    double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    std::cout << approximatelyEqual(a, 1.0, 1e-8) << '\n';     // compare "almost 1.0" to 1.0
    std::cout << approximatelyEqual(a - 1.0, 0.0, 1e-8) << '\n'; // compare "almost 0.0" to 0.0
    std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, 1e-12, 1e-8) << '\n'; // compare "almost 0.0" to 0.0
}

void block_scope()
{
    std::cout << "Enter an integer: ";
    int value1{ 0 };// value1 inalized
    std::cin >> value1;// value1 asigned user input
    std::cout << std::endl;

    std::cout << "Enter an larger integer: ";
    int value2{ 0 };// value2 inalized
    std::cin >> value2;// value2 asigned user input
    std::cout << std::endl;

    std::cout << "Swapping values" << std::endl;
    std::cout << std::endl;

    if (value1 > value2)
    {
        std::cout << "The smaller value is " << value2 << std::endl;
        std::cout << std::endl;
        std::cout << "The larger number is " << value1 << std::endl;
    }
    else
    {
        std::cout << "The smaller value is " << value1 << std::endl;
        std::cout << std::endl;
        std::cout << "The larger number is " << value2 << std::endl;
    }
}

void shadowing()
{
    // outer block
    int apples1{ 5 }; // here's the outer block apples

    { // nested block
        // apples refers to outer block apples here
        std::cout << apples1 << '\n'; // print value of outer block apples

        int apples{ 0 }; // define apples in the scope of the nested block

        // apples now refers to the nested block apples
        // the outer block apples is temporarily hidden

        apples = 10; // this assigns value 10 to nested block apples, not outer block apples

        std::cout << apples << '\n'; // print value of nested block apples
    } // nested block apples destroyed


    std::cout << apples1 << '\n'; // prints value of outer block apples
    // outer block apples destroyed
}

int g_value1{ 5 }; // global variable
void shadow_v()
{
    int g_value{ 7 }; // hides the global variable value
    ++g_value;
    // increments local value, not global value
    --(::g_value1);
    // decrements global value, not local value (parenthesis added for readability)
    std::cout << "local variable value: " << g_value << '\n';
    std::cout << "global variable value: " << ::g_value1 << '\n';
} // local value is destroyed

void global_variables_internal_linkage()
{
    //static int g_x1; // non-constant globals have external linkage by default,
    //but can be given internal linkage via the static keyword

    //const int g_y1{ 1 }; // const globals have internal linkage by default

    //constexpr int g_z1{ 2 }; // constexpr globals have internal linkage by default
    // Internal global variables definitions:

    //static int g_x;// defines non-initialized internal global variable
    //(zero initialized by default)

    //static int g_x{ 1 };// defines initialized internal global variable

    //const int g_y{ 2 };// defines initialized internal global const variable

    //constexpr int g_y{ 3 };// defines initialized internal global constexpr variable

    // Internal function definitions:
    //static int foo() {};     // defines internal function
}

void global_variables_external_linkage()
{
    // int g_x{ 2 }; // non-constant globals are external by default
    // extern const int g_y{ 3 };
    // const globals can defined as extern, making them external
    // extern constexpr int g_z{ 3 }; 
    // constexpr globals can defined as extern, making them external
    //(but this is useless, see the note in the next section)
    /*
        // External global variable definitions:
    int g_x;                       // defines non-initialized external global variable (zero initialized by default)
    extern const int g_x{ 1 };     // defines initialized const external global variable
    extern constexpr int g_x{ 2 }; // defines initialized constexpr external global variable

    // Forward declarations
    extern int g_y;                // forward declaration for non-constant global variable
    extern const int g_y;          // forward declaration for const global variable
    extern constexpr int g_y;      // not allowed: constexpr variables can't be forward declared

    Scope determines where a variable is accessible. Duration determines where a variable is created and destroyed. Linkage determines whether the variable can be exported to another file or not.
Global variables have global scope (aka. file scope), which means they can be accessed from the point of declaration to the end of the file in which they are declared.

Global variables have static duration, which means they are created when the program is started, and destroyed when it ends.

Global variables can have either internal or external linkage, via the static and extern keywords respectively.
    */
}

void radius()
{
    std::cout << "Enter a radius: ";
    int rad{ 0 };
    std::cin >> rad;
    std::cout << "The cirumference is: " << 2 * rad * constants::pi << std::endl;
}

void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

void usingDeclarations()
{
    using std::cout;
    using std::endl;
    // this using declaration tells the compiler that cout should resolve to std::cout
    cout << "Using declaration" << endl;
}

void usingDirective()
{
    using namespace std;
    // this using directive tells the compiler that we're using everything in the std namespace!
    cout << "Using directive" << endl;
}

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

void auto_values()
{
    /*
    auto d{ 5.0 }; // 5.0 is a double literal, so d will be type double
    auto i{ 1 + 2 }; // 1 + 2 evaluates to an int, so i will be type int

    auto add(int x, int y) -> int;
    auto divide(double x, double y) -> double;
    auto printSomething() -> void;
    auto generateSubstring(const std::string &s, int start, int len) -> std::string;
    */

    double d{ 4.0 };
    short s{ 2 };
    std::cout << typeid(d + s).name() << ' ' << d + s << '\n'; // show us the type of d + s

    std::cout << 5u - 10; // 5u means treat 5 as an unsigned integer
    // you might expect the expression 5u - 10 to evaluate to -5 since 5 - 10 = -5. But here’s what actually happens:
    // 4294967291

}


