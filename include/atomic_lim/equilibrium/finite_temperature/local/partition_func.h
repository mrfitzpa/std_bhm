// std_bhm/include/atomic_lim/equilibrium/finite_temperature/local
// /partition_func.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ATOMIC_LIM_EQUILIBRIUM_FINITE_TEMPERATURE_LOCAL_PARTITION_FUNC_H
#define STD_BHM_ATOMIC_LIM_EQUILIBRIUM_FINITE_TEMPERATURE_LOCAL_PARTITION_FUNC_H

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
namespace local
{
namespace partition_func_detail
{

using local_params = std_bhm::atomic_lim::local::params;

double partition_func(const local_params& l_params);

} // end of partition_func_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::atomic_lim::equilibrium::finite_temperature::\
local::partition_func_detail::partition_func;



} // end of local namespace
} // end of finite_temperature namespace
} // end of equilibrium namespace
} // end of atomic_lim namespace
} // end of std_bhm namespace


#endif
