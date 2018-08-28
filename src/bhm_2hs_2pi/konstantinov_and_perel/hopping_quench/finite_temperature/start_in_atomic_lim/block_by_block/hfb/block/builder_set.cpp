// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/block
// /builder_set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/builder_set.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/soln_arrays.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/g/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/simp_quad/set.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

namespace NSA5 = NSA3::k_eqn;
namespace NSA6 = NSA3::g;
namespace NSA7 = NSA3::M;
namespace NSA8 = NSA3::simp_quad;

using dbl_vec = std::vector<double>;

struct NSA4::builder_set::impl
{
    impl(const ::NSA3::soln_arrays& soln,
	 const ::NSA5::params& k_eqn_params,
	 const dbl_vec& n_array);

    const int window_index;
    ::NSA3::soln_arrays soln;
    const ::NSA6::set g_set;
    const ::NSA7::set M_set;
    const ::NSA8::set simp_quad_set;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

namespace NSA5 = NSA3::k_eqn;

namespace unnamed
{
namespace
{

int get_window_index(const ::NSA5::params& k_eqn_params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// builder_set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

namespace NSA5 = NSA3::k_eqn;

NSA4::builder_set::builder_set(const ::NSA3::soln_arrays& soln,
			       const ::NSA5::params& k_eqn_params,
			       const dbl_vec& n_array)
    : pimpl{ spimpl::make_impl<impl>(soln, k_eqn_params, n_array) }
{}



// builder_set::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

namespace NSA5 = NSA3::k_eqn;

NSA4::builder_set::impl::impl(const ::NSA3::soln_arrays& soln,
			      const ::NSA5::params& k_eqn_params,
			      const dbl_vec& n_array)
    : window_index{ ::unnamed::get_window_index(k_eqn_params) },
      soln{soln},
      g_set{k_eqn_params},
      M_set{k_eqn_params, n_array},
      simp_quad_set{M_set, soln}
{}



// Get window index (m_W) from k-eqn parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

namespace NSA5 = NSA3::k_eqn;

namespace unnamed
{
namespace
{

int get_window_index(const ::NSA5::params& k_eqn_params)
{
    const auto& s_params = k_eqn_params.get_step_params();
    const auto window_index = s_params.get_window_index();

    return window_index;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get window index (m_W).
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

int NSA4::builder_set::get_window_index() const
{
    return pimpl->window_index;
}



// Get solution arrays.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

NSA3::soln_arrays& NSA4::builder_set::get_soln_arrays() const
{
    return pimpl->soln;
}



// Get g-set.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

namespace NSA6 = NSA3::g;

const NSA6::set& NSA4::builder_set::get_g_set() const
{
    return pimpl->g_set;
}



// Get M function set.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

namespace NSA7 = NSA3::M;

const NSA7::set& NSA4::builder_set::get_M_set() const
{
    return pimpl->M_set;
}



// Get simpson quadrature set.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;

namespace NSA8 = NSA3::simp_quad;

const NSA8::set& NSA4::builder_set::get_simp_quad_set() const
{
    return pimpl->simp_quad_set;
}
