// std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb
// /n_array_tracker.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <cmath>
#include <complex>
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/n_array_tracker.h"

#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/finite_temperature/local/kinetic_propagator.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using dbl_vec = std::vector<double>;
using local_params = std_bhm::atomic_lim::local::params;

struct NSA3::n_array_tracker::impl
{
    impl(int n_block_steps, const local_params& l_params, double tol);

    int count;
    
    dbl_vec n_array;
    
    bool convergence_reached;
    double tol;
    int num_of_updates;
};



// n_array_tracker constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using local_params = std_bhm::atomic_lim::local::params;

NSA3::n_array_tracker::n_array_tracker(int n_block_steps,
				       const local_params& l_params,
				       double tol)
    : pimpl{ spimpl::make_unique_impl<impl>(n_block_steps, l_params, tol) }
{}



// n_array_tracker::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using local_params = std_bhm::atomic_lim::local::params;
using cmplx_dbl = std::complex<double>;

NSA3::n_array_tracker::impl::impl(int n_block_steps,
				  const local_params& l_params,
				  double tol)
    : count{-1},
      n_array( 2 * (n_block_steps + 1) ),
      convergence_reached{false},
      tol{tol},
      num_of_updates{0}
{
    const auto G0_K12 = ::NSA4::kinetic_propagator(l_params);
    const auto I = cmplx_dbl(0, 1.0);
    
    n_array[0] = std::real( 0.5 * (I * G0_K12.eval(0.0) - 1.0) );
    n_array[1] = n_array[0];
    n_array[2] = n_array[0];
}



// Use extrapolation to make an initial guess of the next step in the n-array.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

void NSA3::n_array_tracker::guess_next_step_by_extrapolation()
{
    pimpl->convergence_reached = false;
    pimpl->num_of_updates = 0;
    pimpl->count = pimpl->count + 1;

    if (pimpl->count == 0) // guess already done in constructor
	return;

    const auto index = pimpl->count + 2;
    auto& n_array = pimpl->n_array;
    
    n_array[index] = n_array[index-1] + 0.5 * ( 3.0 * n_array[index-1]
						- 4.0 * n_array[index-2]
						+ n_array[index-3] );
}



// Update current step in the n-array.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

void NSA3::n_array_tracker::update_current_step(double new_estimate)
{
    const auto index = pimpl->count + 2;
    const auto last_estimate = pimpl->n_array[index];

    if ( std::abs(last_estimate - new_estimate) < pimpl->tol )
	pimpl->convergence_reached = true;

    pimpl->n_array[index] = new_estimate;
    pimpl->num_of_updates++;
}



// Check if convergence has been reached in our calculation of 'n' for the
// current set of steps in the solution.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

bool NSA3::n_array_tracker::get_convergence_status() const
{
    return pimpl->convergence_reached;
}



// Get number of updates for current step n-estimates.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

int NSA3::n_array_tracker::get_number_of_updates() const
{
    return pimpl->num_of_updates;
}



// Get n array.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using dbl_vec = std::vector<double>;;

const dbl_vec& NSA3::n_array_tracker::get_n_array() const
{
    return pimpl->n_array;
}
