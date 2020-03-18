// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/from_std_cin
// /constr_quench_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_quench_params.h"

#include "hopping/quench/linear/quench_params.h"

#include "parameters/from_std_cin.h"



// Construct a 'quench_params' object by reading values from std::cin.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::from_std_cin::constr_quench_params_detail;

namespace NSA4 = std_bhm::hopping::quench::linear;

namespace NSA5 = std_bhm::parameters::from_std_cin;

NSA4::quench_params NSA3::constr_quench_params()
{
    const auto jf = ::NSA5::to_value<double>();
    const auto tc = ::NSA5::to_value<double>();
    const auto tau_Q = ::NSA5::to_value<double>();

    return ::NSA4::quench_params{0.0, jf, tc, tau_Q};
}
