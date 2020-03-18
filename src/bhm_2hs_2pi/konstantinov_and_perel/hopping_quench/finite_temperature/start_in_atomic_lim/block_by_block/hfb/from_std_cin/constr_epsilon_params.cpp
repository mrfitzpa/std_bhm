// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/from_std_cin
// /constr_epsilon_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_epsilon_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_quench_params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/epsilon_params.h"

#include "hopping/quench/linear/quench_params.h"

#include "parameters/from_std_cin.h"
#include "k_map/k_ints_to_k_vec.h"

#include "output/vector_to_string.h"



// Construct a 'epsilon_params' object by reading values from std::cin.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::from_std_cin;
namespace NSA5 = NSA4::constr_epsilon_params_detail;

namespace NSA6 = std_bhm::parameters::from_std_cin;
namespace NSA7 = std_bhm::k_map;

namespace NSA8 = std_bhm::output;

NSA3::epsilon_params NSA5::constr_epsilon_params()
{
    const auto q_params = ::NSA4::constr_quench_params();
    
    const auto L = ::NSA6::to_value<int>();
    const auto k_ints = ::NSA6::to_vector<int>();
    const auto k_vec = ::NSA7::k_ints_to_k_vec(k_ints, L);

    std::cout << "k-vec = " << ::NSA8::vector_1d_to_string(k_vec) << std::endl;

    return ::NSA3::epsilon_params{q_params, k_vec};
}
