// /std_bhm/src/atomic_lim/local/params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::atomic_lim::local;

struct NSA1::params::impl
{
    impl(double beta, double mu, int max_band_index);

    const double beta;
    const double mu;
    const int max_band_index;
};



// params constructor.
namespace NSA1 = std_bhm::atomic_lim::local;

NSA1::params::params(double beta, double mu, int max_band_index)
    : pimpl{ spimpl::make_impl<impl>(beta, mu, max_band_index) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::atomic_lim::local;

NSA1::params::impl::impl(double beta, double mu, int max_band_index)
    : beta{beta}, mu{mu}, max_band_index{max_band_index}
{}



// Get inverse temperature beta.
namespace NSA1 = std_bhm::atomic_lim::local;

double NSA1::params::get_beta() const { return pimpl->beta; }



// Get chemical potential mu.
namespace NSA1 = std_bhm::atomic_lim::local;

double NSA1::params::get_mu() const { return pimpl->mu; }



// Get max_band_index, which specifies the highest band index to consider
// in calculations of local quantities.
namespace NSA1 = std_bhm::atomic_lim::local;

int NSA1::params::get_max_band_index() const
{
    return pimpl->max_band_index;
}
