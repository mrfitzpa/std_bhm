// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/X/set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/set_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/rho_rho.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/rho_K.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/K_rho.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen_params.h"

#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

struct NSA4::set::impl
{
    impl(const ::NSA4::set_params& x_set_params);

    const ::NSA4::rho_rho X_rho_rho_A;
    const ::NSA4::rho_rho X_rho_rho_B;

    const ::NSA4::rho_K X_rho_K_A;
    const ::NSA4::rho_K X_rho_K_B;

    const ::NSA4::K_rho X_K_rho_A;
    const ::NSA4::K_rho X_K_rho_B;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::element_params gen_x_element_params(
                                 const ::NSA4::set_params& x_set_params,
				 double step_offset);

const ::NSA4::rho_rho gen_X_rho_rho_A(const ::NSA4::set_params& x_set_params);
const ::NSA4::rho_rho gen_X_rho_rho_B(const ::NSA4::set_params& x_set_params);

const ::NSA4::rho_K gen_X_rho_K_A(const ::NSA4::set_params& x_set_params);
const ::NSA4::rho_K gen_X_rho_K_B(const ::NSA4::set_params& x_set_params);

const ::NSA4::K_rho gen_X_K_rho_A(const ::NSA4::set_params& x_set_params);
const ::NSA4::K_rho gen_X_K_rho_B(const ::NSA4::set_params& x_set_params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

NSA4::set::set(const ::NSA4::set_params& x_set_params)
    : pimpl{ spimpl::make_impl<impl>(x_set_params) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

NSA4::set::impl::impl(const ::NSA4::set_params& x_set_params)
    : X_rho_rho_A{ ::unnamed::gen_X_rho_rho_A(x_set_params) },
      X_rho_rho_B{ ::unnamed::gen_X_rho_rho_B(x_set_params) },
      X_rho_K_A{ ::unnamed::gen_X_rho_K_A(x_set_params) },
      X_rho_K_B{ ::unnamed::gen_X_rho_K_B(x_set_params) },
      X_K_rho_A{ ::unnamed::gen_X_K_rho_A(x_set_params) },
      X_K_rho_B{ ::unnamed::gen_X_K_rho_B(x_set_params) }
{}



// Generate X::params.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace unnamed
{
namespace
{

const ::NSA4::element_params gen_x_element_params(
                                 const ::NSA4::set_params& x_set_params,
				 double step_offset)
{
    const auto& l_params = x_set_params.get_local_params();
    const auto& s_params = x_set_params.get_step_params();

    const auto n_block_steps = s_params.get_n_block_steps();
    const auto Ns = 2 * (n_block_steps + 1);
    const auto ds = s_params.get_ds();

    const auto ag_params = ::NSA3::array_gen_params(Ns, ds, step_offset);
    
    return ::NSA4::element_params(l_params, ag_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_rho_rho_A.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::rho_rho gen_X_rho_rho_A(const ::NSA4::set_params& x_set_params)
{
    const auto step_offset = 0.0;
    const auto x_element_params = ::unnamed::gen_x_element_params(x_set_params,
								  step_offset);

    return ::NSA4::rho_rho(x_element_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_rho_rho_B.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::rho_rho gen_X_rho_rho_B(const ::NSA4::set_params& x_set_params)
{
    const auto step_offset = 0.5;
    const auto x_element_params = ::unnamed::gen_x_element_params(x_set_params,
								  step_offset);

    return ::NSA4::rho_rho(x_element_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_rho_K_A.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::rho_K gen_X_rho_K_A(const ::NSA4::set_params& x_set_params)
{
    const auto step_offset = 0.0;
    const auto x_element_params = ::unnamed::gen_x_element_params(x_set_params,
								  step_offset);

    return ::NSA4::rho_K(x_element_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_rho_K_B.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::rho_K gen_X_rho_K_B(const ::NSA4::set_params& x_set_params)
{
    const auto step_offset = -0.5;
    const auto x_element_params = ::unnamed::gen_x_element_params(x_set_params,
								  step_offset);

    return ::NSA4::rho_K(x_element_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_K_rho_A.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::K_rho gen_X_K_rho_A(const ::NSA4::set_params& x_set_params)
{
    const auto step_offset = 0.0;
    const auto x_element_params = ::unnamed::gen_x_element_params(x_set_params,
								  step_offset);

    return ::NSA4::K_rho(x_element_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_K_rho_B.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::K_rho gen_X_K_rho_B(const ::NSA4::set_params& x_set_params)
{
    const auto step_offset = 0.5;
    const auto x_element_params = ::unnamed::gen_x_element_params(x_set_params,
								  step_offset);

    return ::NSA4::K_rho(x_element_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get X_rho_rho_A reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::element& NSA4::set::get_rho_rho_A() const
{
    return pimpl->X_rho_rho_A;
}



// Get X_rho_rho_B reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::element& NSA4::set::get_rho_rho_B() const
{
    return pimpl->X_rho_rho_B;
}



// Get X_rho_K_A reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::element& NSA4::set::get_rho_K_A() const
{
    return pimpl->X_rho_K_A;
}



// Get X_rho_K_B reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::element& NSA4::set::get_rho_K_B() const
{
    return pimpl->X_rho_K_B;
}



// Get X_K_rho_A reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::element& NSA4::set::get_K_rho_A() const
{
    return pimpl->X_K_rho_A;
}



// Get X_K_rho_B reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::element& NSA4::set::get_K_rho_B() const
{
    return pimpl->X_K_rho_B;
}
