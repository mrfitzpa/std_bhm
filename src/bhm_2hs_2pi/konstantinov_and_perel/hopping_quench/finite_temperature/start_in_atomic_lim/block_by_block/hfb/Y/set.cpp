// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Y/set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/rho_rho.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/rho_K.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/K_rho.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Y;

namespace NSA4 = NSA2::hfb::k_eqn;

struct NSA3::set::impl
{
    impl(const ::NSA4::params& k_eqn_params);

    const ::NSA3::rho_rho Y_rho_rho_A;
    const ::NSA3::rho_rho Y_rho_rho_B;

    const ::NSA3::rho_K Y_rho_K_A;
    const ::NSA3::rho_K Y_rho_K_B;

    const ::NSA3::K_rho Y_K_rho_A;
    const ::NSA3::K_rho Y_K_rho_B;
};



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Y;

namespace NSA4 = NSA2::hfb::k_eqn;

NSA3::set::set(const ::NSA4::params& k_eqn_params)
    : pimpl{ spimpl::make_impl<impl>(k_eqn_params) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Y;

namespace NSA4 = NSA2::hfb::k_eqn;

NSA3::set::impl::impl(const ::NSA4::params& k_eqn_params)
    : Y_rho_rho_A{k_eqn_params, 0.0}, Y_rho_rho_B{k_eqn_params, -0.5},
      Y_rho_K_A{k_eqn_params, 0.0}, Y_rho_K_B{k_eqn_params, 0.5},
      Y_K_rho_A{k_eqn_params, 0.0}, Y_K_rho_B{k_eqn_params, -0.5}
{}



// Get Y_rho_rho_A reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Y;

const NSA3::element& NSA3::set::get_rho_rho_A() const
{
    return pimpl->Y_rho_rho_A;
}



// Get Y_rho_rho_B reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Y;

const NSA3::element& NSA3::set::get_rho_rho_B() const
{
    return pimpl->Y_rho_rho_B;
}



// Get Y_rho_K_A reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Y;

const NSA3::element& NSA3::set::get_rho_K_A() const
{
    return pimpl->Y_rho_K_A;
}



// Get Y_rho_K_B reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Y;

const NSA3::element& NSA3::set::get_rho_K_B() const
{
    return pimpl->Y_rho_K_B;
}



// Get Y_K_rho_A reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Y;

const NSA3::element& NSA3::set::get_K_rho_A() const
{
    return pimpl->Y_K_rho_A;
}



// Get Y_K_rho_B reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Y;

const NSA3::element& NSA3::set::get_K_rho_B() const
{
    return pimpl->Y_K_rho_B;
}
