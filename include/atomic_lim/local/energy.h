// std_bhm/include/atomic_lim/local/energy.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ATOMIC_LIM_LOCAL_ENERGY_H
#define STD_BHM_ATOMIC_LIM_LOCAL_ENERGY_H

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace atomic_lim
{
namespace local
{

double energy(int m);
double ground_state_energy(double mu);
double single_particle_excitation_energy(int m, double mu);
double single_hole_excitation_energy(int m, double mu);
double n_particle_excitation_energy(int n, int m, double mu);
double n_hole_excitation_energy(int n, int m,  double mu);

} // end of local namespace
} // end of atomic_lim namespace
} // end of std_bhm namespace


#endif
