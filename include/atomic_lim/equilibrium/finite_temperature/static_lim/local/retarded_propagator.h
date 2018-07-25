// std_bhm/include/atomic_lim/equilibrium/finite_temperature/static_lim/local
// /retarded_propagator.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ATOMIC_LIM_EQUILIBRIUM_FINITE_TEMPERATURE_STATIC_LIM_\
LOCAL_RETARDED_PROPAGATOR_H
#define STD_BHM_ATOMIC_LIM_EQUILIBRIUM_FINITE_TEMPERATURE_STATIC_LIM_\
LOCAL_RETARDED_PROPAGATOR_H

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */



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
namespace static_lim
{
namespace local
{
namespace retarded_propagator_detail
{

using local_params = std_bhm::atomic_lim::local::params;

double retarded_propagator(const local_params& l_params);

} // end of retarded_propagator_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::atomic_lim::equilibrium::finite_temperature::static_lim::local::\
retarded_propagator_detail::retarded_propagator;



} // end of local namespace
} // end of static_lim namespace
} // end of finite_temperature namespace
} // end of equilibrium namespace
} // end of atomic_lim namespace
} // end of std_bhm namespace


#endif
