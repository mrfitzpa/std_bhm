// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/from_std_cin
// /constr_local_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_local_params.h"

#include "atomic_lim/local/params.h"

#include "parameters/from_std_cin.h"



// Construct a 'local_params' object by reading values from std::cin.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::from_std_cin::constr_local_params_detail;

namespace NSA4 = std_bhm::parameters::from_std_cin;

using local_params = std_bhm::atomic_lim::local::params;

local_params NSA3::constr_local_params()
{
    const auto beta = ::NSA4::to_value<double>();
    const auto mu = ::NSA4::to_value<double>();
    const auto max_band_index = ::NSA4::to_value<int>();

    return local_params{beta, mu, max_band_index};
}
