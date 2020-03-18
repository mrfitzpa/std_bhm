// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/from_std_cin
// /constr_test_soln_arrays.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>
#include <algorithm>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_test_soln_arrays.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_k_eqn_params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/soln_arrays.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/element.h"

#include "parameters/from_std_cin.h"



// Construct a test n_array vector by reading values from std::cin.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::from_std_cin;
namespace NSA5 = NSA4::constr_test_soln_arrays_detail;

namespace NSA6 = NSA3::g;
namespace NSA7 = std_bhm::parameters::from_std_cin;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

NSA3::soln_arrays NSA5::constr_test_soln_arrays()
{
    const auto k_eqn_params = ::NSA4::constr_k_eqn_params();
    const auto g_set = ::NSA6::set{k_eqn_params};
    const auto& g_rho = g_set.get_rho();
    const auto& g_K = g_set.get_K();

    const auto n_block_steps = ::NSA7::to_value<int>();
    const auto Ns = 2 * (n_block_steps + 1);
    
    const auto l2 = ::NSA7::to_value<int>();

    auto test_y_rho = cmplx_vec(Ns);
    auto test_y_K = cmplx_vec(Ns);

    auto l1 = -1;
    std::generate(test_y_rho.begin(),
		  test_y_rho.end(),
		  [&]() { l1++; return g_rho.eval(l1, l2); });

    l1 = -1;
    std::generate(test_y_K.begin(),
		  test_y_K.end(),
		  [&]() { l1++; return g_K.eval(l1, l2); });

    return ::NSA3::soln_arrays{test_y_rho, test_y_K};
}
