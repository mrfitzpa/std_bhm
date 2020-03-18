// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/sim
// /gen_abs_filename_for_n_k_data_file.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <string>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/sim/gen_abs_filename_for_n_k_data_file.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/sim/gen_system_data_set_directory_name.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/sim/alg_1_params.h"

#include "output/gen_abs_pathname_for_output_directories.h"



// Generate absolute filename for n_k data file (to be written presumably).
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::sim;
namespace NSA4 = NSA3::gen_abs_filename_for_n_k_data_file_detail;

namespace NSA5 = std_bhm::output;

using int_vec = std::vector<int>;

std::string NSA4::gen_abs_filename_for_n_k_data_file(
                      const NSA3::alg_1_params& sim_params,
		      const int_vec& k_ints)
{
    const auto abs_pathname_for_output_directories
	= ::NSA5::gen_abs_pathname_for_output_directories();
    const auto system_data_set_directory_name
	= ::NSA3::gen_system_data_set_directory_name(sim_params);

    auto k_ints_str_rep = std::string();
    for(const auto& k_int : k_ints)
	k_ints_str_rep += " " + std::to_string(k_int);
    k_ints_str_rep += ".txt";

    return (abs_pathname_for_output_directories + "/"
	    + system_data_set_directory_name + "/"
	    + "n_k data/k-vector"
	    + k_ints_str_rep);
}
