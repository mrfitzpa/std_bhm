// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/array_gen
// /X_K_rho.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen/X_K_rho.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen/atomic_func_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen/step_params.h"
#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/finite_temperature/local/kinetic_propagator.h"



// Generate a matrix representation of X_K_rho.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::array_gen;
namespace NSA4 = NSA3::X_K_rho_detail;

namespace NSA5 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

cmplx_vec NSA4::X_K_rho(const ::NSA3::atomic_func_params& af_params)
{
    const auto& l_params = af_params.get_local_params();
    const auto kinetic_propagator = ::NSA5::kinetic_propagator(l_params);

    const auto& s_params = af_params.get_step_params();
    const auto step_offset = s_params.get_step_offset();
    const auto ds = s_params.get_ds();
    const auto s_offset = step_offset * ds;
    const auto i_ds = cmplx_dbl(0, ds);
    
    const auto Ns = s_params.get_Ns();
    const auto two_Ns = 2 * Ns;
    auto array_form = cmplx_vec(Ns);

    for(auto l=decltype(two_Ns){0}; l<two_Ns; l++)
    {
	double s = (l - Ns) * ds + s_offset;
	array_form[l] = i_ds * kinetic_propagator.eval(s);
    }

    return array_form;
}
