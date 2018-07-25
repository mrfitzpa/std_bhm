// std_bhm/src/parameters/from_std_cin.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <limits>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "parameters/from_std_cin.h"



// Read in value of type T from the standard input stream.
namespace NSA1 = std_bhm::parameters::from_std_cin;

template <class T>
T NSA1::to_value()
{

    T value;
    std::cin >> value;

    // Flushes the newline escape sequence out of the input buffer.
    // This is to ensure subsequent calls to std::getline do not skip.
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 

    return value;

}



// Read in a vector from the standard input stream.
namespace NSA1 = std_bhm::parameters::from_std_cin;

template <class T>
std::vector<T> NSA1::to_vector()
{

    std::string buffer;
    std::getline(std::cin, buffer);
    std::istringstream stream(buffer);
    std::vector<T> vector;
    T input;
    while(stream >> input) { vector.push_back(input); }
    return vector;

}



// Read in a string from the standard input stream.
namespace NSA1 = std_bhm::parameters::from_std_cin;

std::string NSA1::to_string()
{

    std::string buffer;
    std::getline(std::cin, buffer);
    return buffer;

}



// Explicit instantiations of the free public functions

// --- Explicit instantions of to_value(...) ---
namespace NSA1 = std_bhm::parameters::from_std_cin;

template double NSA1::to_value<double>();
template int NSA1::to_value<int>();



// --- Explicit instantions of to_vector(...) ---
namespace NSA1 = std_bhm::parameters::from_std_cin;

template std::vector<double> NSA1::to_vector<double>();
template std::vector<int> NSA1::to_vector<int>();
