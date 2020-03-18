// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/g/set.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the class(es) defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block
// /hfb/g/set.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_k_eqn_params.h"

#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::from_std_cin;
namespace NSA5 = NSA3::g;

namespace NSA6 = std_bhm::parameters::from_std_cin;

int main(int argc, char** argv)
{
    const auto k_eqn_params = ::NSA4::constr_k_eqn_params();
    const auto& g_set = ::NSA5::set(k_eqn_params);

    const auto l1 = ::NSA6::to_value<int>();
    const auto l2 = ::NSA6::to_value<int>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    const auto& g_rho = g_set.get_rho();
    const auto& g_K = g_set.get_K();

    std::cout << "g_rho(" << l1 << ", " << l2 << ") = "
	      << g_rho.eval(l1, l2) << std::endl;

    std::cout << "g_K(" << l1 << ", " << l2 << ") = "
	      << g_K.eval(l1, l2) << std::endl;
    
    return 0;
}
