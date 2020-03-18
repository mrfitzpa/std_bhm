// std_bhm/include/atomic_lim/equilibrium/finite_temperature/local
// /kinetic_propagator.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ATOMIC_LIM_EQUILIBRIUM_FINITE_TEMPERATURE_LOCAL_\
KINETIC_PROPAGATOR_H
#define STD_BHM_ATOMIC_LIM_EQUILIBRIUM_FINITE_TEMPERATURE_LOCAL_\
KINETIC_PROPAGATOR_H

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



namespace local
{
class params; // forward declaration
}



namespace equilibrium
{
namespace finite_temperature
{
namespace local
{
namespace kinetic_propagator_detail
{

namespace NSA1 = std_bhm::atomic_lim::equilibrium::local;
using local_params = std_bhm::atomic_lim::local::params;
using cmplx_dbl = std::complex<double>;

class kinetic_propagator: public NSA1::two_pt_func
{
public:
    kinetic_propagator(const local_params& l_params);

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;

    virtual cmplx_dbl do_eval(double t) const;
};

} // end of kinetic_propagator_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::atomic_lim::equilibrium::finite_temperature::\
local::kinetic_propagator_detail::kinetic_propagator;



} // end of local namespace
} // end of finite_temperature namespace
} // end of equilibrium namespace
} // end of atomic_lim namespace
} // end of std_bhm namespace


#endif
