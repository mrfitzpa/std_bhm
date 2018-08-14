// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Z/type_2.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the class(es) defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block
// /hfb/Z/type_2.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/type_2.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_array_gen_params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen_params.h"

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
    const auto ag_params = ::NSA4::constr_array_gen_params();
    const auto Ns = ag_params.get_Ns();
    const auto ds = ag_params.get_ds();

    auto n_array = dbl_vec(Ns);
    auto i = -1;
    std::generate(n_array.begin(),
		  n_array.end(),
		  [&]() { i++; return 1.0 + 0.05 * sin(ds * i); });
    
    const auto& Z1 = ::NSA5::type_2(n_array);

    const auto l1 = ::NSA6::to_value<int>();
    const auto l2 = ::NSA6::to_value<int>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    std::cout << "Z1(" << l1 << ", " << l2 << ") = "
	      << Z1.eval(l1, l2) << std::endl;
    
    return 0;
}
