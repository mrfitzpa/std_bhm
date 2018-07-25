// std_bhm/include/parameters/from_std_cin.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_PARAMETERS_FROM_STD_CIN_H
#define STD_BHM_PARAMETERS_FROM_STD_CIN_H

/* Include standard libraries */
#include <vector>
#include <string>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace parameters
{
namespace from_std_cin
{

template <class T>
T to_value();

template <class T>
std::vector<T> to_vector();

std::string to_string();

} // end of from_std_cin namespace
} // end of parameters namespace
} // end of std_bhm namespace


#endif
 
