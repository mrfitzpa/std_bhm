// std_bhm/include/atomic_lim/equilibrium/zero_temperature/local/energy.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ATOMIC_LIM_EQUILIBRIUM_ZERO_TEMPERATURE_LOCAL_ENERGY_H
#define STD_BHM_ATOMIC_LIM_EQUILIBRIUM_ZERO_TEMPERATURE_LOCAL_ENERGY_H

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */



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

double single_particle_excitation_energy(double mu);
double single_hole_excitation_energy(double mu);
double n_particle_excitation_energy(int n, double mu);
double n_hole_excitation_energy(int n, double mu);

} // end of local namespace
} // end of zero_temperature namespace
} // end of equilibrium namespace
} // end of atomic_lim namespace
} // end of std_bhm namespace


#endif
