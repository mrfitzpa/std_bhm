// /std_bhm/ed_1d/local_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "ed_1d/local_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d;

struct NSA1::local_params::impl
{
    impl(double mu, double U);

    const double mu;
    const double U;
};



// local_params constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::local_params::local_params(double mu, double U)
    : pimpl{ spimpl::make_impl<impl>(mu, U) }
{}



// local_params::impl constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::local_params::impl::impl(double mu, double U)
    : mu{mu}, U{U}
{}



// Get chemical potential.
namespace NSA1 = std_bhm::ed_1d;

double NSA1::local_params::get_mu() const
{
    return pimpl->mu;
}



// Get on-site interaction strength.
namespace NSA1 = std_bhm::ed_1d;

double NSA1::local_params::get_U() const
{
    return pimpl->U;
}
