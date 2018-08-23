// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/simp_quad/set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <complex>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/simp_quad/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/simp_quad/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/soln_arrays.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

namespace NSA5 = NSA3::M;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

struct NSA4::set::impl
{
    impl(const ::NSA5::set& M_set, const ::NSA3::soln_arrays& soln);

    const ::NSA4::element simp_quad_rho_rho;
    const ::NSA4::element simp_quad_rho_K;
    const ::NSA4::element simp_quad_K_rho;
};



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

namespace NSA5 = NSA3::M;

NSA4::set::set(const ::NSA5::set& M_set, const ::NSA3::soln_arrays& soln)
    : pimpl{ spimpl::make_impl<impl>(M_set, soln) }
{}



// set::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

namespace NSA5 = NSA3::M;

NSA4::set::impl::impl(const ::NSA5::set& M_set, const ::NSA3::soln_arrays& soln)
    : simp_quad_rho_rho{ M_set.get_rho_rho_1(), soln.get_y_rho() },
      simp_quad_rho_K{ M_set.get_rho_K_4(), soln.get_y_K() },
      simp_quad_K_rho{ M_set.get_K_rho_1(), soln.get_y_rho() }
{}



// Get simp_quad_rho_rho.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

NSA4::element NSA4::set::get_rho_rho() const
{
    return pimpl->simp_quad_rho_rho;
}



// Get simp_quad_rho_K.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

NSA4::element NSA4::set::get_rho_K() const
{
    return pimpl->simp_quad_rho_K;
}



// Get simp_quad_K_rho.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

NSA4::element NSA4::set::get_K_rho() const
{
    return pimpl->simp_quad_K_rho;
}
