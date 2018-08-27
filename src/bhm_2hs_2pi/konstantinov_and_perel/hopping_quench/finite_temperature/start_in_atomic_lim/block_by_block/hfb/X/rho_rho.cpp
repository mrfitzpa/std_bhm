// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/X/rho_rho.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <complex>
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/rho_rho.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"

#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/finite_temperature/local/spectral_func.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::X;

namespace NSA4 = NSA2::hfb::k_eqn;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

struct NSA3::rho_rho::impl
{
    impl(const ::NSA4::params& k_eqn_params, double step_offset);

    const cmplx_vec array_rep;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::X;

namespace NSA4 = NSA2::hfb::k_eqn;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

namespace unnamed
{
namespace
{

const cmplx_vec gen_array(const ::NSA4::params& k_eqn_params,
			  double step_offset);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// rho_rho constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::X;

namespace NSA4 = NSA2::hfb::k_eqn;

NSA3::rho_rho::rho_rho(const ::NSA4::params& k_eqn_params, double step_offset)
    : pimpl{ spimpl::make_impl<impl>(k_eqn_params, step_offset) }
{}



// rho_rho::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::X;

namespace NSA4 = NSA2::hfb::k_eqn;

NSA3::rho_rho::impl::impl(const ::NSA4::params& k_eqn_params, double step_offset)
    : array_rep( ::unnamed::gen_array(k_eqn_params, step_offset) )
{}



// Generate array representation.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::X;

namespace NSA4 = NSA2::hfb::k_eqn;
namespace NSA5 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

namespace unnamed
{
namespace
{

const cmplx_vec gen_array(const ::NSA4::params& k_eqn_params,
			  double step_offset)
{
    const auto& l_params = k_eqn_params.get_local_params();
    const auto spectral_func = ::NSA5::spectral_func(l_params);

    const auto& s_params = k_eqn_params.get_step_params();
    const auto ds = s_params.get_ds();
    const auto s_offset = step_offset * ds;
    const auto i_ds = cmplx_dbl(0, ds);
    
    const auto n_block_steps = s_params.get_n_block_steps();
    const auto Ns = 2 * (n_block_steps + 1);
    auto array_rep = cmplx_vec(Ns);

    for(auto l=decltype(Ns){0}; l<Ns; l++)
    {
	double s = -l * ds + s_offset;
	array_rep[l] = i_ds * spectral_func.eval(s);
    }

    return array_rep;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Evaluate X_rho_rho.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::X;

namespace NSA4 = NSA2::hfb::k_eqn;

cmplx_dbl NSA3::rho_rho::do_eval(int l1, int l2, int l3) const
{
    const auto index = l1 - l3;
    return pimpl->array_rep[index];
}
