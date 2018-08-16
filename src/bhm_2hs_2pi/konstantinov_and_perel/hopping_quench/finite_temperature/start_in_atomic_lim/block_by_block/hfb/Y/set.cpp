// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Y/set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/set_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/base.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/rho_rho.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/rho_K.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/K_rho.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/epsilon_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen_params.h"

#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

struct NSA4::set::impl
{
    impl(const ::NSA4::set_params& y_set_params);

    const ::NSA4::rho_rho Y_rho_rho_A;
    const ::NSA4::rho_rho Y_rho_rho_B;

    const ::NSA4::rho_K Y_rho_K_A;
    const ::NSA4::rho_K Y_rho_K_B;

    const ::NSA4::K_rho Y_K_rho_A;
    const ::NSA4::K_rho Y_K_rho_B;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

namespace unnamed
{
namespace
{

const ::NSA4::params gen_y_params(const ::NSA4::set_params& y_set_params,
				  double step_offset);

const ::NSA4::rho_rho gen_Y_rho_rho_A(const ::NSA4::set_params& y_set_params);
const ::NSA4::rho_rho gen_Y_rho_rho_B(const ::NSA4::set_params& y_set_params);

const ::NSA4::rho_K gen_Y_rho_K_A(const ::NSA4::set_params& y_set_params);
const ::NSA4::rho_K gen_Y_rho_K_B(const ::NSA4::set_params& y_set_params);

const ::NSA4::K_rho gen_Y_K_rho_A(const ::NSA4::set_params& y_set_params);
const ::NSA4::K_rho gen_Y_K_rho_B(const ::NSA4::set_params& y_set_params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

NSA4::set::set(const ::NSA4::set_params& y_set_params)
    : pimpl{ spimpl::make_impl<impl>(y_set_params) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

NSA4::set::impl::impl(const ::NSA4::set_params& y_set_params)
    : Y_rho_rho_A{ ::unnamed::gen_Y_rho_rho_A(y_set_params) },
      Y_rho_rho_B{ ::unnamed::gen_Y_rho_rho_B(y_set_params) },
      Y_rho_K_A{ ::unnamed::gen_Y_rho_K_A(y_set_params) },
      Y_rho_K_B{ ::unnamed::gen_Y_rho_K_B(y_set_params) },
      Y_K_rho_A{ ::unnamed::gen_Y_K_rho_A(y_set_params) },
      Y_K_rho_B{ ::unnamed::gen_Y_K_rho_B(y_set_params) }
{}



// Generate Y::params.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace unnamed
{
namespace
{

const ::NSA4::params gen_y_params(const ::NSA4::set_params& y_set_params,
				  double step_offset)
{
    const auto& l_params = y_set_params.get_local_params();
    const auto& e_params = y_set_params.get_epsilon_params();
    const auto& s_params = y_set_params.get_step_params();

    const auto n_block_steps = s_params.get_n_block_steps();
    const auto Ns = 2 * (n_block_steps + 1);
    const auto ds = s_params.get_ds();

    const auto ag_params = ::NSA3::array_gen_params(Ns, ds, step_offset);
    
    return ::NSA4::params(l_params, e_params, ag_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Y_rho_rho_A.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

namespace unnamed
{
namespace
{

const ::NSA4::rho_rho gen_Y_rho_rho_A(const ::NSA4::set_params& y_set_params)
{
    const auto step_offset = 0.0;
    const auto y_params = ::unnamed::gen_y_params(y_set_params, step_offset);

    return ::NSA4::rho_rho(y_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Y_rho_rho_B.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

namespace unnamed
{
namespace
{

const ::NSA4::rho_rho gen_Y_rho_rho_B(const ::NSA4::set_params& y_set_params)
{
    const auto step_offset = -0.5;
    const auto y_params = ::unnamed::gen_y_params(y_set_params, step_offset);

    return ::NSA4::rho_rho(y_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Y_rho_K_A.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

namespace unnamed
{
namespace
{

const ::NSA4::rho_K gen_Y_rho_K_A(const ::NSA4::set_params& y_set_params)
{
    const auto step_offset = 0.0;
    const auto y_params = ::unnamed::gen_y_params(y_set_params, step_offset);
    
    return ::NSA4::rho_K(y_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Y_rho_K_B.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

namespace unnamed
{
namespace
{

const ::NSA4::rho_K gen_Y_rho_K_B(const ::NSA4::set_params& y_set_params)
{
    const auto step_offset = 0.5;
    const auto y_params = ::unnamed::gen_y_params(y_set_params, step_offset);
    
    return ::NSA4::rho_K(y_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Y_K_rho_A.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

namespace unnamed
{
namespace
{

const ::NSA4::K_rho gen_Y_K_rho_A(const ::NSA4::set_params& y_set_params)
{
    const auto step_offset = 0.0;
    const auto y_params = ::unnamed::gen_y_params(y_set_params, step_offset);
    
    return ::NSA4::K_rho(y_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Y_K_rho_B.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

namespace unnamed
{
namespace
{

const ::NSA4::K_rho gen_Y_K_rho_B(const ::NSA4::set_params& y_set_params)
{
    const auto step_offset = -0.5;
    const auto y_params = ::unnamed::gen_y_params(y_set_params, step_offset);

    return ::NSA4::K_rho(y_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get Y_rho_rho_A reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

const NSA4::base& NSA4::set::get_rho_rho_A() const
{
    return pimpl->Y_rho_rho_A;
}



// Get Y_rho_rho_B reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

const NSA4::base& NSA4::set::get_rho_rho_B() const
{
    return pimpl->Y_rho_rho_B;
}



// Get Y_rho_K_A reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

const NSA4::base& NSA4::set::get_rho_K_A() const
{
    return pimpl->Y_rho_K_A;
}



// Get Y_rho_K_B reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

const NSA4::base& NSA4::set::get_rho_K_B() const
{
    return pimpl->Y_rho_K_B;
}



// Get Y_K_rho_A reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

const NSA4::base& NSA4::set::get_K_rho_A() const
{
    return pimpl->Y_K_rho_A;
}



// Get Y_K_rho_B reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Y;

const NSA4::base& NSA4::set::get_K_rho_B() const
{
    return pimpl->Y_K_rho_B;
}
