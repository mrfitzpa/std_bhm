// std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/zero_temperature
// /self_energy/without_sf_terms/hfb/R12_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/\
self_energy/without_sf_terms/hfb/R12_params.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"



// R12_params constructor
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::zero_temperature;
namespace NSA2 = NSA1::self_energy::without_sf_terms::hfb;
namespace NSA3 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

NSA2::R12_params::R12_params(double mu, const std::vector<double>& k_vector)
    : mu{mu}, k_vector{k_vector}, J{0}, n( ::NSA3::particle_count(mu) )
{}

NSA2::R12_params::R12_params(double mu, const std::vector<double>& k_vector,
			     double J, double n)
    : mu{mu}, k_vector{k_vector}, J{J}, n{n}
{}
