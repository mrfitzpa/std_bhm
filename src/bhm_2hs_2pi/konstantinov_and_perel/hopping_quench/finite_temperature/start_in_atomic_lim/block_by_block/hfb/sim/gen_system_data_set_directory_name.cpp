// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/sim
// /gen_system_data_set_directory_name.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <string>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/sim/gen_system_data_set_directory_name.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/sim/alg_1_params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"

#include "hopping/spatial_params.h"
#include "hopping/quench/linear/quench_params.h"

#include "atomic_lim/local/params.h"

#include "str_ops/to_string_no_trailing_zeros.h"



// Generate name for system data set directory based on main algorithm
// parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::sim;
namespace NSA4 = NSA3::gen_system_data_set_directory_name_detail;

namespace NSA5 = std_bhm::str_ops;

std::string NSA4::gen_system_data_set_directory_name(
                      const ::NSA3::alg_1_params& sim_params)
{
    const auto l_params = sim_params.get_local_params();
    const auto sp_params = sim_params.get_spatial_params();
    const auto q_params = sim_params.get_quench_params();
    const auto s_params = sim_params.get_step_params();
    
    const auto d = sp_params.get_d();
    const auto L = sp_params.get_L();
    
    const auto beta = l_params.get_beta();
    const auto mu = l_params.get_mu();
    
    const auto jf = q_params.get_jf();
    const auto tc = q_params.get_tc();
    const auto tau_Q = q_params.get_tau_Q();
    
    const auto ds = s_params.get_ds();
    const auto Ns = 2 * (s_params.get_n_block_steps() + 1);
    const auto window_index = s_params.get_window_index();

    const auto d_str = ::NSA5::to_string_no_trailing_zeros(d);
    const auto L_str = ::NSA5::to_string_no_trailing_zeros(L);
    
    const auto beta_str = ::NSA5::to_string_no_trailing_zeros(beta);
    const auto mu_str = ::NSA5::to_string_no_trailing_zeros(mu);
    
    const auto jf_str = ::NSA5::to_string_no_trailing_zeros(jf);
    const auto tc_str = ::NSA5::to_string_no_trailing_zeros(tc);
    const auto tau_Q_str = ::NSA5::to_string_no_trailing_zeros(tau_Q);
    
    const auto ds_str = ::NSA5::to_string_no_trailing_zeros(ds);
    const auto Ns_str = ::NSA5::to_string_no_trailing_zeros(Ns);
    const auto window_index_str
	= ::NSA5::to_string_no_trailing_zeros(window_index);

    return ( "d_" + d_str + " L_" + L_str + " beta_" + beta_str
	     + " mu_" + mu_str + " jf_" + jf_str + " tc_" + tc_str
	     + " tauQ_" + tau_Q_str + " ds_" + ds_str + " Ns_" + Ns_str
	     + " mW_" + window_index_str );
}
