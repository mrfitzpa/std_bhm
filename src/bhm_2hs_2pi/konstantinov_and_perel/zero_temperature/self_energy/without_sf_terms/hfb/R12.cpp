// std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/zero_temperature
// /self_energy/without_sf_terms/hfb/R12.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/\
self_energy/without_sf_terms/hfb/R12.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/\
self_energy/without_sf_terms/hfb/R12_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/u1.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"
#include "hopping/fourier_transform_of_connectivity.h"
#include "hopping/epsilon.h"



// Partial definition of impl class
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::zero_temperature;
namespace NSA2 = NSA1::self_energy::without_sf_terms::hfb;

struct NSA2::R12::impl
{
    impl(const ::NSA2::R12_params& params);

    const double two_u1; // 2 * u1
    const int n0; // particle density in the atomic limit
    const double neg_F_CM; // -1 * (Fourier transform of connectivity matrix)

    double epsilon; // Fourier transform of the hopping matrix
    double local_term; // 2 * u1 * (n - n0)

    double do_eval() const;
};



// R12 constructor
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::zero_temperature;
namespace NSA2 = NSA1::self_energy::without_sf_terms::hfb;

NSA2::R12::R12(const ::NSA2::R12_params& params)
    : pimpl{ spimpl::make_impl<impl>(params) }
{}



// R12::impl constructor
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::zero_temperature;
namespace NSA2 = NSA1::self_energy::without_sf_terms::hfb;
namespace NSA3 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;
namespace NSA4 = std_bhm::hopping;

NSA2::R12::impl::impl(const ::NSA2::R12_params& params)
    : two_u1{ 2.0 * ::NSA1::u1(params.mu) },
    n0{ ::NSA3::particle_count(params.mu) },
    neg_F_CM{ -::NSA4::fourier_transform_of_connectivity(params.k_vector) },
    epsilon{params.J * neg_F_CM}, 
    local_term{ two_u1 * (params.n - n0) }
{}



// Set hopping amplitude. Note that we are not really storing the value
// anywhere, rather we are updating 'impl.epsilon' based on the new value
// for the hopping amplitude.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::zero_temperature;
namespace NSA2 = NSA1::self_energy::without_sf_terms::hfb;

void NSA2::R12::do_set_hopping_amplitude(double J) 
{ pimpl->epsilon = J * pimpl->neg_F_CM; }



// Set average particle density. Note that we are not really storing the
// value anywhere, rather we are updating 'impl.local_term' based on the
// new value for the average particle density.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::zero_temperature;
namespace NSA2 = NSA1::self_energy::without_sf_terms::hfb;

void NSA2::R12::do_set_avg_particle_density(double n) 
{ pimpl->local_term = pimpl->two_u1 * (n - pimpl->n0); }



// Evaluate self-energy based on current parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::zero_temperature;
namespace NSA2 = NSA1::self_energy::without_sf_terms::hfb;

double NSA2::R12::do_eval() const 
{ return pimpl->epsilon + pimpl->local_term; }
