// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M
// /set_ctor_args.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set_ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/set_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/set_ctor_args.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

struct NSA4::set_ctor_args::impl
{
    impl(const ::NSA5::set_params& x_set_params,
	 const ::NSA6::set_ctor_args& s_set_ctor_args);

    const ::NSA5::set_params x_set_params;
    const ::NSA6::set_ctor_args s_set_ctor_args;
};



// set_ctor_args constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

NSA4::set_ctor_args::set_ctor_args(const ::NSA5::set_params& x_set_params,
				   const ::NSA6::set_ctor_args& s_set_ctor_args)
    : pimpl{ spimpl::make_impl<impl>(x_set_params, s_set_ctor_args) }
{}



// set_ctor_args::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

NSA4::set_ctor_args::impl::impl(const ::NSA5::set_params& x_set_params,
				const ::NSA6::set_ctor_args& s_set_ctor_args)
    : x_set_params{x_set_params}, s_set_ctor_args{s_set_ctor_args}
{}



// Get X::set_params.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;

const NSA5::set_params NSA4::set_ctor_args::get_X_set_params() const
{
    return pimpl->x_set_params;
}



// Get Sigma::set_ctor_args.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA6 = NSA3::Sigma;

const NSA6::set_ctor_args NSA4::set_ctor_args::get_Sigma_set_ctor_args() const
{
    return pimpl->s_set_ctor_args;
}
