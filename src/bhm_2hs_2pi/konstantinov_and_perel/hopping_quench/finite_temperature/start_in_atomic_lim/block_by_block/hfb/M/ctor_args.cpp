// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M/ctor_args.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/base.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/base.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/base.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Y;
namespace NSA7 = NSA3::Z;

struct NSA4::ctor_args::impl
{
    impl(const ::NSA5::base& X_base,
	 const ::NSA6::base& Y_base,
	 const ::NSA7::base& Z_base);

    const ::NSA5::base& X_base;
    const ::NSA6::base& Y_base;
    const ::NSA7::base& Z_base;
};



// ctor_args constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Y;
namespace NSA7 = NSA3::Z;

NSA4::ctor_args::ctor_args(const ::NSA5::base& X_base,
			   const ::NSA6::base& Y_base,
			   const ::NSA7::base& Z_base)
    : pimpl{ spimpl::make_impl<impl>(X_base, Y_base, Z_base) }
{}



// ctor_args::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Y;
namespace NSA7 = NSA3::Z;

NSA4::ctor_args::impl::impl(const ::NSA5::base& X_base,
			    const ::NSA6::base& Y_base,
			    const ::NSA7::base& Z_base)
    : X_base{X_base}, Y_base{Y_base}, Z_base{Z_base}
{}



// Get X_base reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;

const NSA5::base& NSA4::ctor_args::get_X_base() const
{
    return pimpl->X_base;
}



// Get Y_base reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA6 = NSA3::Y;

const NSA6::base& NSA4::ctor_args::get_Y_base() const
{
    return pimpl->Y_base;
}



// Get Y_base reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA7 = NSA3::Z;

const NSA7::base& NSA4::ctor_args::get_Z_base() const
{
    return pimpl->Z_base;
}
