// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/block
// /b/K_4.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>
#include <memory>
#include <algorithm>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/b/K_4.h"

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

struct NSA5::K_4::impl
{
    impl(const ::NSA4::builder_set& block_builder_set);

    const int window_index;

    const ::NSA6::element& g_K;
    
    const ::NSA7::element& M_rho_K_4;
    const ::NSA7::element& M_rho_K_6;
    const ::NSA7::element& M_K_rho_1;
    const ::NSA7::element& M_K_rho_3;

    const ::NSA8::element& simp_quad_rho_K;
    const ::NSA8::element& simp_quad_K_rho;

    const cmplx_vec& y_rho;
    const cmplx_vec& y_K;

    cmplx_dbl eval_first_component(int m1, int m2) const;
    cmplx_dbl eval_second_component(int m1, int m2) const;
};



// K_4 constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::b;

NSA5::K_4::K_4(const ::NSA4::builder_set& block_builder_set)
    : pimpl{ spimpl::make_impl<impl>(block_builder_set) }
{}



// builder_set::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::b;

NSA5::K_4::impl::impl(const ::NSA4::builder_set& block_builder_set)
    : window_index{ block_builder_set.get_window_index() },
      g_K{ ( block_builder_set.get_g_set() ).get_K() },
      M_rho_K_4{ ( block_builder_set.get_M_set() ).get_rho_K_4() },
      M_rho_K_6{ ( block_builder_set.get_M_set() ).get_rho_K_6() },
      M_K_rho_1{ ( block_builder_set.get_M_set() ).get_K_rho_1() },
      M_K_rho_3{ ( block_builder_set.get_M_set() ).get_K_rho_3() },
      simp_quad_rho_K{
	  ( block_builder_set.get_simp_quad_set() ).get_rho_K() },
      simp_quad_K_rho{
	  ( block_builder_set.get_simp_quad_set() ).get_K_rho() },
      y_rho{ ( block_builder_set.get_soln_arrays() ).get_y_rho() },
      y_K{ ( block_builder_set.get_soln_arrays() ).get_y_K() }
{}



// Evaluate b-vector.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::b;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

cmplx_vec NSA5::K_4::do_eval(int m1, int m2) const
{
    auto b_K_4 = cmplx_vec(2);

    b_K_4[0] = pimpl->eval_first_component(m1, m2);
    b_K_4[1] = pimpl->eval_second_component(m1, m2);
    
    return b_K_4;
}



// Evaluate second component of the b-vector.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::b;

using cmplx_dbl = std::complex<double>;

cmplx_dbl NSA5::K_4::impl::eval_first_component(int m1, int m2) const
{
    const auto mL = std::min(window_index, m2);
    
    return (g_K.eval(2*m1, 2*m2+1)
	    + simp_quad_rho_K.eval(2*(m2-mL), m1-m2+mL-1, 2*m1, 2*m2+1)
	    + (1.0 / 3.0) * ( M_rho_K_4.eval(2*m1, 2*m2+1, 2*m1-2)
			      * y_K[2*m1-2] )
	    + (4.0 / 3.0) * ( M_rho_K_4.eval(2*m1, 2*m2+1, 2*m1-1)
			      * y_K[2*m1-1] )
	    + simp_quad_K_rho.eval(0, mL, 2*m1, 2*m2+1)
	    + (1.0 / 6.0) * ( M_K_rho_1.eval(2*m1, 2*m2+1, 2*mL)
			      * y_rho[2*mL] )
	    + (2.0 / 3.0) * ( M_K_rho_3.eval(2*m1, 2*m2+1, 2*mL)
			      * ( -(1.0 / 8.0) * y_rho[2*mL-1]
				  + (3.0 / 4.0) * y_rho[2*mL]
				  + (3.0 / 8.0) * y_rho[2*mL+1] ) )
	    + (1.0 / 6.0) * ( M_K_rho_1.eval(2*m1, 2*m2+1, 2*mL+1)
			      * y_rho[2*mL+1] ) );
}



// Evaluate second component of the b-vector.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::b;

using cmplx_dbl = std::complex<double>;

cmplx_dbl NSA5::K_4::impl::eval_second_component(int m1, int m2) const
{
    const auto mL = std::min(window_index, m2);
    
    return (g_K.eval(2*m1+1, 2*m2+1)
	    + simp_quad_rho_K.eval(2*(m2-mL), m1-m2+mL-1, 2*m1+1, 2*m2+1)
	    + (1.0 / 3.0) * ( M_rho_K_4.eval(2*m1+1, 2*m2+1, 2*m1-2)
			      * y_K[2*m1-2] )
	    + (4.0 / 3.0) * ( M_rho_K_4.eval(2*m1+1, 2*m2+1, 2*m1-1)
			      * y_K[2*m1-1] )
	    + simp_quad_K_rho.eval(0, mL, 2*m1+1, 2*m2+1)
	    + (1.0 / 6.0) * ( M_K_rho_1.eval(2*m1+1, 2*m2+1, 2*mL)
			      * y_rho[2*mL] )
	    + (2.0 / 3.0) * ( M_K_rho_3.eval(2*m1+1, 2*m2+1, 2*mL)
			      * ( -(1.0 / 8.0) * y_rho[2*mL-1]
				  + (3.0 / 4.0) * y_rho[2*mL]
				  + (3.0 / 8.0) * y_rho[2*mL+1] ) )
	    + (1.0 / 6.0) * ( M_K_rho_1.eval(2*m1+1, 2*m2+1, 2*mL+1)
			      * y_rho[2*mL+1] )
	    - (1.0 / 12.0) * ( M_rho_K_6.eval(2*m1+1, 2*m2+1, 2*m1)
			      * y_K[2*m1-1] ) );
}
