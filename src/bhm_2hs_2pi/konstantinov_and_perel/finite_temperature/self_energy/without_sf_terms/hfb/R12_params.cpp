// std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/zero_temperature
// /self_energy/without_sf_terms/hfb/R12_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/\
self_energy/without_sf_terms/hfb/R12_params.h"
#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

using local_params = std_bhm::atomic_lim::local::params;
using dbl_vec = std::vector<double>;

struct NSA2::R12_params::impl
{
    impl(const local_params& l_params, const dbl_vec& k_vec);
    impl(const local_params& l_params, const dbl_vec& k_vec,
	 double J, double n);

    const local_params l_params;
    const dbl_vec k_vec;
    const double J;
    const double n;
};


// R12_params constructor
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

using local_params = std_bhm::atomic_lim::local::params;
using dbl_vec = std::vector<double>;

NSA2::R12_params::R12_params(const local_params& l_params, const dbl_vec& k_vec)
    : pimpl{ spimpl::make_impl<impl>(l_params, k_vec) }
{}

NSA2::R12_params::R12_params(const local_params& l_params, const dbl_vec& k_vec,
			     double J, double n)
    : pimpl{ spimpl::make_impl<impl>(l_params, k_vec, J, n) }
{}



// R12_params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;
namespace NSA3 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

using local_params = std_bhm::atomic_lim::local::params;
using dbl_vec = std::vector<double>;

NSA2::R12_params::impl::impl(const local_params& l_params, const dbl_vec& k_vec)
    : l_params{l_params}, k_vec{k_vec},
      J{0}, n( ::NSA3::particle_count( l_params.get_mu() ) )
{}

NSA2::R12_params::impl::impl(const local_params& l_params, const dbl_vec& k_vec,
			     double J, double n)
    : l_params{l_params}, k_vec{k_vec}, J{J}, n{n}
{}



// Get local parameters (pertaining to the atomic limit).
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

using local_params = std_bhm::atomic_lim::local::params;

local_params NSA2::R12_params::get_local_params() const
{
    return pimpl->l_params;
}



// Get quasi-momentum vector.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

using dbl_vec = std::vector<double>;

dbl_vec NSA2::R12_params::get_k_vector() const { return pimpl->k_vec; }



// Get hopping amplitude J.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

double NSA2::R12_params::get_J() const { return pimpl->J; }



// Get average particle density n.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

double NSA2::R12_params::get_n() const { return pimpl->n; }
