// std_bhm/src/atomic_lim/equilibrium/finite_temperature/local
// /spectral_func.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <cmath>
#include <complex>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "atomic_lim/equilibrium/finite_temperature/local/spectral_func.h"
#include "atomic_lim/equilibrium/local/two_pt_func.h"
#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"
#include "atomic_lim/local/energy.h"
#include "atomic_lim/equilibrium/finite_temperature/local/partition_func.h"



// Partial definition of impl class
namespace NSA1 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using local_params = std_bhm::atomic_lim::local::params;
using cmplx_dbl = std::complex<double>;

struct NSA1::spectral_func::impl
{
    impl(const local_params& l_params);

    const local_params l_params;
    
    const int n0;
    const double E0_n0;
    const double Z0;
    const cmplx_dbl I;

    cmplx_dbl do_eval(double t) const;
};



// spectral_func constructor
namespace NSA1 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using local_params = std_bhm::atomic_lim::local::params;

NSA1::spectral_func::spectral_func(const local_params& l_params)
    : pimpl{ spimpl::make_impl<impl>(l_params) }
{}



// spectral_func::impl constructor
namespace NSA1 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;
namespace NSA2 = std_bhm::atomic_lim::local;
namespace NSA3 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

using local_params = std_bhm::atomic_lim::local::params;
using cmplx_dbl = std::complex<double>;

NSA1::spectral_func::impl::impl(const local_params& l_params)
    : l_params{l_params},
      n0{ ::NSA3::particle_count( l_params.get_mu() ) },
      E0_n0{ ::NSA2::ground_state_energy( l_params.get_mu() ) },
      Z0{ ::NSA1::partition_func(l_params) },
      I{ cmplx_dbl{0, 1} }
{}



// Evaluate spectral function, called by wrapper "eval(...)".
namespace NSA1 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;
namespace NSA2 = std_bhm::atomic_lim::local;

using cmplx_dbl = std::complex<double>;

cmplx_dbl NSA1::spectral_func::do_eval(double t) const
{
    const auto l_params = pimpl->l_params;
    const auto mu = l_params.get_mu();
    const auto beta = l_params.get_beta();
    const auto max_band_index = int{ l_params.get_max_band_index() };

    const auto E0_n0 = pimpl->E0_n0;
    const auto n0 = pimpl->n0;
    const auto temp_1 = beta * (E0_n0 - n0 * mu);

    const auto I_times_t = pimpl->I * t;

    auto sum = cmplx_dbl{0.0, 0.0};

    for(int m=0; m<max_band_index; m++)
    {
	const auto E0_m = ::NSA2::energy(m);
	const auto temp_2 = beta * (E0_m - m * mu);
	const auto exp_term_1 = std::exp(temp_1 - temp_2);

	const auto E0_p_m = ::NSA2::single_particle_excitation_energy(m, mu);
	const auto exp_term_2 = std::exp(-I_times_t * E0_p_m);

	const auto E0_h_m = ::NSA2::single_hole_excitation_energy(m, mu);
	const auto exp_term_3 = std::exp(I_times_t * E0_h_m);

	sum += exp_term_1 * ( double(m+1) * exp_term_2
			      - double(m) * exp_term_3);
    }

    const auto Z0 = pimpl->Z0;
    return sum / Z0;
}
