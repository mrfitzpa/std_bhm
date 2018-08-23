// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Sigma
// /set_ctor_args.cpp

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
start_in_atomic_lim/block_by_block/hfb/Sigma/set_ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/set_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;

using dbl_vec = std::vector<double>;

struct NSA4::set_ctor_args::impl
{
    impl(const ::NSA5::set_params& Y_set_params,
	 const dbl_vec& n_array);

    const ::NSA5::set_params Y_set_params;
    const dbl_vec& n_array;
};



// set_ctor_args constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;

using dbl_vec = std::vector<double>;

NSA4::set_ctor_args::set_ctor_args(const ::NSA5::set_params& Y_set_params,
				   const dbl_vec& n_array)
    : pimpl{ spimpl::make_impl<impl>(Y_set_params, n_array) }
{}



// set_ctor_args::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;

using dbl_vec = std::vector<double>;

NSA4::set_ctor_args::impl::impl(const ::NSA5::set_params& Y_set_params,
				const dbl_vec& n_array)
    : Y_set_params{Y_set_params}, n_array(n_array)
{}



// Get Y::set_params.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;

const NSA5::set_params NSA4::set_ctor_args::get_Y_set_params() const
{
    return pimpl->Y_set_params;
}



// Get n-array.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

using dbl_vec = std::vector<double>;

const dbl_vec& NSA4::set_ctor_args::get_n_array() const
{
    return pimpl->n_array;
}
