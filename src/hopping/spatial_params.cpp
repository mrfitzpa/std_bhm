// /std_bhm/src/hopping/spatial_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "hopping/spatial_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::hopping;

struct NSA1::spatial_params::impl
{
    impl(int L, int d);

    const int L;
    const int d;
};



// spatial_params constructor.
namespace NSA1 = std_bhm::hopping;

NSA1::spatial_params::spatial_params(int L, int d)
    : pimpl{ spimpl::make_impl<impl>(L, d) }
{}



// spatial_params::impl constructor.
namespace NSA1 = std_bhm::hopping;

NSA1::spatial_params::impl::impl(int L, int d)
    : L{L}, d{d}
{}



// Get # of sites along any of the crystal axes (they're all the same).
namespace NSA1 = std_bhm::hopping;

int NSA1::spatial_params::get_L() const { return pimpl->L; }



// Get # of spatial dimensions.
namespace NSA1 = std_bhm::hopping;

int NSA1::spatial_params::get_d() const { return pimpl->d; }
