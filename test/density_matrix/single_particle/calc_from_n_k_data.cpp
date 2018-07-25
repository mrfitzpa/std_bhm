// /std_bhm/test/density_matrix/single_particle/calc_from_n_k_data.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/density_matrix/single_particle
// /calc_from_n_k_data.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <string>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "density_matrix/single_particle/calc_from_n_k_data.h"
#include "os/get_abs_path_of_exe.h"
#include "str_ops/replace.h"
#include "parameters/from_std_cin.h"
#include "k_map/gen_minimal_k_ints_set.h"
#include "parameters/read_spatial_params_off_sys_data_dir_name.h"
#include "hopping/spatial_params.h"
#include "output/vector_to_string.h"



namespace NSA1 = std_bhm::os;
namespace NSA2 = std_bhm::str_ops;
namespace NSA3 = std_bhm::density_matrix::single_particle;
namespace NSA4 = std_bhm::parameters;
namespace NSA5 = NSA4::from_std_cin;
namespace NSA6 = std_bhm::k_map;
namespace NSA7 = std_bhm::output;

int main(int argc, char** argv)
{
    std::cout << "Testing the function "
	      << "'std_bhm::density_matrix::single_particle::"
	      << "calc_from_n_k_data(...)': \n"
	      << std::endl;

    const auto abs_path_of_exe = ::NSA1::get_abs_path_of_exe();
    const auto substr_index = abs_path_of_exe.find_last_of("/\\");
    auto abs_dir_name_for_sys_data_set
	= abs_path_of_exe.substr(0, substr_index);
    ::NSA2::replace(abs_dir_name_for_sys_data_set, "/bin/", "/data/");
    abs_dir_name_for_sys_data_set
	+= "/d_3 L_6 beta_100 mu_0.42 jf_0.03 tc_100 tauQ_5 ds_0.05 Ns_1001";

    const auto& density_matrix
	= ::NSA3::calc_from_n_k_data(abs_dir_name_for_sys_data_set);

    const auto& sp_params = ::NSA4::read_spatial_params_off_sys_data_dir_name
	                                (abs_dir_name_for_sys_data_set);

    // Note that delta_r_ints_set = k_ints_set
    const auto delta_r_ints_set = ::NSA6::gen_minimal_k_ints_set(sp_params);
   
    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    const auto index = ::NSA5::to_value<int>();
    const auto& density_matrix_element = density_matrix[index];
    const auto& delta_r_ints = delta_r_ints_set[index];
    const auto Ns = density_matrix_element.size();
    std::cout << "Printing density_matrix_element contents for delta_r_ints = "
	      << ::NSA7::vector_1d_to_string(delta_r_ints) << ":" << std::endl;
    for(auto i=decltype(10){0}; i<10; i++)
    {
	std::cout << "density_matrix_element[" << i << "] = "
		  << density_matrix_element[i] << std::endl;
    }
    for(auto i=decltype(Ns){Ns-10}; i<Ns; i++)
    {
	std::cout << "density_matrix_element[" << i << "] = "
		  << density_matrix_element[i] << std::endl;
    }
    
    return 0;
}

