// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/sim
// /gen_abs_filename_for_output_file.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_SIM_\
GEN_ABS_FILENAME_FOR_OUTPUT_FILE_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_SIM_\
GEN_ABS_FILENAME_FOR_OUTPUT_FILE_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace bhm_2hs_2pi
{
namespace konstantinov_and_perel
{
namespace hopping_quench
{
namespace finite_temperature
{
namespace start_in_atomic_lim
{
namespace block_by_block
{
namespace hfb
{
namespace sim
{



namespace alg_1_params_detail
{
class alg_1_params; // forward declaration
}



namespace gen_abs_filename_for_output_file_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::sim::alg_1_params_detail;

using int_vec = std::vector<int>;

std::string gen_abs_filename_for_output_file(
                const NSA3::alg_1_params& sim_params,
		const int_vec& vec_index,
		const std::string& lowest_level_dir_name_and_file_prefix);

} // end of gen_abs_filename_for_output_file_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::sim::\
gen_abs_filename_for_output_file_detail::\
gen_abs_filename_for_output_file;



} // end of sim namespace
} // end of hfb namespace
} // end of block_by_block namespace
} // end of start_in_atomic_lim namespace
} // end of finite_temperature namespace
} // end of hopping_quench namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
 
