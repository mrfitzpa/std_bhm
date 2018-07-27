// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Y.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_Y_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_Y_H

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



namespace array_gen
{
namespace Y_params_detail
{
class Y_params; // forward declaration
}
}



namespace Y_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::array_gen::Y_params_detail;

class Y
{
public:
    Y(const NSA3::Y_params& y_params);
    virtual ~Y();

    double eval(int l1, int l2) const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;

    virtual int calc_Y_array_index(int l1, int l2) const = 0;
};

} // end of Y_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::\
Y_detail::Y;



} // end of hfb namespace
} // end of block_by_block namespace
} // end of start_in_atomic_lim namespace
} // end of finite_temperature namespace
} // end of hopping_quench namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
 
