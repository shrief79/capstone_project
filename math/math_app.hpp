/*
    math_app.hpp
    created on :29/8/2023
    author     :shrief mahmoud

*/

#ifndef MATH_APP_HPP
#define MATH_APP_HPP
#include <iostream>
#include <cstdlib>
#include "../lib/MsgQue_lib.hpp"
// class for the math_lib contains (+,-,x,/)
class MathLib
{
public:
    MathLib();

    double add(double num1, double num2);
    double sub(double num1, double num2);
    double multiply(double num1, double num2);
    double divide(double num1, double num2);
};

#endif // MATH_APP_HPP
