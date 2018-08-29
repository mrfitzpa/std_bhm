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
    impl(const ::NSA4::params& k_eqn_params);

    int count;
    
    cmplx_vec y_rho;
    cmplx_vec y_K;

    dbl_vec n_array;

    ::NSA5::builder_set builder_set;

    ::NSA3::y_rho_eqn_alg y_rho_alg;
    ::NSA3::y_K_eqn_alg y_K_alg;

    void initial_guess_to_next_step_n_estimate();
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

using dbl_vec = std::vector<double>;

namespace unnamed
{
namespace
{

int get_max_array_size(const ::NSA4::params& k_eqn_params);
dbl_vec initialize_n_array(const ::NSA4::params& k_eqn_params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// alg constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

NSA4::alg::alg(const ::NSA4::params& k_eqn_params)
    : pimpl{ spimpl::make_unique_impl<impl>(k_eqn_params) }
{}



// k_eqn_alg::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

namespace NSA6 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

NSA4::alg::impl::impl(const ::NSA4::params& k_eqn_params)
    : count{-1},
      y_rho( ::unnamed::get_max_array_size(k_eqn_params) ),
      y_K( ::unnamed::get_max_array_size(k_eqn_params) ),
      n_array( ::unnamed::initialize_n_array(k_eqn_params) ),
      builder_set{::NSA3::soln_arrays{y_rho, y_K}, k_eqn_params, n_array},
      y_rho_alg{builder_set},
      y_K_alg{builder_set}
{}



// Get maximum array size from k-eqn parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

namespace unnamed
{
namespace
{

int get_max_array_size(const ::NSA4::params& k_eqn_params)
{
    const auto& s_params = k_eqn_params.get_step_params();
    const auto window_index = s_params.get_window_index();

    return 2 * (window_index + 1);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Initialize the n-array.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

namespace NSA6 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using dbl_vec = std::vector<double>;
using cmplx_dbl = std::complex<double>;

namespace unnamed
{
namespace
{

dbl_vec initialize_n_array(const ::NSA4::params& k_eqn_params)
{
    const auto Ns = ::unnamed::get_max_array_size(k_eqn_params);

    auto n_array = dbl_vec(Ns);

    const auto& l_params = k_eqn_params.get_local_params();
    const auto G0_K12 = ::NSA6::kinetic_propagator(l_params);
    const auto I = cmplx_dbl(0.0, 1.0);

    n_array[0] = std::real( 0.5 * (I * G0_K12.eval(0.0) - 1.0) );
    n_array[1] = n_array[0];
    n_array[2] = n_array[0];

    return n_array;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Initiate next step in solution to the k-equation.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

void NSA4::alg::step_evolve()
{
    pimpl->count = pimpl->count + 1;
    pimpl->initial_guess_to_next_step_n_estimate();

    pimpl->y_rho_alg.step_evolve();
    pimpl->y_K_alg.step_evolve();
}



// Reiterate step solution to the k-equations based on current 'state' variables
// of the algorithm.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

void NSA4::alg::reiterate_step(double new_n_estimate)
{
    const auto index = pimpl->count + 2;
    pimpl->n_array[index] = new_n_estimate;

    pimpl->y_rho_alg.reiterate_step();
    pimpl->y_K_alg.reiterate_step();
}



// Iterate step solution to the k-equation based on current 'state' variables
// of the algorithm.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::k_eqn;

void NSA4::alg::impl::initial_guess_to_next_step_n_estimate()
{
    if (count == 0) // initial guess already done in constructor in this case
	return;

    const auto index = count + 2;
    n_array[index] = n_array[index-1] + 0.5 * ( 3.0 * n_array[index-1]
						- 4.0 * n_array[index-2]
						+ n_array[index-3] );
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

    return std::real( 0.5 * (I * pimpl->y_K[index] - 1.0) );
}
