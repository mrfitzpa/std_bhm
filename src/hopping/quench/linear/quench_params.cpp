// /std_bhm/src/hopping/quench/linear/quench_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "hopping/quench/linear/quench_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::hopping::quench::linear;

struct NSA1::quench_params::impl
{
    impl(double ji, double jf, double tc, double tau_Q);

    const double ji;
    const double jf;
    const double tc;
    const double tau_Q;
};



// quench_params constructor.
namespace NSA1 = std_bhm::hopping::quench::linear;

NSA1::quench_params::quench_params(double ji, double jf,
				    double tc, double tau_Q)
    : pimpl{ spimpl::make_impl<impl>(ji, jf, tc, tau_Q) }
{}



// quench_params::impl constructor.
namespace NSA1 = std_bhm::hopping::quench::linear;

NSA1::quench_params::impl::impl(double ji, double jf, 
				double tc, double tau_Q)
    : ji{ji}, jf{jf}, tc{tc}, tau_Q{tau_Q}
{}



// Get initial value of hopping amplitude.
namespace NSA1 = std_bhm::hopping::quench::linear;

double NSA1::quench_params::get_ji() const { return pimpl->ji; }



// Get final value of hopping amplitude.
namespace NSA1 = std_bhm::hopping::quench::linear;

double NSA1::quench_params::get_jf() const { return pimpl->jf; }



// Get "time offset" for quench.
namespace NSA1 = std_bhm::hopping::quench::linear;

double NSA1::quench_params::get_tc() const { return pimpl->tc; }



// Get quench timescale.
namespace NSA1 = std_bhm::hopping::quench::linear;

double NSA1::quench_params::get_tau_Q() const { return pimpl->tau_Q; }
