// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M
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
start_in_atomic_lim/block_by_block/hfb/M/element_ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

struct NSA4::element_ctor_args::impl
{
    impl(const ::NSA5::element& X_element,
	 const ::NSA6::element& Sigma_element);

    const ::NSA5::element& X_element;
    const ::NSA6::element& Sigma_element;
};



// element_ctor_args constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

NSA4::element_ctor_args::element_ctor_args(const ::NSA5::element& X_element,
					   const ::NSA6::element& Sigma_element)
    : pimpl{ spimpl::make_impl<impl>(X_element, Sigma_element) }
{}



// element_ctor_args::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

NSA4::element_ctor_args::impl::impl(const ::NSA5::element& X_element,
				    const ::NSA6::element& Sigma_element)
    : X_element{X_element}, Sigma_element{Sigma_element}
{}



// Get X_element reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;

const NSA5::element& NSA4::element_ctor_args::get_X_element() const
{
    return pimpl->X_element;
}



// Get Sigma_element reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA6 = NSA3::Sigma;

const NSA6::element& NSA4::element_ctor_args::get_Sigma_element() const
{
    return pimpl->Sigma_element;
}
