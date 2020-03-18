// std_bhm/include/k_map/gen_minimal_k_vec_set.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_K_MAP_GEN_MINIMAL_K_VEC_SET_H
#define STD_BHM_K_MAP_GEN_MINIMAL_K_VEC_SET_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "hopping/spatial_params.h"



namespace std_bhm
{
namespace k_map
{
namespace gen_minimal_k_vec_set_detail
{

namespace NSA1 = std_bhm::hopping;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

dbl_vec_2d gen_minimal_k_vec_set(const NSA1::spatial_params& sp_params);

} // end of gen_minimal_k_vec_set_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::k_map::gen_minimal_k_vec_set_detail::gen_minimal_k_vec_set;



} // end of k_map namespace
} // end of std_bhm namespace


#endif
