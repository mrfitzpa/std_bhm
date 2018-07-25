// std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/u1.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <cmath>
/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/u1.h"
#include "atomic_lim/local/params.h"
#include "atomic_lim/local/energy.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"
#include "atomic_lim/equilibrium/finite_temperature/static_lim/local/\
retarded_propagator.h"
#include "atomic_lim/equilibrium/finite_temperature/local/partition_func.h"



// Calculate the u1, which is a constant that comes out of the static limit 
// of the u-vertex in the BHM-2HS-2PI theory.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::u1_detail;
namespace NSA3 = std_bhm::atomic_lim;
namespace NSA4 = NSA3::local;
namespace NSA5 = NSA3::equilibrium::finite_temperature::static_lim::local;
namespace NSA6 = NSA3::equilibrium::zero_temperature::local;
namespace NSA7 = NSA3::equilibrium::finite_temperature::local;

using local_params = std_bhm::atomic_lim::local::params;

double NSA2::u1(const local_params& l_params)
{
    const auto mu = l_params.get_mu();
    const auto beta = l_params.get_beta();
    const auto max_band_index = int{ l_params.get_max_band_index() };

    const auto E0_n0 = ::NSA4::ground_state_energy(mu);
    const auto n0 = ::NSA6::particle_count(mu);
    const auto temp_1 = beta * (E0_n0 - n0 * mu);

    auto sum = 0.0;

    for(int m=0; m<max_band_index; m++)
    {
	const auto mP1 = m + 1;
	const auto mP2 = m + 2;
	const auto mM1 = m - 1;
	
	const auto E0_m = ::NSA4::energy(m);
	const auto temp_2 = beta * (E0_m - m * mu);
	const auto exp_term = std::exp(temp_1 - temp_2);

	const auto E0_p_m = ::NSA4::single_particle_excitation_energy(m, mu);
	const auto E0_h_m = ::NSA4::single_hole_excitation_energy(m, mu);
	const auto E0_2p_m = ::NSA4::n_particle_excitation_energy(2, m, mu);
	const auto E0_2h_m = ::NSA4::n_hole_excitation_energy(2, m, mu);	

	sum += exp_term * ( mP1 * mP2 / E0_2p_m / E0_p_m / E0_p_m 
			    + m * mM1 / E0_2h_m / E0_h_m / E0_h_m
			    - mP1 * mP1 / E0_p_m / E0_p_m / E0_p_m 
			    - m * m / E0_h_m / E0_h_m / E0_h_m
			    - m * mP1 / E0_p_m / E0_h_m / E0_h_m 
			    - m * mP1 / E0_p_m / E0_p_m / E0_h_m);
    }
    
    const auto G0_R12_w0 = ::NSA5::retarded_propagator(l_params);
    const auto Z0 = ::NSA7::partition_func(l_params);

    return -2 * sum / Z0 / G0_R12_w0 /G0_R12_w0 / G0_R12_w0 / G0_R12_w0;
}
