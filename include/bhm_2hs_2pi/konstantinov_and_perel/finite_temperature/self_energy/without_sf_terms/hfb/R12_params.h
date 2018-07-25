// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/finite_temperature
// /self_energy/without_sf_terms/hfb/R12_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_FINITE_TEMPERATURE_\
SELF_ENERGY_WITHOUT_SF_TERMS_HFB_R12_PARAMS_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_FINITE_TEMPERATURE_\
SELF_ENERGY_WITHOUT_SF_TERMS_HFB_R12_PARAMS_H

/* Include standard libraries */
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{



namespace atomic_lim
{
namespace local
{
class params; // forward declaration
}
}



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

using local_params = std_bhm::atomic_lim::local::params;
using dbl_vec = std::vector<double>;

class R12_params
{
public:
    R12_params(const local_params& l_params, const dbl_vec& k_vec);
    R12_params(const local_params& l_params, const dbl_vec& k_vec,
	       double J, double n);

    local_params get_local_params() const;
    dbl_vec get_k_vector() const;
    double get_J() const;
    double get_n() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of R12_params namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::finite_temperature::\
self_energy::without_sf_terms::hfb::R12_params_detail::R12_params;



} // end of hfb namespace
} // end of without_sf_terms namespace
} // end of self_energy namespace
} // end of finite_temperature namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
