// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Z/type_6.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the class(es) defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block
// /hfb/Z/type_6.cpp'.

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
start_in_atomic_lim/block_by_block/hfb/Z/type_6.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_step_params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"

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
    const auto s_params = ::NSA4::constr_step_params();
    const auto n_block_steps = s_params.get_n_block_steps();
    const auto Ns = 2 * (n_block_steps + 1);
    const auto ds = s_params.get_ds();

    auto n_array = dbl_vec(Ns);
    auto i = -1;
    std::generate(n_array.begin(),
		  n_array.end(),
		  [&]() { i++; return 1.0 + 0.05 * sin(ds * i); });
    
    const auto& Z6 = ::NSA5::type_6(n_array);

    const auto l1 = ::NSA6::to_value<int>();
    const auto l2 = ::NSA6::to_value<int>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    std::cout << "Z6(" << l1 << ", " << l2 << ") = "
	      << Z6.eval(l1, l2) << std::endl;
    
    return 0;
}
