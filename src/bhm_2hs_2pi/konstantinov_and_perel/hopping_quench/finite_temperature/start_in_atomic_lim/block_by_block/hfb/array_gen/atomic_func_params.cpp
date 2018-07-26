// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/array_gen
// /atomic_func_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen/atomic_func_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen/step_params.h"
#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::array_gen;

using local_params = std_bhm::atomic_lim::local::params;

struct NSA3::atomic_func_params::impl
{
    impl(const local_params& l_params,
	 const NSA3::step_params& s_params);

    const local_params l_params;
    const NSA3::step_params s_params;
};



// atomic_func_params constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::array_gen;

using local_params = std_bhm::atomic_lim::local::params;

NSA3::atomic_func_params::atomic_func_params
(const local_params& l_params, const ::NSA3::step_params& s_params)
    : pimpl{ spimpl::make_impl<impl>(l_params, s_params) }
{}



// atomic_func_params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::array_gen;

using local_params = std_bhm::atomic_lim::local::params;

NSA3::atomic_func_params::impl::impl(const local_params& l_params,
				     const ::NSA3::step_params& s_params)
    : l_params{l_params}, s_params{s_params}
{}



// Get local parameters (pertaining to the atomic limit).
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::array_gen;

using local_params = std_bhm::atomic_lim::local::params;

local_params NSA3::atomic_func_params::get_local_params() const
{
    return pimpl->l_params;
}



// Get step parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::array_gen;

NSA3::step_params NSA3::atomic_func_params::get_step_params() const
{
    return pimpl->s_params;
}
