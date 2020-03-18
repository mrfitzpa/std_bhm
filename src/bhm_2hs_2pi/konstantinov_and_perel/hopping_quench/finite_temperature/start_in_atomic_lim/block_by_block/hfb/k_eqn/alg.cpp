// std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/k_eqn/alg.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <complex>
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/alg.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/soln_arrays.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/builder_set.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/y_rho_eqn_alg.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/y_K_eqn_alg.h"

#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/finite_temperature/local/kinetic_propagator.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

namespace NSA5 = NSA3::block;

using dbl_vec = std::vector<double>;
using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

struct NSA4::alg::impl
{
    impl(const ::NSA4::params& k_eqn_params, const dbl_vec& n_array);

    int count;
    
    ::NSA3::soln_arrays soln;

    const dbl_vec& n_array;
    dbl_vec n_k_array;

    ::NSA5::builder_set builder_set;

    ::NSA3::y_rho_eqn_alg y_rho_alg;
    ::NSA3::y_K_eqn_alg y_K_alg;
};



// alg constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

NSA4::alg::alg(const ::NSA4::params& k_eqn_params, const dbl_vec& n_array)
    : pimpl{ spimpl::make_unique_impl<impl>(k_eqn_params, n_array) }
{}



// k_eqn_alg::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

namespace NSA6 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

NSA4::alg::impl::impl(const ::NSA4::params& k_eqn_params,
		      const dbl_vec& n_array)
    : count{-1},
      soln{ ( k_eqn_params.get_step_params() ).get_n_block_steps() },
      n_array(n_array),
      n_k_array(n_array),
      builder_set{soln, k_eqn_params, n_array},
      y_rho_alg{builder_set},
      y_K_alg{builder_set}
{}



// Initiate next step in solution to the k-equation.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

using cmplx_dbl = std::complex<double>;

void NSA4::alg::step_evolve()
{
    const auto index = pimpl->count + 2;
    const auto I = cmplx_dbl(0.0, 1.0);

    if (index != 1)
    {
	const auto& y_K = pimpl->soln.get_y_K();
	pimpl->n_k_array[index] = std::real( 0.5 * (I * y_K[index] - 1.0) );
    }

    pimpl->count = pimpl->count + 1;

    pimpl->y_rho_alg.step_evolve();
    pimpl->y_K_alg.step_evolve();
}



// Reiterate step solution to the k-equations based on current 'state' variables
// of the algorithm.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

void NSA4::alg::reiterate_step()
{
    pimpl->y_rho_alg.reiterate_step();
    pimpl->y_K_alg.reiterate_step();
}



// Get current-step estimate for the n_k-array.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

using cmplx_dbl = std::complex<double>;

double NSA4::alg::get_current_step_n_k_estimate() const
{
    const auto index = pimpl->count + 2;
    const auto I = cmplx_dbl(0.0, 1.0);
    const auto& y_K = pimpl->soln.get_y_K();

    return std::real( 0.5 * (I * y_K[index] - 1.0) );
}



// Get n_k array.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

using dbl_vec = std::vector<double>;;

const dbl_vec& NSA4::alg::get_n_k_array() const
{
    const auto index = pimpl->count + 2;
    const auto I = cmplx_dbl(0.0, 1.0);
    
    const auto& y_K = pimpl->soln.get_y_K();
    auto& n_k_array = pimpl->n_k_array;
    
    n_k_array[index] = std::real( 0.5 * (I * y_K[index] - 1.0) );
    
    return n_k_array;
}
