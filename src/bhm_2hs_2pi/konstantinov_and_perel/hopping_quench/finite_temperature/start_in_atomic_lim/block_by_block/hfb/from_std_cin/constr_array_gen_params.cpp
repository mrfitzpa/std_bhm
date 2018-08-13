// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/from_std_cin
// /constr_array_gen_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_array_gen_params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen_params.h"

#include "parameters/from_std_cin.h"



// Construct a 'array_gen_params' object by reading values from std::cin.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::from_std_cin::constr_array_gen_params_detail;

namespace NSA5 = std_bhm::parameters::from_std_cin;

NSA3::array_gen_params NSA4::constr_array_gen_params()
{
    const auto Ns = ::NSA5::to_value<int>();
    const auto ds = ::NSA5::to_value<double>();
    const auto step_offset = ::NSA5::to_value<double>();

    return ::NSA3::array_gen_params{Ns, ds, step_offset};
}
