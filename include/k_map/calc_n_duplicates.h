// std_bhm/include/k_map/calc_n_duplicates.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_K_MAP_CALC_N_DUPLICATES_H
#define STD_BHM_K_MAP_CALC_N_DUPLICATES_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace k_map
{
namespace calc_n_duplicates_detail
{

using dbl_vec = std::vector<double>;

int calc_n_duplicates(dbl_vec k_vec);

} // end of calc_n_duplicates_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::k_map::calc_n_duplicates_detail::calc_n_duplicates;



} // end of k_map namespace
} // end of std_bhm namespace


#endif
