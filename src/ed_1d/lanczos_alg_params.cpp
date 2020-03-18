// /std_bhm/ed_1d/lanczos_alg_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "ed_1d/lanczos_alg_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d;

struct NSA1::lanczos_alg_params::impl
{
    impl(int krylov_dimension, double convergence_tolerance);

    const int krylov_dimension;
    const double convergence_tolerance;
};



// lanczos_alg_params constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::lanczos_alg_params::lanczos_alg_params(int krylov_dimension,
					     double convergence_tolerance)
    : pimpl{ spimpl::make_impl<impl>(krylov_dimension, convergence_tolerance) }
{}



// lanczos_alg_params::impl constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::lanczos_alg_params::impl::impl(int krylov_dimension,
				     double convergence_tolerance)
    : krylov_dimension{krylov_dimension},
      convergence_tolerance{convergence_tolerance}
{}



// Get Krylov dimension.
namespace NSA1 = std_bhm::ed_1d;

int NSA1::lanczos_alg_params::get_krylov_dimension() const
{
    return pimpl->krylov_dimension;
}



// Get 'zero-tolerance'.
namespace NSA1 = std_bhm::ed_1d;

double NSA1::lanczos_alg_params::get_convergence_tolerance() const
{
    return pimpl->convergence_tolerance;
}
