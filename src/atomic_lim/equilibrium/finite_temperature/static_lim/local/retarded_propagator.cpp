// std_bhm/src/atomic_lim/equilibrium/finite_temperature/static_lim/local
// /retarded_propagator.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <cmath>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "atomic_lim/equilibrium/finite_temperature/static_lim/local/\
retarded_propagator.h"
#include "atomic_lim/local/params.h"
#include "atomic_lim/local/energy.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"
#include "atomic_lim/equilibrium/finite_temperature/local/partition_func.h"



// Calculate the static limit of the retarded Green's function.
namespace NSA1 = std_bhm::atomic_lim::equilibrium::finite_temperature;
namespace NSA2 = NSA1::local;
namespace NSA3 = NSA1::static_lim::local::retarded_propagator_detail;
namespace NSA4 = std_bhm::atomic_lim::local;
namespace NSA5 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

using local_params = std_bhm::atomic_lim::local::params;

double NSA3::retarded_propagator(const local_params& l_params)
{
    const auto mu = l_params.get_mu();
    const auto beta = l_params.get_beta();
    const auto max_band_index = l_params.get_max_band_index();

    const auto E0_n0 = ::NSA4::ground_state_energy(mu);
    const auto n0 = ::NSA5::particle_count(mu);
    const auto temp_1 = beta * (E0_n0 - n0 * mu);

    auto sum = 0.0;

    for(auto m=decltype(max_band_index){0}; m<max_band_index; m++)
    {
	const auto E0_m = ::NSA4::energy(m);
	const auto temp_2 = beta * (E0_m - m * mu);
	const auto exp_term = std::exp(temp_1 - temp_2);

	const auto E0_p_m = ::NSA4::single_particle_excitation_energy(m, mu);
	const auto E0_h_m = ::NSA4::single_hole_excitation_energy(m, mu);

	sum += exp_term / E0_p_m / E0_h_m;
    }

    const auto Z0 = ::NSA2::partition_func(l_params);
    return -(1 + mu) * sum / Z0;
}
