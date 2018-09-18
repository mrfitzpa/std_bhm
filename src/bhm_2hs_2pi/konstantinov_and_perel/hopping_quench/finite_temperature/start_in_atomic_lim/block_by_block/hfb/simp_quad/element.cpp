// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/simp_quad
// /element.cpp

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
start_in_atomic_lim/block_by_block/hfb/simp_quad/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/element.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

namespace NSA5 = NSA3::M;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

struct NSA4::element::impl
{
    impl(const ::NSA5::element& M_element, const cmplx_vec& soln_array);

    const ::NSA5::element M_element;
    const cmplx_vec& soln_array;
};



// element constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

namespace NSA5 = NSA3::M;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

NSA4::element::element(const ::NSA5::element& M_element,
		       const cmplx_vec& soln_array)
    : pimpl{ spimpl::make_impl<impl>(M_element, soln_array) }
{}



// element::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

namespace NSA5 = NSA3::M;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

NSA4::element::impl::impl(const ::NSA5::element& M_element,
			  const cmplx_vec& soln_array)
    : M_element{M_element}, soln_array(soln_array)
{}



// Evaluate element
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::simp_quad;

namespace NSA5 = NSA3::M;

using cmplx_dbl = std::complex<double>;

cmplx_dbl NSA4::element::eval(int li, int n_steps, int m1, int m2) const
{
    if (n_steps <= 0) { return 0.0; }

    const auto& M_element = pimpl->M_element;
    const auto& soln_array = pimpl->soln_array;

    auto l = li;
    auto sum = M_element.eval(m1, m2, l) * soln_array[l] / 3.0;
    const auto four_thirds = 4.0 / 3.0;
    const auto two_thirds = 2.0 / 3.0;

    for(decltype(n_steps) j=0; j<n_steps-1; j++)
    {
	l++;
	sum += four_thirds * M_element.eval(m1, m2, l) * soln_array[l];
	l++;
	sum += two_thirds * M_element.eval(m1, m2, l) * soln_array[l];
    }

    l++;
    sum += four_thirds * M_element.eval(m1, m2, l) * soln_array[l];
    l++;
    sum += M_element.eval(m1, m2, l) * soln_array[l] / 3.0;
    
    return sum;
}
