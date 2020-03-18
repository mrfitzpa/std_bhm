// std_bhm/src/str_ops/to_string_no_trailing_zeros.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <string>
#include <typeinfo>

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "str_ops/to_string_no_trailing_zeros.h"



// Convert numerical value to string with no trailing zeros.
namespace NSA1 = std_bhm::str_ops;

template <class T>
std::string NSA1::to_string_no_trailing_zeros(T value)
{
    auto str = std::to_string(value);

    if ( typeid(T) == typeid(int) )
	return str;
    
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (str.back() == '.')
	str.pop_back();

    return str;
}



// Explicit instantiations of the free public functions

// --- Explicit instantions of to_string_no_trailing_zeros(...) ---
namespace NSA1 = std_bhm::str_ops;

template std::string NSA1::to_string_no_trailing_zeros(int value);
template std::string NSA1::to_string_no_trailing_zeros(double value);
