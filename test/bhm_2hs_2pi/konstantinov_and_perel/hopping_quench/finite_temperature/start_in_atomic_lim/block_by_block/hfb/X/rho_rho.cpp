// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/X/rho_rho.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the class(es) defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block
// /hfb/X/rho_rho.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/rho_rho.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/base.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"

#include "atomic_lim/local/params.h"

#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace NSA5 = std_bhm::parameters::from_std_cin;

using local_params = std_bhm::atomic_lim::local::params;

int main(int argc, char** argv)
{
    const auto beta = ::NSA5::to_value<double>();
    const auto mu = ::NSA5::to_value<double>();
    const auto max_band_index = ::NSA5::to_value<int>();
    const auto& l_params = local_params{beta, mu, max_band_index};

    const auto ds = ::NSA5::to_value<double>();
    const auto Ns = ::NSA5::to_value<int>();
    const auto step_offset = ::NSA5::to_value<double>();
    const auto& s_params = ::NSA3::step_params{Ns, ds, step_offset};

    const auto& x_params = ::NSA4::params{l_params, s_params};
    const auto& X_rho_rho = ::NSA4::rho_rho(x_params);

    const auto l1 = ::NSA5::to_value<int>();
    const auto l2 = ::NSA5::to_value<int>();
    const auto l3 = ::NSA5::to_value<int>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    std::cout << "X_rho_rho(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << X_rho_rho.eval(l1, l2, l3) << std::endl;
    
    return 0;
}
