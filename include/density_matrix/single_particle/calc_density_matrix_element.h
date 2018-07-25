// std_bhm/include/density_matrix/single_particle/calc_density_matrix_element.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_DENSITY_MATRIX_SINGLE_PARTICLE_CALC_DENSITY_MATRIX_ELEMENT_H
#define STD_BHM_DENSITY_MATRIX_SINGLE_PARTICLE_CALC_DENSITY_MATRIX_ELEMENT_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */


namespace std_bhm
{
namespace density_matrix
{
namespace single_particle
{
namespace calc_density_matrix_element_detail
{

using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

dbl_vec calc_density_matrix_element(const int_vec& delta_r_ints,
				    const dbl_vec_2d& n_k_arrays,
				    int L);

} // end of calc_density_matrix_element_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::density_matrix::single_particle::\
calc_density_matrix_element_detail::calc_density_matrix_element;



} // end of single_particle namespace
} // end of density_matrix namespace
} // end of std_bhm namespace


#endif
