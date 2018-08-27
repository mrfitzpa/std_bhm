// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/block
// /builder_set.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_BLOCK_BUILDER_SET_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_BLOCK_BUILDER_SET_H

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



namespace soln_arrays_detail
{
class soln_arrays; // forward declaration
}

namespace k_eqn
{
namespace params_detail
{
class params; // forward declaration
}
}

namespace g
{
namespace set_detail
{
class set; // forward declaration
}
}

namespace M
{
namespace set_detail
{
class set; // forward declaration
}
}

namespace simp_quad
{
namespace set_detail
{
class set; // forward declaration
}
}



namespace block
{
namespace builder_set_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = NSA3::soln_arrays_detail;
namespace NSA5 = NSA3::k_eqn::params_detail;
namespace NSA6 = NSA3::g::set_detail;
namespace NSA7 = NSA3::M::set_detail;
namespace NSA8 = NSA3::simp_quad::set_detail;

using dbl_vec = std::vector<double>;

class builder_set
{
public:
    builder_set(const NSA4::soln_arrays& soln,
		const NSA5::params& k_eqn_params,
		const dbl_vec& n_array);

    int get_n_block_steps() const;
    NSA4::soln_arrays& get_soln_arrays() const;
    const NSA6::set& get_g_set() const;
    const NSA7::set& get_M_set() const;
    const NSA8::set& get_simp_quad_set() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of builder_set_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::block::\
builder_set_detail::builder_set;



} // end of block namespace
} // end of hfb namespace
} // end of block_by_block namespace
} // end of start_in_atomic_lim namespace
} // end of finite_temperature namespace
} // end of hopping_quench namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
 
