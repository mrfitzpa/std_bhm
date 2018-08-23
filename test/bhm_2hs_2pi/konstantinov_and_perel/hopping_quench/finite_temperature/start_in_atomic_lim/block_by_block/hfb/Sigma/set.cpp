// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Sigma/set.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the class(es) defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block
// /hfb/Sigma/set.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/set_ctor_args.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/\
constr_Sigma_set_ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_test_n_array.h"

#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::from_std_cin;
namespace NSA5 = NSA3::Sigma;

namespace NSA6 = std_bhm::parameters::from_std_cin;

int main(int argc, char** argv)
{
    const auto n_array = ::NSA4::constr_test_n_array();
    
    const auto s_set_ctor_args = ::NSA4::constr_Sigma_set_ctor_args(n_array);
    const auto& Sigma_set = ::NSA5::set(s_set_ctor_args);

    const auto l1 = ::NSA6::to_value<int>();
    const auto l2 = ::NSA6::to_value<int>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    const auto& Sigma_rho_rho_1 = Sigma_set.get_rho_rho_1();
    const auto& Sigma_rho_rho_2 = Sigma_set.get_rho_rho_2();
    const auto& Sigma_rho_rho_3 = Sigma_set.get_rho_rho_3();

    const auto& Sigma_rho_K_4 = Sigma_set.get_rho_K_4();
    const auto& Sigma_rho_K_5 = Sigma_set.get_rho_K_5();
    const auto& Sigma_rho_K_6 = Sigma_set.get_rho_K_6();

    const auto& Sigma_K_rho_1 = Sigma_set.get_K_rho_1();
    const auto& Sigma_K_rho_2 = Sigma_set.get_K_rho_2();
    const auto& Sigma_K_rho_3 = Sigma_set.get_K_rho_3();

    std::cout << "Sigma_rho_rho_1(" << l1 << ", " << l2 << ") = "
	      << Sigma_rho_rho_1.eval(l1, l2) << std::endl;

    std::cout << "Sigma_rho_rho_2(" << l1 << ", " << l2 << ") = "
	      << Sigma_rho_rho_2.eval(l1, l2) << std::endl;

    std::cout << "Sigma_rho_rho_3(" << l1 << ", " << l2 << ") = "
	      << Sigma_rho_rho_3.eval(l1, l2) << std::endl;



    std::cout << "Sigma_rho_K_4(" << l1 << ", " << l2 << ") = "
	      << Sigma_rho_K_4.eval(l1, l2) << std::endl;

    std::cout << "Sigma_rho_K_5(" << l1 << ", " << l2 << ") = "
	      << Sigma_rho_K_5.eval(l1, l2) << std::endl;

    std::cout << "Sigma_rho_K_6(" << l1 << ", " << l2 << ") = "
	      << Sigma_rho_K_6.eval(l1, l2) << std::endl;



    std::cout << "Sigma_K_rho_1(" << l1 << ", " << l2 << ") = "
	      << Sigma_K_rho_1.eval(l1, l2) << std::endl;

    std::cout << "Sigma_K_rho_2(" << l1 << ", " << l2 << ") = "
	      << Sigma_K_rho_2.eval(l1, l2) << std::endl;

    std::cout << "Sigma_K_rho_3(" << l1 << ", " << l2 << ") = "
	      << Sigma_K_rho_3.eval(l1, l2) << std::endl;
    
    return 0;
}
