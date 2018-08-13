// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Y/params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/epsilon_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen_params.h"

#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

using local_params = std_bhm::atomic_lim::local::params;

struct NSA4::params::impl
{
    impl(const local_params& l_params,
	 const ::NSA3::epsilon_params& e_params,
	 const ::NSA3::array_gen_params& ag_params);

    const local_params l_params;
    const ::NSA3::epsilon_params e_params;
    const NSA3::array_gen_params ag_params;
};



// params constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

using local_params = std_bhm::atomic_lim::local::params;

NSA4::params::params(const local_params& l_params,
		     const ::NSA3::epsilon_params& e_params,
		     const ::NSA3::array_gen_params& ag_params)
    : pimpl{ spimpl::make_impl<impl>(l_params, e_params, ag_params) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

using local_params = std_bhm::atomic_lim::local::params;

NSA4::params::impl::impl(const local_params& l_params,
			 const ::NSA3::epsilon_params& e_params,
			 const ::NSA3::array_gen_params& ag_params)
    : l_params{l_params}, e_params{e_params}, ag_params{ag_params}
{}



// Get local parameters (pertaining to the atomic limit).
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

using local_params = std_bhm::atomic_lim::local::params;

local_params NSA4::params::get_local_params() const
{
    return pimpl->l_params;
}



// Get epsilon parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

NSA3::epsilon_params NSA4::params::get_epsilon_params() const
{
    return pimpl->e_params;
}



// Get step parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

NSA3::array_gen_params NSA4::params::get_array_gen_params() const
{
    return pimpl->ag_params;
}
