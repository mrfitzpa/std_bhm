// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/g/set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/set_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/element_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/rho.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/K.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen_params.h"

#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

struct NSA4::set::impl
{
    impl(const ::NSA4::set_params& g_set_params);

    const ::NSA4::rho g_rho;
    const ::NSA4::K g_K;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

namespace unnamed
{
namespace
{

const ::NSA4::element_params gen_g_element_params(
                                 const ::NSA4::set_params& g_set_params);

const ::NSA4::rho gen_g_rho(const ::NSA4::set_params& g_set_params);
const ::NSA4::K gen_g_K(const ::NSA4::set_params& g_set_params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

NSA4::set::set(const ::NSA4::set_params& g_set_params)
    : pimpl{ spimpl::make_impl<impl>(g_set_params) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

NSA4::set::impl::impl(const ::NSA4::set_params& g_set_params)
    : g_rho{ ::unnamed::gen_g_rho(g_set_params) },
      g_K{ ::unnamed::gen_g_K(g_set_params) }
{}



// Generate g_element_params.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

namespace unnamed
{
namespace
{

const ::NSA4::element_params gen_g_element_params(
                                 const ::NSA4::set_params& g_set_params)
{
    const auto& l_params = g_set_params.get_local_params();
    const auto& s_params = g_set_params.get_step_params();

    const auto n_block_steps = s_params.get_n_block_steps();
    const auto Ns = 2 * (n_block_steps + 1);
    const auto ds = s_params.get_ds();
    const auto step_offset = 0.0;
    const auto ag_params = ::NSA3::array_gen_params(Ns, ds, step_offset);

    return ::NSA4::element_params(l_params, ag_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate g_rho.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

namespace unnamed
{
namespace
{

const ::NSA4::rho gen_g_rho(const ::NSA4::set_params& g_set_params)
{
    const auto g_element_params = ::unnamed::gen_g_element_params(g_set_params);

    return ::NSA4::rho(g_element_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate g_K.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

namespace unnamed
{
namespace
{

const ::NSA4::K gen_g_K(const ::NSA4::set_params& g_set_params)
{
    const auto g_element_params = ::unnamed::gen_g_element_params(g_set_params);

    return ::NSA4::K(g_element_params);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get g_rho reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

const NSA4::element& NSA4::set::get_rho() const
{
    return pimpl->g_rho;
}



// Get g_K reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::g;

const NSA4::element& NSA4::set::get_K() const
{
    return pimpl->g_K;
}
