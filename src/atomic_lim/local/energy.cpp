// std_bhm/src/atomic_lim/local/energy.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "atomic_lim/local/energy.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"



// Calculate the local energy (in the atomic limit) for some lattice 
// site with 'm' particles.
namespace NSA1 = std_bhm::atomic_lim::local;

double NSA1::energy(int m)
{
    return m * (m - 1) / 2.0;
}



// Calculate the local ground state energy (in the atomic limit) for
// a system with chemical potential 'mu'. 
namespace NSA1 = std_bhm::atomic_lim::local;
namespace NSA2 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

double NSA1::ground_state_energy(double mu)
{
    const auto m = ::NSA2::particle_count(mu);
    return ::NSA1::energy(m);
}



// Calculate the local single-particle excitation energy (in the atomic limit)
// for some lattice site with 'm' particles and chemical potential 'mu'.
namespace NSA1 = std_bhm::atomic_lim::local;

double NSA1::single_particle_excitation_energy(int m, double mu)
{
    return ::NSA1::energy(m+1) - ::NSA1::energy(m) - mu;
}



// Calculate the local single-hole excitation energy (in the atomic limit)
// for some lattice site with 'm' particles and chemical potential 'mu'.
namespace NSA1 = std_bhm::atomic_lim::local;

double NSA1::single_hole_excitation_energy(int m, double mu)
{
    return ::NSA1::energy(m-1) - ::NSA1::energy(m) + mu;
}



// Calculate the local n-particle excitation energy (in the atomic limit)
// for some lattice site with 'm' particles and chemical potential 'mu'.
namespace NSA1 = std_bhm::atomic_lim::local;

double NSA1::n_particle_excitation_energy(int n, int m, double mu)
{
    return ::NSA1::energy(m+n) - ::NSA1::energy(m) - n * mu;
}



// Calculate the local n-hole excitation energy (in the atomic limit)
// for some lattice site with 'm' particles and chemical potential 'mu'.
namespace NSA1 = std_bhm::atomic_lim::local;

double NSA1::n_hole_excitation_energy(int n, int m, double mu)
{
    return ::NSA1::energy(m-n) - ::NSA1::energy(m) + n * mu;
}
