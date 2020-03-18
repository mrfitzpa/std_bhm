// std_bhm/include/k_map/k_ints_to_k_vec.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_K_MAP_K_INTS_TO_K_VEC_H
#define STD_BHM_K_MAP_K_INTS_TO_K_VEC_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace k_map
{
namespace k_ints_to_k_vec_detail
{

using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;

dbl_vec k_ints_to_k_vec(int_vec k_ints, int L);

} // end of k_ints_to_k_vec_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::k_map::k_ints_to_k_vec_detail::k_ints_to_k_vec;



} // end of k_map namespace
} // end of std_bhm namespace


#endif
