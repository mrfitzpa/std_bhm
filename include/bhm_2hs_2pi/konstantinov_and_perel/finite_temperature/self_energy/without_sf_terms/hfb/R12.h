// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/finite_temperature
// /self_energy/without_sf_terms/hfb/R12.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_FINITE_TEMPERATURE_\
SELF_ENERGY_WITHOUT_SF_TERMS_HFB_R12_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_FINITE_TEMPERATURE_\
SELF_ENERGY_WITHOUT_SF_TERMS_HFB_R12_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace bhm_2hs_2pi
{
namespace konstantinov_and_perel
{
namespace finite_temperature
{
namespace self_energy
{
namespace without_sf_terms
{
namespace hfb
{



namespace R12_params_detail
{
class R12_params; // forward declaration
}



namespace R12_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::finite_temperature::self_energy::without_sf_terms::hfb;
namespace NSA3 = NSA2::R12_params_detail;

class R12
{
public:
    R12(const NSA3::R12_params& params);

    void set_hopping_amplitude(double J);
    void set_avg_particle_density(double n);
    
    double eval() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of R12_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::finite_temperature::\
self_energy::without_sf_terms::hfb::R12_detail::R12;



} // end of hfb namespace
} // end of without_sf_terms namespace
} // end of self_energy namespace
} // end of finite_temperature namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
