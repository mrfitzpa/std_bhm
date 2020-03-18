// std_bhm/include/atomic_lim/equilibrium/zero_temperature/local/spectral_func.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ATOMIC_LIM_EQUILIBRIUM_ZERO_TEMPERATURE_LOCAL_SPECTRAL_FUNC_H
#define STD_BHM_ATOMIC_LIM_EQUILIBRIUM_ZERO_TEMPERATURE_LOCAL_SPECTRAL_FUNC_H

/* Include standard libraries */
#include <complex>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "atomic_lim/equilibrium/local/two_pt_func.h"


namespace std_bhm
{
namespace atomic_lim
{
namespace equilibrium
{
namespace zero_temperature
{
namespace local
{
namespace spectral_func_detail
{

namespace NSA1 = std_bhm::atomic_lim::equilibrium::local;

class spectral_func: public NSA1::two_pt_func
{
public:
    spectral_func(double mu=0.25);

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;

    virtual std::complex<double> do_eval(double t) const;
};

} // end of spectral_func_detail namespace

// lift relevant classes and functions up one namespace
using std_bhm::atomic_lim::equilibrium::zero_temperature::\
local::spectral_func_detail::spectral_func;

} // end of local namespace
} // end of zero_temperature namespace
} // end of equilibrium namespace
} // end of atomic_lim namespace
} // end of std_bhm namespace


#endif
