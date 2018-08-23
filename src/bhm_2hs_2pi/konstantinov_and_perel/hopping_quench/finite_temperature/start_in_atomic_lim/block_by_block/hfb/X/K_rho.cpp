// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/X/K_rho.cpp

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
start_in_atomic_lim/block_by_block/hfb/X/K_rho.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element_params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen_params.h"

#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/finite_temperature/local/kinetic_propagator.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

struct NSA4::K_rho::impl
{
    impl(const ::NSA4::element_params& x_element_params);

    const int Ns;
    const cmplx_vec array_rep;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

namespace unnamed
{
namespace
{

int get_Ns(const ::NSA4::element_params& x_element_params);
const cmplx_vec gen_array(const ::NSA4::element_params& x_element_params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// K_rho constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

NSA4::K_rho::K_rho(const ::NSA4::element_params& x_element_params)
    : pimpl{ spimpl::make_impl<impl>(x_element_params) }
{}



// K_rho::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

NSA4::K_rho::impl::impl(const ::NSA4::element_params& x_element_params)
    : Ns{ ::unnamed::get_Ns(x_element_params) },
      array_rep( ::unnamed::gen_array(x_element_params) )
{}



// Extract 'Ns' from the X-parameters
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

int get_Ns(const ::NSA4::element_params& x_element_params)
{
    const auto& ag_params = x_element_params.get_array_gen_params();
    const auto Ns = ag_params.get_Ns();

    return Ns;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate array representation.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace NSA5 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

namespace unnamed
{
namespace
{

const cmplx_vec gen_array(const ::NSA4::element_params& x_element_params)
{
    const auto& l_params = x_element_params.get_local_params();
    const auto kinetic_propagator = ::NSA5::kinetic_propagator(l_params);

    const auto& ag_params = x_element_params.get_array_gen_params();
    const auto ds = ag_params.get_ds();
    const auto step_offset = ag_params.get_step_offset();
    const auto s_offset = step_offset * ds;
    const auto i_ds = cmplx_dbl(0, ds);
    
    const auto Ns = ag_params.get_Ns();
    const auto two_Ns = 2 * Ns;
    auto array_rep = cmplx_vec(two_Ns);

    for(auto l=decltype(two_Ns){0}; l<two_Ns; l++)
    {
	double s = -(l - Ns) * ds + s_offset;
	array_rep[l] = i_ds * kinetic_propagator.eval(s);
    }

    return array_rep;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Evaluate X_K_rho.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

cmplx_dbl NSA4::K_rho::do_eval(int l1, int l2, int l3) const
{
    const auto index = l2 - l1 - l3 + pimpl->Ns;
    return pimpl->array_rep[index];
}
