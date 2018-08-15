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
start_in_atomic_lim/block_by_block/hfb/X/base.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/params.h"
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
    impl(const ::NSA4::set_params& params);

    const ::NSA4::rho_rho X_rho_rho_1;
    const ::NSA4::rho_rho X_rho_rho_2;

    const ::NSA4::rho_K X_rho_K_1;
    const ::NSA4::rho_K X_rho_K_2;

    const ::NSA4::K_rho X_K_rho_1;
    const ::NSA4::K_rho X_K_rho_2;
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

const ::NSA3::array_gen_params gen_array_gen_params(
                                   const ::NSA3::step_params& s_params,
				   double step_offset);

const ::NSA4::rho_rho gen_X_rho_rho_1(const ::NSA4::set_params& params);
const ::NSA4::rho_rho gen_X_rho_rho_2(const ::NSA4::set_params& params);

const ::NSA4::rho_K gen_X_rho_K_1(const ::NSA4::set_params& params);
const ::NSA4::rho_K gen_X_rho_K_2(const ::NSA4::set_params& params);

const ::NSA4::K_rho gen_X_K_rho_1(const ::NSA4::set_params& params);
const ::NSA4::K_rho gen_X_K_rho_2(const ::NSA4::set_params& params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

NSA4::set::set(const ::NSA4::set_params& params)
    : pimpl{ spimpl::make_impl<impl>(params) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

NSA4::set::impl::impl(const ::NSA4::set_params& params)
    : X_rho_rho_1{ ::unnamed::gen_X_rho_rho_1(params) },
      X_rho_rho_2{ ::unnamed::gen_X_rho_rho_2(params) },
      X_rho_K_1{ ::unnamed::gen_X_rho_K_1(params) },
      X_rho_K_2{ ::unnamed::gen_X_rho_K_2(params) },
      X_K_rho_1{ ::unnamed::gen_X_K_rho_1(params) },
      X_K_rho_2{ ::unnamed::gen_X_K_rho_2(params) }
{}



// Generate array_gen_params given step_params and step_offset.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace unnamed
{
namespace
{

const ::NSA3::array_gen_params gen_array_gen_params(
                                   const ::NSA3::step_params& s_params,
				   double step_offset)
{
    const auto n_block_steps = s_params.get_n_block_steps();
    const auto Ns = 2 * (n_block_steps + 1);
    const auto ds = s_params.get_ds();

    return ::NSA3::array_gen_params(Ns, ds, step_offset);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_rho_rho_1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::rho_rho gen_X_rho_rho_1(const ::NSA4::set_params& params)
{
    const auto& l_params = params.get_local_params();
    const auto& s_params = params.get_step_params();

    const auto step_offset = 0.0;
    const auto ag_params = ::unnamed::gen_array_gen_params(s_params,
							   step_offset);

    const auto x_params = ::NSA4::params(l_params, ag_params);

    return ::NSA4::rho_rho(x_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_rho_rho_2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::rho_rho gen_X_rho_rho_2(const ::NSA4::set_params& params)
{
    const auto& l_params = params.get_local_params();
    const auto& s_params = params.get_step_params();

    const auto step_offset = 0.5;
    const auto ag_params = ::unnamed::gen_array_gen_params(s_params,
							   step_offset);

    const auto x_params = ::NSA4::params(l_params, ag_params);

    return ::NSA4::rho_rho(x_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_rho_K_1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::rho_K gen_X_rho_K_1(const ::NSA4::set_params& params)
{
    const auto& l_params = params.get_local_params();
    const auto& s_params = params.get_step_params();

    const auto step_offset = 0.0;
    const auto ag_params = ::unnamed::gen_array_gen_params(s_params,
							   step_offset);

    const auto x_params = ::NSA4::params(l_params, ag_params);

    return ::NSA4::rho_K(x_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_rho_K_2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::rho_K gen_X_rho_K_2(const ::NSA4::set_params& params)
{
    const auto& l_params = params.get_local_params();
    const auto& s_params = params.get_step_params();

    const auto step_offset = -0.5;
    const auto ag_params = ::unnamed::gen_array_gen_params(s_params,
							   step_offset);

    const auto x_params = ::NSA4::params(l_params, ag_params);

    return ::NSA4::rho_K(x_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_K_rho_1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::K_rho gen_X_K_rho_1(const ::NSA4::set_params& params)
{
    const auto& l_params = params.get_local_params();
    const auto& s_params = params.get_step_params();

    const auto step_offset = 0.0;
    const auto ag_params = ::unnamed::gen_array_gen_params(s_params,
							   step_offset);

    const auto x_params = ::NSA4::params(l_params, ag_params);

    return ::NSA4::K_rho(x_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate X_K_rho_2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

namespace unnamed
{
namespace
{

const ::NSA4::K_rho gen_X_K_rho_2(const ::NSA4::set_params& params)
{
    const auto& l_params = params.get_local_params();
    const auto& s_params = params.get_step_params();

    const auto step_offset = 0.5;
    const auto ag_params = ::unnamed::gen_array_gen_params(s_params,
							   step_offset);

    const auto x_params = ::NSA4::params(l_params, ag_params);

    return ::NSA4::K_rho(x_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get X_rho_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::base& NSA4::set::get_rho_rho_1() const
{
    return pimpl->X_rho_rho_1;
}



// Get X_rho_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::base& NSA4::set::get_rho_rho_2() const
{
    return pimpl->X_rho_rho_2;
}



// Get X_rho_K_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::base& NSA4::set::get_rho_K_1() const
{
    return pimpl->X_rho_K_1;
}



// Get X_rho_K_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::base& NSA4::set::get_rho_K_2() const
{
    return pimpl->X_rho_K_2;
}



// Get X_K_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::base& NSA4::set::get_K_rho_1() const
{
    return pimpl->X_K_rho_1;
}



// Get X_K_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::X;

const NSA4::base& NSA4::set::get_K_rho_2() const
{
    return pimpl->X_K_rho_2;
}
