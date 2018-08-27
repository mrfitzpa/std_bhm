// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Sigma/element.cpp

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
start_in_atomic_lim/block_by_block/hfb/Sigma/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/u1.h"

#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

using local_params = std_bhm::atomic_lim::local::params;

struct NSA4::element::impl
{
    impl(const ::NSA5::element& Y_element,
	 const ::NSA6::element& Z_element,
	 const local_params& l_params);

    const ::NSA5::element& Y_element;
    const ::NSA6::element& Z_element;
    const double two_u1;
};



// element constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

using local_params = std_bhm::atomic_lim::local::params;

NSA4::element::element(const ::NSA5::element& Y_element,
		       const ::NSA6::element& Z_element,
		       const local_params& l_params)
    : pimpl{ spimpl::make_impl<impl>(Y_element, Z_element, l_params) }
{}



// element::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;
namespace NSA7 = NSA1::finite_temperature;

using local_params = std_bhm::atomic_lim::local::params;

NSA4::element::impl::impl(const ::NSA5::element& Y_element,
			  const ::NSA6::element& Z_element,
			  const local_params& l_params)
    : Y_element{Y_element},
      Z_element{Z_element},
      two_u1{ 2.0 * ::NSA7::u1(l_params) }
{}



// Evaluate Sigma.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

double NSA4::element::eval(int l1, int l2) const
{
    const auto Y = pimpl->Y_element.eval(l1, l2);
    const auto Z = pimpl->Z_element.eval(l1, l2);
    
    return Y + pimpl->two_u1 * Z;
}
