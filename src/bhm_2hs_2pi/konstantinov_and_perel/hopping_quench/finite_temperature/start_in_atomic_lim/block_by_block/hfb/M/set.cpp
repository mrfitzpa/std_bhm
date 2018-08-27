// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M/set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;
namespace NSA7 = NSA3::k_eqn;

using dbl_vec = std::vector<double>;

struct NSA4::set::impl
{
    impl(const ::NSA7::params& k_eqn_params, const dbl_vec& n_array);

    const ::NSA5::set X_set;
    const ::NSA6::set Sigma_set;
    
    const ::NSA4::element M_rho_rho_1;
    const ::NSA4::element M_rho_rho_2;
    const ::NSA4::element M_rho_rho_3;

    const ::NSA4::element M_rho_K_4;
    const ::NSA4::element M_rho_K_5;
    const ::NSA4::element M_rho_K_6;

    const ::NSA4::element M_K_rho_1;
    const ::NSA4::element M_K_rho_2;
    const ::NSA4::element M_K_rho_3;
};



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA7 = NSA3::k_eqn;

NSA4::set::set(const ::NSA7::params& k_eqn_params, const dbl_vec& n_array)
    : pimpl{ spimpl::make_impl<impl>(k_eqn_params, n_array) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA7 = NSA3::k_eqn;

NSA4::set::impl::impl(const ::NSA7::params& k_eqn_params, const dbl_vec& n_array)
    : X_set{k_eqn_params},
      Sigma_set{k_eqn_params, n_array},
      M_rho_rho_1{ X_set.get_rho_rho_A(), Sigma_set.get_rho_rho_1() },
      M_rho_rho_2{ X_set.get_rho_rho_B(), Sigma_set.get_rho_rho_2() },
      M_rho_rho_3{ X_set.get_rho_rho_B(), Sigma_set.get_rho_rho_3() },
      M_rho_K_4{ X_set.get_rho_K_A(), Sigma_set.get_rho_K_4() },
      M_rho_K_5{ X_set.get_rho_K_B(), Sigma_set.get_rho_K_5() },
      M_rho_K_6{ X_set.get_rho_K_B(), Sigma_set.get_rho_K_6() },
      M_K_rho_1{ X_set.get_K_rho_A(), Sigma_set.get_K_rho_1() },
      M_K_rho_2{ X_set.get_K_rho_B(), Sigma_set.get_K_rho_2() },
      M_K_rho_3{ X_set.get_K_rho_B(), Sigma_set.get_K_rho_3() }
{}



// Get M_rho_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_rho_1() const
{
    return pimpl->M_rho_rho_1;
}



// Get M_rho_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_rho_2() const
{
    return pimpl->M_rho_rho_2;
}



// Get M_rho_rho_3 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_rho_3() const
{
    return pimpl->M_rho_rho_3;
}



// Get M_rho_K_4 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_K_4() const
{
    return pimpl->M_rho_K_4;
}



// Get M_rho_K_5 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_K_5() const
{
    return pimpl->M_rho_K_5;
}



// Get M_rho_K_6 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_K_6() const
{
    return pimpl->M_rho_K_6;
}



// Get M_K_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_K_rho_1() const
{
    return pimpl->M_K_rho_1;
}



// Get M_K_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_K_rho_2() const
{
    return pimpl->M_K_rho_2;
}



// Get M_K_rho_3 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_K_rho_3() const
{
    return pimpl->M_K_rho_3;
}
