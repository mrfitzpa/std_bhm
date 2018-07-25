// std_bhm/src/k_map/k_vec_to_k_ints.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <cmath>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "k_map/k_vec_to_k_ints.h"



// Convert k-vector to k-integer sequence.
namespace NSA1 = std_bhm::k_map::k_vec_to_k_ints_detail;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

int_vec NSA1::k_vec_to_k_ints(dbl_vec k_vec, int L)
{
    auto k_ints = int_vec();
    for(const auto& k_element : k_vec)
    {
	const auto two_pi = atan(1.0) * 8.0;
	const auto k_int = int( round(L * k_element / two_pi) );
	k_ints.push_back(k_int);
    }
    
    return k_ints;
}
