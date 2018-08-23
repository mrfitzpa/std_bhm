// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M/set_ctor_args.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_M_SET_CTOR_ARGS_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_M_SET_CTOR_ARGS_H

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



namespace X
{
namespace set_params_detail
{
class set_params; // forward declaration
}
}

namespace Sigma
{
namespace set_ctor_args_detail
{
class set_ctor_args; // forward declaration
}
}



namespace M
{
namespace set_ctor_args_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = NSA3::X::set_params_detail;
namespace NSA5 = NSA3::Sigma::set_ctor_args_detail;

class set_ctor_args
{
public:
    set_ctor_args(const NSA4::set_params& x_set_params,
		  const NSA5::set_ctor_args& s_set_ctor_args);

    const NSA4::set_params get_X_set_params() const;
    const NSA5::set_ctor_args get_Sigma_set_ctor_args() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of set_ctor_args_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::M::\
set_ctor_args_detail::set_ctor_args;



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
 
