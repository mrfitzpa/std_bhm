// std_bhm/src/n_k/load_n_k_data_arrays.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <string>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "n_k/load_n_k_data_arrays.h"
#include "n_k/load_n_k_data_array.h"
#include "hopping/spatial_params.h"
#include "parameters/read_spatial_params_off_sys_data_dir_name.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

void load_n_k_data_arrays_inner_loop
         (int depth,
	  int_vec& k_ints, 
	  int max,
	  dbl_vec_2d& n_k_arrays,
	  const std::string& abs_sys_data_set_dir_name);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace




// Load all quasi-momentum distribution (i.e. n_k) data_arrays files from a
// given system data set and store data_arrays into a std::vector for later use.
namespace NSA1 = std_bhm::n_k;
namespace NSA2 = NSA1::load_n_k_data_arrays_detail;
namespace NSA3 = std_bhm::parameters;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

dbl_vec_2d NSA2::load_n_k_data_arrays
                     (const std::string& abs_sys_data_set_dir_name)
{
    const auto& sp_params = ::NSA3::read_spatial_params_off_sys_data_dir_name(
	                                abs_sys_data_set_dir_name);
	
    const auto L = sp_params.get_L();
    const auto d = sp_params.get_d();
    
    auto n_k_arrays= dbl_vec_2d();
    auto k_ints = int_vec(d);

    ::unnamed::load_n_k_data_arrays_inner_loop(d,
					       k_ints,
					       L/2,
					       n_k_arrays,
					       abs_sys_data_set_dir_name);

    return n_k_arrays;
}



// A recursive for-loop to load the n_k data_arrays from each data_arrays file.
namespace NSA1 = std_bhm::n_k;

namespace unnamed
{
namespace
{

void load_n_k_data_arrays_inner_loop
         (int depth,
	  int_vec& k_ints, 
	  int max,
	  dbl_vec_2d& n_k_arrays,
	  const std::string& abs_sys_data_set_dir_name)
{
    if(depth > 0)
    {
	for(int i=0; i<=max; i++)
	{
	    int d = k_ints.size();
	    k_ints[d-depth] = i;
	    unnamed::load_n_k_data_arrays_inner_loop(depth-1, k_ints,
						     i, n_k_arrays,
						     abs_sys_data_set_dir_name);
	}
    }
    else
    {
	const auto n_k_array
	    = ::NSA1::load_n_k_data_array(k_ints, abs_sys_data_set_dir_name); 
	n_k_arrays.push_back(n_k_array);
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
