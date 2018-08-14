// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M/ctor_args.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_M_CTOR_ARGS_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_M_CTOR_ARGS_H

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
namespace base_detail
{
class base; // forward declaration
}
}

namespace Y
{
namespace base_detail
{
class base; // forward declaration
}
}

namespace Z
{
class base; // forward declaration
}



namespace M
{
namespace ctor_args_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = NSA3::X::base_detail;
namespace NSA5 = NSA3::Y::base_detail;
namespace NSA6 = NSA3::Z;

class ctor_args
{
public:
    ctor_args(const NSA4::base& X_base,
	      const NSA5::base& Y_base,
	      const NSA6::base& Z_base);

    const NSA4::base& get_X_base() const;
    const NSA5::base& get_Y_base() const;
    const NSA6::base& get_Z_base() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of ctor_args_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::M::\
ctor_args_detail::ctor_args;



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
 
