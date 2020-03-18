// std_bhm/src/atomic_lim/equilibrium/zero_temperature/static_lim/local
// /retarded_propagator.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "atomic_lim/equilibrium/zero_temperature/static_lim/local/\
retarded_propagator.h"
#include "atomic_lim/equilibrium/zero_temperature/local/energy.h"



// Calculate the static limit of the retarded Green's function at zero
// temperature for a system with chemical potential 'mu'.
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature;
namespace NSA2 = NSA1::local;
namespace NSA3 = NSA1::static_lim::local;

double NSA3::retarded_propagator(double mu)
{
    const auto E0_p = ::NSA2::single_particle_excitation_energy(mu);
    const auto E0_h = ::NSA2::single_hole_excitation_energy(mu);
    return -(1 + mu) / E0_p / E0_h;
}
