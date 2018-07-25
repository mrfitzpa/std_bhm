// std_bhm/src/str_ops/replace.cpp

// -----------------------------------------------------------------------

// Function definition taken from https://stackoverflow.com/questions
// /3418231/replace-part-of-a-string-with-another-string

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <string>
#include <cstddef>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "str_ops/replace.h"



// Replaces first instance of sub-string 'from' inside string 'str' with
// sub-string 'to'.
namespace NSA1 = std_bhm::str_ops;

bool NSA1::replace(std::string& str,
		   const std::string& from,
		   const std::string& to)
{
//    size_t start_pos = str.find(from);
    const auto start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
