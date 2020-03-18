// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Z/set.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the class(es) defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block
// /hfb/Z/set.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_test_n_array.h"

#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::from_std_cin;
namespace NSA5 = NSA3::Z;

namespace NSA6 = std_bhm::parameters::from_std_cin;

using dbl_vec = std::vector<double>;

int main(int argc, char** argv)
{
    const auto n_array = ::NSA4::constr_test_n_array();
    const auto& Z_set = ::NSA5::set(n_array);

    const auto l1 = ::NSA6::to_value<int>();
    const auto l2 = ::NSA6::to_value<int>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    const auto& Z1 = Z_set.get_type_1();
    const auto& Z2 = Z_set.get_type_2();
    const auto& Z3 = Z_set.get_type_3();
    const auto& Z4 = Z_set.get_type_4();
    const auto& Z5 = Z_set.get_type_5();
    const auto& Z6 = Z_set.get_type_6();

    std::cout << "Z1(" << l1 << ", " << l2 << ") = "
	      << Z1.eval(l1, l2) << std::endl;

    std::cout << "Z2(" << l1 << ", " << l2 << ") = "
	      << Z2.eval(l1, l2) << std::endl;

    std::cout << "Z3(" << l1 << ", " << l2 << ") = "
	      << Z3.eval(l1, l2) << std::endl;

    std::cout << "Z4(" << l1 << ", " << l2 << ") = "
	      << Z4.eval(l1, l2) << std::endl;

    std::cout << "Z5(" << l1 << ", " << l2 << ") = "
	      << Z5.eval(l1, l2) << std::endl;

    std::cout << "Z6(" << l1 << ", " << l2 << ") = "
	      << Z6.eval(l1, l2) << std::endl;
    
    return 0;
}
