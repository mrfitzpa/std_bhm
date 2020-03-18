// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/from_std_cin
// /constr_quench_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_FROM_STD_CIN_\
CONSTR_QUENCH_PARAMS_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_FROM_STD_CIN_\
CONSTR_QUENCH_PARAMS_H

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{



namespace hopping
{
namespace quench
{
namespace linear
{
class quench_params; // forward declaration
}
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
namespace from_std_cin
{
namespace constr_quench_params_detail
{

namespace NSA1 = std_bhm::hopping::quench::linear;

NSA1::quench_params constr_quench_params();

} // end of constr_quench_params_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::\
from_std_cin::constr_quench_params_detail::constr_quench_params;



} // end of from_std_cin namespace
} // end of hfb namespace
} // end of block_by_block namespace
} // end of start_in_atomic_lim namespace
} // end of finite_temperature namespace
} // end of hopping_quench namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
 
