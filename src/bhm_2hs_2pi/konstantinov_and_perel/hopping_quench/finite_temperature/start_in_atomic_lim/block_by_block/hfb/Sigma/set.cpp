// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Sigma/set.cpp

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
start_in_atomic_lim/block_by_block/hfb/Sigma/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/element.h"

#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

namespace NSA4 = NSA2::hfb::k_eqn;
namespace NSA5 = NSA2::hfb::Y;
namespace NSA6 = NSA2::hfb::Z;

using dbl_vec = std::vector<double>;

struct NSA3::set::impl
{
    impl(const ::NSA4::params& k_eqn_params, const dbl_vec& n_array);

    const ::NSA5::set Y_set;
    const ::NSA6::set Z_set;

    const ::NSA3::element Sigma_rho_rho_1;
    const ::NSA3::element Sigma_rho_rho_2;
    const ::NSA3::element Sigma_rho_rho_3;

    const ::NSA3::element Sigma_rho_K_4;
    const ::NSA3::element Sigma_rho_K_5;
    const ::NSA3::element Sigma_rho_K_6;

    const ::NSA3::element Sigma_K_rho_1;
    const ::NSA3::element Sigma_K_rho_2;
    const ::NSA3::element Sigma_K_rho_3;
};



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

namespace NSA4 = NSA2::hfb::k_eqn;
namespace NSA5 = NSA2::hfb::Y;
namespace NSA6 = NSA2::hfb::Z;

using dbl_vec = std::vector<double>;

NSA3::set::set(const ::NSA4::params& k_eqn_params, const dbl_vec& n_array)
    : pimpl{ spimpl::make_impl<impl>(k_eqn_params, n_array) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

namespace NSA4 = NSA2::hfb::k_eqn;
namespace NSA5 = NSA2::hfb::Y;
namespace NSA6 = NSA2::hfb::Z;

using dbl_vec = std::vector<double>;

NSA3::set::impl::impl(const ::NSA4::params& k_eqn_params,
		      const dbl_vec& n_array)
    : Y_set{k_eqn_params},
      Z_set{n_array},
      Sigma_rho_rho_1{ Y_set.get_rho_rho_A(),
		       Z_set.get_type_1(),
		       k_eqn_params.get_local_params() },
      Sigma_rho_rho_2{ Y_set.get_rho_rho_B(),
		       Z_set.get_type_2(),
		       k_eqn_params.get_local_params() },
      Sigma_rho_rho_3{ Y_set.get_rho_rho_B(),
		       Z_set.get_type_3(),
		       k_eqn_params.get_local_params() },
      Sigma_rho_K_4{ Y_set.get_rho_K_A(),
		     Z_set.get_type_4(),
		     k_eqn_params.get_local_params() },
      Sigma_rho_K_5{ Y_set.get_rho_K_B(),
		     Z_set.get_type_5(),
		     k_eqn_params.get_local_params() },
      Sigma_rho_K_6{ Y_set.get_rho_K_B(),
		     Z_set.get_type_6(),
		     k_eqn_params.get_local_params() },
      Sigma_K_rho_1{ Y_set.get_K_rho_A(),
		     Z_set.get_type_1(),
		     k_eqn_params.get_local_params() },
      Sigma_K_rho_2{ Y_set.get_K_rho_B(),
		     Z_set.get_type_2(),
		     k_eqn_params.get_local_params() },
      Sigma_K_rho_3{ Y_set.get_K_rho_B(),
		     Z_set.get_type_3(),
		     k_eqn_params.get_local_params() }
{}



// Get Sigma_rho_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

const NSA3::element NSA3::set::get_rho_rho_1() const
{
    return pimpl->Sigma_rho_rho_1;
}



// Get Sigma_rho_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

const NSA3::element NSA3::set::get_rho_rho_2() const
{
    return pimpl->Sigma_rho_rho_2;
}



// Get Sigma_rho_rho_3 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

const NSA3::element NSA3::set::get_rho_rho_3() const
{
    return pimpl->Sigma_rho_rho_3;
}



// Get Sigma_rho_K_4 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

const NSA3::element NSA3::set::get_rho_K_4() const
{
    return pimpl->Sigma_rho_K_4;
}



// Get Sigma_rho_K_5 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

const NSA3::element NSA3::set::get_rho_K_5() const
{
    return pimpl->Sigma_rho_K_5;
}



// Get Sigma_rho_K_6 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

const NSA3::element NSA3::set::get_rho_K_6() const
{
    return pimpl->Sigma_rho_K_6;
}



// Get Sigma_K_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

const NSA3::element NSA3::set::get_K_rho_1() const
{
    return pimpl->Sigma_K_rho_1;
}



// Get Sigma_K_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

const NSA3::element NSA3::set::get_K_rho_2() const
{
    return pimpl->Sigma_K_rho_2;
}



// Get Sigma_K_rho_3 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Sigma;

const NSA3::element NSA3::set::get_K_rho_3() const
{
    return pimpl->Sigma_K_rho_3;
}
