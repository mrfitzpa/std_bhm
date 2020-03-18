// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/sim/
// alg_1_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <iostream>
#include <string>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/sim/alg_1_params.h"

#include "atomic_lim/local/params.h"
#include "hopping/spatial_params.h"
#include "hopping/quench/linear/quench_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"

#include "parameters/from_std_cin.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA5 = std_bhm::hopping;
namespace NSA6 = NSA5::quench::linear;

using local_params = std_bhm::atomic_lim::local::params;

struct NSA4::alg_1_params::impl
{
    impl();

    const local_params l_params;
    const ::NSA5::spatial_params sp_params;
    const ::NSA6::quench_params q_params;
    const ::NSA3::step_params s_params;
    const double tol;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA5 = std_bhm::hopping;
namespace NSA6 = NSA5::quench::linear;

using local_params = std_bhm::atomic_lim::local::params;

namespace unnamed
{
namespace
{

local_params get_l_params_from_cin();
::NSA5::spatial_params get_sp_params_from_cin();
::NSA6::quench_params get_q_params_from_cin();
::NSA3::step_params get_s_params_from_cin();
double get_tol_from_cin();

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// alg_1_params constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

NSA4::alg_1_params::alg_1_params()
    : pimpl{ spimpl::make_impl<impl>() }
{}



// alg_1_params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

NSA4::alg_1_params::impl::impl()
    : l_params{ ::unnamed::get_l_params_from_cin() },
      sp_params{ ::unnamed::get_sp_params_from_cin() },
      q_params{ ::unnamed::get_q_params_from_cin() },
      s_params{ ::unnamed::get_s_params_from_cin() },
      tol{ ::unnamed::get_tol_from_cin() }
{}



// Get local parameters (pertaining to the atomic limit) from standard input.
namespace NSA7 = std_bhm::parameters::from_std_cin;

using local_params = std_bhm::atomic_lim::local::params;

namespace unnamed
{
namespace
{

local_params get_l_params_from_cin()
{
    const auto beta = ::NSA7::to_value<double>();
    const auto mu = ::NSA7::to_value<double>();
    const auto max_band_index = ::NSA7::to_value<int>();

    return local_params{beta, mu, max_band_index};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get spatial parameters from standard input.
namespace NSA5 = std_bhm::hopping;
namespace NSA7 = std_bhm::parameters::from_std_cin;

namespace unnamed
{
namespace
{

::NSA5::spatial_params get_sp_params_from_cin()
{
    const auto L = ::NSA7::to_value<int>();
    const auto d = ::NSA7::to_value<int>();

    return ::NSA5::spatial_params{L, d};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get quench parameters from standard input.
namespace NSA5 = std_bhm::hopping;
namespace NSA6 = NSA5::quench::linear;
namespace NSA7 = std_bhm::parameters::from_std_cin;

namespace unnamed
{
namespace
{

::NSA6::quench_params get_q_params_from_cin()
{
    const auto ji = 0.0;
    const auto jf = ::NSA7::to_value<double>();
    const auto tc = ::NSA7::to_value<double>();
    const auto tau_Q = ::NSA7::to_value<double>();

    return ::NSA6::quench_params{ji, jf, tc, tau_Q};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get step parameters from standard input.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA7 = std_bhm::parameters::from_std_cin;

namespace unnamed
{
namespace
{

::NSA3::step_params get_s_params_from_cin()
{
    const auto n_block_steps = ::NSA7::to_value<int>();
    const auto ds = ::NSA7::to_value<double>();
    const auto window_index = ::NSA7::to_value<int>();
    
    return ::NSA3::step_params{n_block_steps, ds, window_index};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get convergence tolerance from standard input.
namespace NSA7 = std_bhm::parameters::from_std_cin;

namespace unnamed
{
namespace
{

double get_tol_from_cin()
{
    const auto tol_str = ::NSA7::to_string();
    const auto tol = std::stod(tol_str);
    
    return tol;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get local parameters (pertaining to the atomic limit) from class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

using local_params = std_bhm::atomic_lim::local::params;

local_params NSA4::alg_1_params::get_local_params() const
{
    return pimpl->l_params;
}



// Get spatial parameters from class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA5 = std_bhm::hopping;

NSA5::spatial_params NSA4::alg_1_params::get_spatial_params() const
{
    return pimpl->sp_params;
}



// Get quench parameters from class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA5 = std_bhm::hopping;
namespace NSA6 = NSA5::quench::linear;

NSA6::quench_params NSA4::alg_1_params::get_quench_params() const
{
    return pimpl->q_params;
}



// Get step parameters from class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

NSA3::step_params NSA4::alg_1_params::get_step_params() const
{
    return pimpl->s_params;
}



// Get convergence tolerance from class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

double NSA4::alg_1_params::get_convergence_tolerance() const
{
    return pimpl->tol;
}
