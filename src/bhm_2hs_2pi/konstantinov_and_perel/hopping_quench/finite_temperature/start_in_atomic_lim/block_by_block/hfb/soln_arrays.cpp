// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/soln_arrays.cpp

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
start_in_atomic_lim/block_by_block/hfb/soln_arrays.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

struct NSA3::soln_arrays::impl
{
    impl(cmplx_vec& y_rho, cmplx_vec& y_K);
    impl(int n_block_steps);

    cmplx_vec y_rho;
    cmplx_vec y_K;
};



// soln_arrays constructor #1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

NSA3::soln_arrays::soln_arrays(cmplx_vec& y_rho, cmplx_vec& y_K)
    : pimpl{ spimpl::make_impl<impl>(y_rho, y_K) }
{}



// soln_arrays constructor #2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

NSA3::soln_arrays::soln_arrays(int n_block_steps)
    : pimpl{ spimpl::make_impl<impl>(n_block_steps) }
{}



// soln_arrays::impl constructor #1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

NSA3::soln_arrays::impl::impl(cmplx_vec& y_rho, cmplx_vec& y_K)
    : y_rho(y_rho), y_K(y_K)
{}



// soln_arrays::impl constructor #2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

NSA3::soln_arrays::impl::impl(int n_block_steps)
    : y_rho( 2 * (n_block_steps + 1) ), y_K( 2 * (n_block_steps + 1) )
{}



// Get y_rho array representation.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

cmplx_vec& NSA3::soln_arrays::get_y_rho() const
{
    return pimpl->y_rho;
}



// Get y_K array representation.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

cmplx_vec& NSA3::soln_arrays::get_y_K() const
{
    return pimpl->y_K;
}
