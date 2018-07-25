// std_bhm/include/n_k/load_n_k_data_array.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_N_K_LOAD_N_K_DATA_ARRAY_H
#define STD_BHM_N_K_LOAD_N_K_DATA_ARRAY_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */


namespace std_bhm
{
namespace n_k
{
namespace load_n_k_data_array_detail
{

using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;

dbl_vec load_n_k_data_array(const int_vec& k_ints,
			    const std::string& abs_sys_data_set_dir_name);

} // end of load_n_k_data_array_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::n_k::load_n_k_data_array_detail::load_n_k_data_array;



} // end of n_k namespace
} // end of std_bhm namespace


#endif
