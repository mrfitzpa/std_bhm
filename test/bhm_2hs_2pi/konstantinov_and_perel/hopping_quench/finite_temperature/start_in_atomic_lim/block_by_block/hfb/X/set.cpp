// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/X/set.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the class(es) defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block
// /hfb/X/set.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/set_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_X_set_params.h"

#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::from_std_cin;
namespace NSA5 = NSA3::X;

namespace NSA6 = std_bhm::parameters::from_std_cin;

int main(int argc, char** argv)
{
    const auto x_set_params = ::NSA4::constr_X_set_params();
    const auto& X_set = ::NSA5::set(x_set_params);

    const auto l1 = ::NSA6::to_value<int>();
    const auto l2 = ::NSA6::to_value<int>();
    const auto l3 = ::NSA6::to_value<int>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    const auto& X_rho_rho_A = X_set.get_rho_rho_A();
    const auto& X_rho_rho_B = X_set.get_rho_rho_B();

    const auto& X_rho_K_A = X_set.get_rho_K_A();
    const auto& X_rho_K_B = X_set.get_rho_K_B();

    const auto& X_K_rho_A = X_set.get_K_rho_A();
    const auto& X_K_rho_B = X_set.get_K_rho_B();

    std::cout << "X_rho_rho_A(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << X_rho_rho_A.eval(l1, l2, l3) << std::endl;

    std::cout << "X_rho_rho_B(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << X_rho_rho_B.eval(l1, l2, l3) << std::endl;


    std::cout << "X_rho_K_A(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << X_rho_K_A.eval(l1, l2, l3) << std::endl;

    std::cout << "X_rho_K_B(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << X_rho_K_B.eval(l1, l2, l3) << std::endl;


    std::cout << "X_K_rho_A(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << X_K_rho_A.eval(l1, l2, l3) << std::endl;

    std::cout << "X_K_rho_B(" << l1 << ", " << l2 << ", " << l3 << ") = "
	      << X_K_rho_B.eval(l1, l2, l3) << std::endl;
    
    return 0;
}
