// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M/element.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <complex>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

struct NSA4::element::impl
{
    impl(const ::NSA5::element& X_element,
	 const ::NSA6::element& Sigma_element);

    const ::NSA5::element& X_element;
    const ::NSA6::element Sigma_element;
};



// element constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

NSA4::element::element(const ::NSA5::element& X_element,
		       const ::NSA6::element& Sigma_element)
    : pimpl{ spimpl::make_impl<impl>(X_element, Sigma_element) }
{}



// element::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

NSA4::element::impl::impl(const ::NSA5::element& X_element,
			  const ::NSA6::element& Sigma_element)
    : X_element{X_element},
      Sigma_element{Sigma_element}
{}



// Evaluate M.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::M;

using cmplx_dbl = std::complex<double>;

cmplx_dbl NSA4::element::eval(int l1, int l2, int l3) const
{
    const auto X = pimpl->X_element.eval(l1, l2, l3);
    const auto Sigma = pimpl->Sigma_element.eval(l2, l3);
    
    return X * Sigma;
}
