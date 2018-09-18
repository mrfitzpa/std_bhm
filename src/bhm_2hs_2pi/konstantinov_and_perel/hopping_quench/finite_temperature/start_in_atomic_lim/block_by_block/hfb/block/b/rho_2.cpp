// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/block
// /b/rho_2.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/b/rho_2.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/builder_set.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/set.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/simp_quad/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/simp_quad/set.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/soln_arrays.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::b;

namespace NSA6 = NSA3::g;
namespace NSA7 = NSA3::M;
namespace NSA8 = NSA3::simp_quad;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

struct NSA5::rho_2::impl
{
    impl(const ::NSA4::builder_set& block_builder_set);

    const ::NSA6::element& g_rho;
    
    const ::NSA7::element M_rho_rho_1;
    
    const ::NSA8::element simp_quad_rho_rho;

    const cmplx_vec& y_rho;
};



// rho_2 constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::b;

NSA5::rho_2::rho_2(const ::NSA4::builder_set& block_builder_set)
    : pimpl{ spimpl::make_impl<impl>(block_builder_set) }
{}



// builder_set::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::b;

NSA5::rho_2::impl::impl(const ::NSA4::builder_set& block_builder_set)
    : g_rho{ ( block_builder_set.get_g_set() ).get_rho() },
      M_rho_rho_1{ ( block_builder_set.get_M_set() ).get_rho_rho_1() },
      simp_quad_rho_rho{
	  ( block_builder_set.get_simp_quad_set() ).get_rho_rho() },
      y_rho{ ( block_builder_set.get_soln_arrays() ).get_y_rho() }
{}



// Evaluate b-vector.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::b;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

cmplx_vec NSA5::rho_2::do_eval(int m1, int m2) const
{
    const auto& g_rho = pimpl->g_rho;
    const auto& M_rho_rho_1 = pimpl->M_rho_rho_1;
    const auto& simp_quad_rho_rho = pimpl->simp_quad_rho_rho;
    const auto& y_rho = pimpl->y_rho;
    
    auto b_rho_2 = cmplx_vec(1);

    b_rho_2[0] = ( g_rho.eval(2*m1, 2*m2)
		   + simp_quad_rho_rho.eval(0, m1-1, 2*m1, 2*m2)
		   + (1.0 / 3.0) * ( M_rho_rho_1.eval(2*m1, 2*m2, 2*m1-2)
				     * y_rho[2*m1-2] )
		   + (4.0 / 3.0) * ( M_rho_rho_1.eval(2*m1, 2*m2, 2*m1-1)
				     * y_rho[2*m1-1] ) );
    
    return b_rho_2;
}
