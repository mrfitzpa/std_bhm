// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/g/K.cpp

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
start_in_atomic_lim/block_by_block/hfb/g/K.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"

#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/finite_temperature/local/kinetic_propagator.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

namespace NSA5 = NSA3::k_eqn;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

struct NSA4::K::impl
{
    impl(const ::NSA5::params& k_eqn_params);

    const cmplx_vec array_rep;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

namespace NSA5 = NSA3::k_eqn;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

namespace unnamed
{
namespace
{

const cmplx_vec gen_array(const ::NSA5::params& k_eqn_params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// K constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

namespace NSA5 = NSA3::k_eqn;

NSA4::K::K(const ::NSA5::params& k_eqn_params)
    : pimpl{ spimpl::make_impl<impl>(k_eqn_params) }
{}



// K::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

namespace NSA5 = NSA3::k_eqn;

NSA4::K::impl::impl(const ::NSA5::params& k_eqn_params)
    : array_rep( ::unnamed::gen_array(k_eqn_params) )
{}



// Generate array representation.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

namespace NSA5 = NSA3::k_eqn;

namespace NSA6 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

namespace unnamed
{
namespace
{

const cmplx_vec gen_array(const ::NSA5::params& k_eqn_params)
{
    const auto& l_params = k_eqn_params.get_local_params();
    const auto kinetic_propagator = ::NSA6::kinetic_propagator(l_params);

    const auto& s_params = k_eqn_params.get_step_params();
    const auto ds = s_params.get_ds();
    
    const auto n_block_steps = s_params.get_n_block_steps();
    const auto Ns = 2 * (n_block_steps + 1);
    auto array_rep = cmplx_vec(Ns);

    for(auto l=decltype(Ns){0}; l<Ns; l++)
    {
	double s = -l * ds;
	array_rep[l] = kinetic_propagator.eval(s);
    }

    return array_rep;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Evaluate g_K.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

cmplx_dbl NSA4::K::do_eval(int l1, int l2) const
{
    const auto index = l2 - l1;
    return pimpl->array_rep[index];
}
