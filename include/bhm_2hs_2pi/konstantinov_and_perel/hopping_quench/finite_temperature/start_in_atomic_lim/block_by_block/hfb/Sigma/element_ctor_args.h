// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Sigma
// /element_ctor_args.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_SIGMA_\
ELEMENT_CTOR_ARGS_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_SIGMA_\
ELEMENT_CTOR_ARGS_H

/* Include standard libraries */
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



namespace Y
{
namespace element_detail
{
class element; // forward declaration
}
}

namespace Z
{
class element; // forward declaration
}



namespace Sigma
{
namespace element_ctor_args_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA5 = NSA3::Y::element_detail;
namespace NSA6 = NSA3::Z;

using local_params = std_bhm::atomic_lim::local::params;

class element_ctor_args
{
public:
    element_ctor_args(const NSA5::element& Y_element,
		      const NSA6::element& Z_element,
		      const local_params& l_params);

    const NSA5::element& get_Y_element() const;
    const NSA6::element& get_Z_element() const;
    local_params get_local_params() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of element_ctor_args_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::Sigma::\
element_ctor_args_detail::element_ctor_args;



} // end of Sigma namespace
} // end of hfb namespace
} // end of block_by_block namespace
} // end of start_in_atomic_lim namespace
} // end of finite_temperature namespace
} // end of hopping_quench namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
 
