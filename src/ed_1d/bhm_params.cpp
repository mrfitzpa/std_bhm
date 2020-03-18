// /std_bhm/src/ed_1d/bhm_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "ed_1d/bhm_params.h"
#include "ed_1d/local_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d;

struct NSA1::bhm_params::impl
{
    impl(double J, const ::NSA1::local_params& l_params);

    const double J; // hopping amplitude
    const ::NSA1::local_params l_params; // mu and U
};



// bhm_params constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::bhm_params::bhm_params(double J, const ::NSA1::local_params& l_params)
    : pimpl{ spimpl::make_impl<impl>(J, l_params) }
{}



// bhm_params::impl constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::bhm_params::impl::impl(double J, const ::NSA1::local_params& l_params)
    : J{J}, l_params{l_params}
{}



// Get hopping amplitude.
namespace NSA1 = std_bhm::ed_1d;

double NSA1::bhm_params::get_J() const
{
    return pimpl->J;
}



// Get local parameters.
namespace NSA1 = std_bhm::ed_1d;

NSA1::local_params NSA1::bhm_params::get_local_params() const
{
    return pimpl->l_params;
}
