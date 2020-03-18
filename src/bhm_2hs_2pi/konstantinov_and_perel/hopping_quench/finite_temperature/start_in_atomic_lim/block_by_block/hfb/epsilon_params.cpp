// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/epsilon_params.cpp

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
start_in_atomic_lim/block_by_block/hfb/epsilon_params.h"
#include "hopping/quench/linear/quench_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = std_bhm::hopping::quench::linear;
using dbl_vec = std::vector<double>;

struct NSA3::epsilon_params::impl
{
    impl(const ::NSA4::quench_params& q_params, const dbl_vec& k_vec);

    const ::NSA4::quench_params q_params;
    const dbl_vec k_vec;
};



// epsilon_params constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = std_bhm::hopping::quench::linear;
using dbl_vec = std::vector<double>;

NSA3::epsilon_params::epsilon_params(const ::NSA4::quench_params& q_params,
				     const dbl_vec& k_vec)
    : pimpl{ spimpl::make_impl<impl>(q_params, k_vec) }
{}



// epsilon_params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = std_bhm::hopping::quench::linear;
using dbl_vec = std::vector<double>;

NSA3::epsilon_params::impl::impl(const ::NSA4::quench_params& q_params,
				 const dbl_vec& k_vec)
    : q_params{q_params}, k_vec(k_vec)
{}



// Get quench parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = std_bhm::hopping::quench::linear;

NSA4::quench_params NSA3::epsilon_params::get_quench_params() const
{
    return pimpl->q_params;
}



// Get quasi-momentum vector.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using dbl_vec = std::vector<double>;

dbl_vec NSA3::epsilon_params::get_k_vector() const
{
    return pimpl->k_vec;
}
