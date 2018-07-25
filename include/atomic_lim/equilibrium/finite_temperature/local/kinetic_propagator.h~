// std_bhm/include/atomic_lim/equilibrium/zero_temperature
// /local/kinetic_propagator.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ATOMIC_LIM_EQUILIBRIUM_ZERO_TEMPERATURE_\
LOCAL_KINETIC_PROPAGATOR_H
#define STD_BHM_ATOMIC_LIM_EQUILIBRIUM_ZERO_TEMPERATURE_\
LOCAL_KINETIC_PROPAGATOR_H

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
namespace kinetic_propagator_detail
{

namespace NS1 = std_bhm::atomic_lim::equilibrium::local;

class kinetic_propagator: public NS1::two_pt_func
{
public:
    kinetic_propagator(double mu);

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;

    virtual std::complex<double> do_eval(double t) const;
};

} // end of kinetic_propagator_detail namespace

// lift relevant classes and functions up one namespace
using std_bhm::atomic_lim::equilibrium::zero_temperature::\
local::kinetic_propagator_detail::kinetic_propagator;

} // end of local namespace
} // end of zero_temperature namespace
} // end of equilibrium namespace
} // end of atomic_lim namespace
} // end of std_bhm namespace


#endif
