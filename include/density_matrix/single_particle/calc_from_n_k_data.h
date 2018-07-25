// std_bhm/include/density_matrix/single_particle/calc_from_n_k_data.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_DENSITY_MATRIX_SINGLE_PARTICLE_CALC_FROM_N_K_DATA_H
#define STD_BHM_DENSITY_MATRIX_SINGLE_PARTICLE_CALC_FROM_N_K_DATA_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */


namespace std_bhm
{



namespace hopping
{
class spatial_params; // forward declaration
}



namespace density_matrix
{
namespace single_particle
{
namespace calc_from_n_k_data_detail
{
namespace NSA1 = std_bhm::hopping;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

dbl_vec_2d calc_from_n_k_data(const std::string& abs_sys_data_set_dir_name);
dbl_vec_2d calc_from_n_k_data(const NSA1::spatial_params& sp_params,
			      const dbl_vec_2d& n_k_arrays);

} // end of calc_from_n_k_data_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::density_matrix::single_particle::\
calc_from_n_k_data_detail::calc_from_n_k_data;



} // end of single_particle namespace
} // end of density_matrix namespace
} // end of std_bhm namespace


#endif
