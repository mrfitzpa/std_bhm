// std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/y_K_eqn_alg.cpp

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
start_in_atomic_lim/block_by_block/hfb/y_K_eqn_alg.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/builder_set.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/C/K_1.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/C/K_2.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/C/K_3.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/C/K_4.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/b/K_1.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/b/K_2.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/b/K_3.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/b/K_4.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/system_1x1.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/system_2x2.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/soln_arrays.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::C;
namespace NSA6 = NSA4::b;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

struct NSA3::y_K_eqn_alg::impl
{
    impl(const ::NSA4::builder_set& block_builder_set);

    int count;
    const int window_index;
    
    const ::NSA5::K_1 C_K_1;
    const ::NSA5::K_2 C_K_2;
    const ::NSA5::K_3 C_K_3;
    const ::NSA5::K_4 C_K_4;
    
    const ::NSA6::K_1 b_K_1;
    const ::NSA6::K_2 b_K_2;
    const ::NSA6::K_3 b_K_3;
    const ::NSA6::K_4 b_K_4;
    
    const ::NSA4::system_2x2 block_system_1;
    const ::NSA4::system_1x1 block_system_2;
    const ::NSA4::system_2x2 block_system_3;
    const ::NSA4::system_2x2 block_system_4;

    cmplx_vec& y_K;

    void iterate_step();
    void solve_block_systems_1_and_2();
    void solve_block_systems_3_and_4();
};



// y_K_eqn_alg constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = NSA3::block;

NSA3::y_K_eqn_alg::y_K_eqn_alg(const ::NSA4::builder_set& block_builder_set)
    : pimpl{ spimpl::make_unique_impl<impl>(block_builder_set) }
{}



// y_K_eqn_alg::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = NSA3::block;

NSA3::y_K_eqn_alg::impl::impl(const ::NSA4::builder_set& block_builder_set)
    : count{-1},
      window_index{ block_builder_set.get_window_index() },
      C_K_1{block_builder_set},
      C_K_2{block_builder_set},
      C_K_3{block_builder_set},
      C_K_4{block_builder_set},
      b_K_1{block_builder_set},
      b_K_2{block_builder_set},
      b_K_3{block_builder_set},
      b_K_4{block_builder_set},
      block_system_1{C_K_1, b_K_1},
      block_system_2{C_K_2, b_K_2},
      block_system_3{C_K_3, b_K_3},
      block_system_4{C_K_4, b_K_4},
      y_K( ( block_builder_set.get_soln_arrays() ).get_y_K() )
{}



// Step evolve the y_K equation of motion.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

void NSA3::y_K_eqn_alg::step_evolve()
{
    pimpl->count = pimpl->count + 1;
    pimpl->iterate_step();
}



// Re-iterate step solution to the y_K equation of motion based on current
// 'state' variables.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

void NSA3::y_K_eqn_alg::reiterate_step()
{
    pimpl->iterate_step();
}



// Iterate step solution to the y_K equation of motion based on current
// 'state' variables.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

void NSA3::y_K_eqn_alg::impl::iterate_step()
{
    if (count % 2) // if count is odd
	solve_block_systems_3_and_4();
    else // if count is even
	solve_block_systems_1_and_2();
}



// Solve block systems 1 and 2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

void NSA3::y_K_eqn_alg::impl::solve_block_systems_1_and_2()
{
    const auto m2 = count / 2 + 1;
    const auto mL = std::min(window_index, m2);

    for(auto m1=decltype(m2){m2-mL}; m1<m2; m1++)
    {
	const auto soln = block_system_1.solve(m1, m2);
	y_K[2*m1] = soln[0];
	y_K[2*m1+1] = soln[1];
    }

    const auto soln = block_system_2.solve(m2, m2);
    y_K[2*m2] = soln[0];
}



// Solve block systems 3 and 4.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

void NSA3::y_K_eqn_alg::impl::solve_block_systems_3_and_4()
{
    const auto m2 = count / 2 + 1;
    const auto mL = std::min(window_index, m2);

    for(auto m1=decltype(m2){m2-mL}; m1<m2; m1++)
    {
	const auto soln = block_system_1.solve(m1, m2);
	y_K[2*m1] = soln[0];
	y_K[2*m1+1] = soln[1];
    }

    const auto soln = block_system_2.solve(m2, m2);
    y_K[2*m2] = soln[0];
    y_K[2*m2+1] = soln[1];
}
