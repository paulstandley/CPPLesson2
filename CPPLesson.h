#ifndef CPPLESSON_H
#define CPPLESSON_H

// define your own namespace to hold constants
namespace constants
{
    // constants have internal linkage by default
    constexpr double pi{ 3.14159 };
    constexpr double avogadro{ 6.0221413e23 };
    constexpr double my_gravity{ 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}

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



#endif // CPPLESSON_H
