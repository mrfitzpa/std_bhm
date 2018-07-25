// std_bhm/src/math/mod.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "math/mod.h"



// Generate a mod for a given vector.
namespace NSA1 = std_bhm::math;

int NSA1::mod(int n, int m) { return ((n%m) + m)%m; }
