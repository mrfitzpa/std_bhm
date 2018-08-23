// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Sigma
// /element_ctor_args.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element_ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/element.h"

#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

using local_params = std_bhm::atomic_lim::local::params;

struct NSA4::element_ctor_args::impl
{
    impl(const ::NSA5::element& Y_element,
	 const ::NSA6::element& Z_element,
	 const local_params& l_params);

    const ::NSA5::element& Y_element;
    const ::NSA6::element& Z_element;
    const local_params l_params;
};



// element_ctor_args constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

using local_params = std_bhm::atomic_lim::local::params;

NSA4::element_ctor_args::element_ctor_args(const ::NSA5::element& Y_element,
					   const ::NSA6::element& Z_element,
					   const local_params& l_params)
    : pimpl{ spimpl::make_impl<impl>(Y_element, Z_element, l_params) }
{}



// element_ctor_args::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

using local_params = std_bhm::atomic_lim::local::params;

NSA4::element_ctor_args::impl::impl(const ::NSA5::element& Y_element,
				    const ::NSA6::element& Z_element,
				    const local_params& l_params)
    : Y_element{Y_element}, Z_element{Z_element}, l_params{l_params}
{}



// Get Y_element reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;

const NSA5::element& NSA4::element_ctor_args::get_Y_element() const
{
    return pimpl->Y_element;
}



// Get Z_element reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA6 = NSA3::Z;

const NSA6::element& NSA4::element_ctor_args::get_Z_element() const
{
    return pimpl->Z_element;
}



// Get local parameters (pertaining to the atomic limit).
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

using local_params = std_bhm::atomic_lim::local::params;

local_params NSA4::element_ctor_args::get_local_params() const
{
    return pimpl->l_params;
}
