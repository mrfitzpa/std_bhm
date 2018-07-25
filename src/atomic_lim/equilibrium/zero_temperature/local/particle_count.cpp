// std_bhm/src/atomic_lim/equilibrium/zero_temperature/local/particle_count.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <cmath>

/* Non-standard third-party libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"



// Calculate the local # of particles in the atomic limit at 
// zero temperature.
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

int NSA1::particle_count(double mu)
{
    return (mu < 0) ? 0 : std::ceil(mu);
}
