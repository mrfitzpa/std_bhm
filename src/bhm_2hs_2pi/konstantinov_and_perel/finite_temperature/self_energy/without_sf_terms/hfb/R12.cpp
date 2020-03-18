// std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/finite_temperature
// /self_energy/without_sf_terms/hfb/R12.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <complex>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/\
self_energy/without_sf_terms/hfb/R12.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/\
self_energy/without_sf_terms/hfb/R12_params.h"
#include "atomic_lim/local/params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/u1.h"
#include "atomic_lim/equilibrium/finite_temperature/local/kinetic_propagator.h"
#include "hopping/fourier_transform_of_connectivity.h"
#include "hopping/epsilon.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

struct NSA2::R12::impl
{
    impl(const ::NSA2::R12_params& params);

    const double two_u1; // 2 * u1
    const double n0; // particle density in the atomic limit
    const double neg_F_CM; // -1 * (Fourier transform of connectivity matrix)

    double epsilon; // Fourier transform of the hopping matrix
    double local_term; // 2 * u1 * (n - n0)
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

namespace unnamed
{
namespace
{

// The following functions are used for impl initialization list only
const double calc_two_u1(const ::NSA2::R12_params& params);
const double calc_n0(const ::NSA2::R12_params& params);
const double calc_neg_F_CM(const ::NSA2::R12_params& params);
double calc_epsilon(const ::NSA2::R12_params& params);
double calc_local_term(const ::NSA2::R12_params& params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// R12 constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

NSA2::R12::R12(const ::NSA2::R12_params& params)
    : pimpl{ spimpl::make_impl<impl>(params) }
{}



// R12::impl constructor
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

NSA2::R12::impl::impl(const ::NSA2::R12_params& params)
    : two_u1{ ::unnamed::calc_two_u1(params) },
      n0{ ::unnamed::calc_n0(params) },
      neg_F_CM{ ::unnamed::calc_neg_F_CM(params) },
      epsilon{ ::unnamed::calc_epsilon(params) }, 
      local_term{ ::unnamed::calc_local_term(params) }
{}



// Calculate impl term two_u1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;
namespace NSA3 = NSA1::finite_temperature;

namespace unnamed
{
namespace
{

const double calc_two_u1(const ::NSA2::R12_params& params)
{
    const auto& l_params = params.get_local_params();
    return 2.0 * ::NSA3::u1(l_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate impl term n0.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;
namespace NSA4 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

namespace unnamed
{
namespace
{

const double calc_n0(const ::NSA2::R12_params& params)
{
    const auto& l_params = params.get_local_params();
    const auto G0_K12 = ::NSA4::kinetic_propagator(l_params);
    const auto G0_K12_s0 = G0_K12.eval(0);
    
    return -0.5 * std::imag(G0_K12_s0) - 0.5;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate impl term neg_F_CM.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;
namespace NSA5 = std_bhm::hopping;

const auto& calc_F_CM = NSA5::fourier_transform_of_connectivity;

namespace unnamed
{
namespace
{

const double calc_neg_F_CM(const ::NSA2::R12_params& params)
{
    const auto& k_vec = params.get_k_vector();
    return -::calc_F_CM(k_vec);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate impl term epsilon.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;
namespace NSA5 = std_bhm::hopping;

namespace unnamed
{
namespace
{

double calc_epsilon(const ::NSA2::R12_params& params)
{
    const auto J = params.get_J();
    const auto neg_F_CM = ::unnamed::calc_neg_F_CM(params);
    
    return J * neg_F_CM;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate impl term local_term.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

namespace unnamed
{
namespace
{

double calc_local_term(const ::NSA2::R12_params& params)
{
    const auto n = params.get_n();
    const auto two_u1 = ::unnamed::calc_two_u1(params);
    const auto n0 = ::unnamed::calc_n0(params);
    
    return two_u1 * (n - n0);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Set hopping amplitude. Note that we are not really storing the value
// anywhere, rather we are updating 'impl.epsilon' based on the new value
// for the hopping amplitude.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

void NSA2::R12::set_hopping_amplitude(double J) 
{
    pimpl->epsilon = J * pimpl->neg_F_CM;
}



// Set average particle density. Note that we are not really storing the
// value anywhere, rather we are updating 'impl.local_term' based on the
// new value for the average particle density.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

void NSA2::R12::set_avg_particle_density(double n) 
{
    pimpl->local_term = pimpl->two_u1 * (n - pimpl->n0);
}



// Evaluate self-energy based on current parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;

double NSA2::R12::eval() const 
{
    return pimpl->epsilon + pimpl->local_term;
}
