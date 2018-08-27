// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M/set.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the class(es) defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block
// /hfb/M/set.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_k_eqn_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_test_n_array.h"

#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::from_std_cin;
namespace NSA5 = NSA3::M;

namespace NSA6 = std_bhm::parameters::from_std_cin;

int main(int argc, char** argv)
{
    const auto k_eqn_params = ::NSA4::constr_k_eqn_params();
    const auto n_array = ::NSA4::constr_test_n_array();
    
    const auto& M_set = ::NSA5::set{k_eqn_params, n_array};

    const auto l1 = ::NSA6::to_value<int>();
    const auto l2 = ::NSA6::to_value<int>();
    const auto l3 = ::NSA6::to_value<int>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    const auto& M_rho_rho_1 = M_set.get_rho_rho_1();
    const auto& M_rho_rho_2 = M_set.get_rho_rho_2();
    const auto& M_rho_rho_3 = M_set.get_rho_rho_3();

    const auto& M_rho_K_4 = M_set.get_rho_K_4();
    const auto& M_rho_K_5 = M_set.get_rho_K_5();
    const auto& M_rho_K_6 = M_set.get_rho_K_6();

    const auto& M_K_rho_1 = M_set.get_K_rho_1();
    const auto& M_K_rho_2 = M_set.get_K_rho_2();
    const auto& M_K_rho_3 = M_set.get_K_rho_3();

    std::cout << "M_rho_rho_1(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << M_rho_rho_1.eval(l1, l2, l3) << std::endl;

    std::cout << "M_rho_rho_2(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << M_rho_rho_2.eval(l1, l2, l3) << std::endl;

    std::cout << "M_rho_rho_3(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << M_rho_rho_3.eval(l1, l2, l3) << std::endl;



    std::cout << "M_rho_K_4(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << M_rho_K_4.eval(l1, l2, l3) << std::endl;

    std::cout << "M_rho_K_5(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << M_rho_K_5.eval(l1, l2, l3) << std::endl;

    std::cout << "M_rho_K_6(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << M_rho_K_6.eval(l1, l2, l3) << std::endl;



    std::cout << "M_K_rho_1(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << M_K_rho_1.eval(l1, l2, l3) << std::endl;

    std::cout << "M_K_rho_2(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << M_K_rho_2.eval(l1, l2, l3) << std::endl;

    std::cout << "M_K_rho_3(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << M_K_rho_3.eval(l1, l2, l3) << std::endl;
    
    return 0;
}
