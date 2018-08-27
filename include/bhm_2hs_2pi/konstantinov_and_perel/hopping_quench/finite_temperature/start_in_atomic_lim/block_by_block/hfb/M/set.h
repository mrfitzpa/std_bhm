// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M/set.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_M_SET_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_M_SET_H

/* Include standard libraries */
#include <vector>
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
namespace hopping_quench
{
namespace finite_temperature
{
namespace start_in_atomic_lim
{
namespace block_by_block
{
namespace hfb
{



namespace k_eqn
{
namespace params_detail
{
class params; // forward declaration
}
}



namespace M
{



namespace element_detail
{
class element; // forward declaration
}



namespace set_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::M;

namespace NSA4 = NSA2::hfb::k_eqn::params_detail;
namespace NSA5 = NSA3::element_detail;

using dbl_vec = std::vector<double>;

class set
{
public:
    set(const NSA4::params& k_eqn_params, const dbl_vec& n_array);

    const NSA5::element& get_rho_rho_1() const;
    const NSA5::element& get_rho_rho_2() const;
    const NSA5::element& get_rho_rho_3() const;

    const NSA5::element& get_rho_K_4() const;
    const NSA5::element& get_rho_K_5() const;
    const NSA5::element& get_rho_K_6() const;

    const NSA5::element& get_K_rho_1() const;
    const NSA5::element& get_K_rho_2() const;
    const NSA5::element& get_K_rho_3() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of set_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::M::\
set_detail::set;



} // end of M namespace
} // end of hfb namespace
} // end of block_by_block namespace
} // end of start_in_atomic_lim namespace
} // end of finite_temperature namespace
} // end of hopping_quench namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
 
