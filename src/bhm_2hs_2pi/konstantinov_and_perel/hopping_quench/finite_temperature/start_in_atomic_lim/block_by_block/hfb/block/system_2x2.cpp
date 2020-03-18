// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/block
// /system_2x2.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>
#include <memory>

#include <iostream>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/system_2x2.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/C/mat.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/b/vec.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::block;

namespace NSA4 = NSA3::C;
namespace NSA5 = NSA3::b;

struct NSA3::system_2x2::impl
{
    impl(const ::NSA4::mat& C_mat, const ::NSA5::vec& b_vec);

    const ::NSA4::mat& C_mat;
    const ::NSA5::vec& b_vec;
};



// system_2x2 constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::block;

namespace NSA4 = NSA3::C;
namespace NSA5 = NSA3::b;

NSA3::system_2x2::system_2x2(const ::NSA4::mat& C_mat, const ::NSA5::vec& b_vec)
    : pimpl{ spimpl::make_impl<impl>(C_mat, b_vec) }
{}



// system_2x2::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::block;

namespace NSA4 = NSA3::C;
namespace NSA5 = NSA3::b;

NSA3::system_2x2::impl::impl(const ::NSA4::mat& C_mat, const ::NSA5::vec& b_vec)
    : C_mat{C_mat}, b_vec{b_vec}
{}



// Solve 2x2 block system.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::block;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

cmplx_vec NSA3::system_2x2::do_solve(int m1, int m2) const
{
    const auto& C_mat = pimpl->C_mat.eval(m1, m2);
    const auto& b_vec = pimpl->b_vec.eval(m1, m2);

    const auto C_11 = C_mat[0];
    const auto C_12 = C_mat[1];
    const auto C_21 = C_mat[2];
    const auto C_22 = C_mat[3];
    
    const auto b_1 = b_vec[0];
    const auto b_2 = b_vec[1];

    auto soln = cmplx_vec(2);
    soln[0] = ( (1.0 - C_22) * b_1 + C_12 * b_2 ) / (1.0 - C_11 - C_22);
    soln[1] = ( (1.0 - C_11) * b_2 + C_21 * b_1 ) / (1.0 - C_11 - C_22);
    
    return soln;
}
