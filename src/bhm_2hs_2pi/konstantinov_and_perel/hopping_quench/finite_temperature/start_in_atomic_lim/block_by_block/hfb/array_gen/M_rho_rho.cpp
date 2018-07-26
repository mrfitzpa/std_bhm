// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/array_gen
// /M_rho_rho.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen/M_rho_rho.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen/atomic_func_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen/step_params.h"
#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/finite_temperature/local/spectral_func.h"



// Generate a vector-array which stores the time series of the -i*ds*A0_12
// based on the parameters passed in.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::array_gen;
namespace NSA4 = NSA3::M_rho_rho_detail;

namespace NSA5 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

cmplx_vec NSA4::M_rho_rho(const ::NSA3::atomic_func_params& af_params)
{
    const auto& l_params = af_params.get_local_params();
    const auto spectral_func = ::NSA5::spectral_func(l_params);

    const auto& s_params = af_params.get_step_params();
    const auto step_offset = s_params.get_step_offset();
    const auto ds = s_params.get_ds();
    const auto s_offset = step_offset * ds;
    const auto neg_i_ds = cmplx_dbl(0, -ds);
    
    const auto Ns = s_params.get_Ns();
    auto array_form = cmplx_vec(Ns);

    for(auto l=decltype(Ns){0}; l<Ns; l++)
    {
	double s = -l * ds + s_offset;
	array_form[l] = neg_i_ds * spectral_func.eval(s);
    }

    return array_form;
}
