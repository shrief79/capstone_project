/*
    configurator.hpp
    created on :30/8/2023
    author     :shrief mahmoud

*/
#ifndef CONIGURATOR_HPP_
#define CONIGURATOR_HPP_
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/*
 * arg: constant string (confiuration file path)
 * in this case we use loops to get trusted files that can use the logger
 */
vector<string> getStringsFromFile(const string &filename);

#endif