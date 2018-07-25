// std_bhm/src/k_map/k_ints_to_k_vec.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <cmath>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "k_map/k_ints_to_k_vec.h"



// Convert k-vector to k-integer sequence.
namespace NSA1 = std_bhm::k_map::k_ints_to_k_vec_detail;

using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;

dbl_vec NSA1::k_ints_to_k_vec(int_vec k_ints, int L)
{
    auto k_vec = dbl_vec();
    for(const auto& k_element : k_ints)
    {
	const auto two_pi = atan(1.0) * 8.0;
	k_vec.push_back( (two_pi * k_element) / L );
    }
    
    return k_vec;
}
