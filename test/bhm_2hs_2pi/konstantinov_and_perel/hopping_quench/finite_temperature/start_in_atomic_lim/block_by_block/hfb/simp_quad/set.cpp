// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/simp_quad/set.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the class(es) defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block
// /hfb/simp_quad/set.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/simp_quad/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/simp_quad/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set_ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/soln_arrays.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_M_set_ctor_args.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_test_n_array.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/from_std_cin/constr_test_soln_arrays.h"

#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::from_std_cin;
namespace NSA5 = NSA3::M;
namespace NSA6 = NSA3::simp_quad;

namespace NSA7 = std_bhm::parameters::from_std_cin;

int main(int argc, char** argv)
{
    const auto n_array = ::NSA4::constr_test_n_array();
    const auto soln = ::NSA4::constr_test_soln_arrays();
    
    const auto m_set_ctor_args = ::NSA4::constr_M_set_ctor_args(n_array);
    const auto M_set = ::NSA5::set{m_set_ctor_args};

    const auto simp_quad_set = ::NSA6::set(M_set, soln);

    const auto li = ::NSA7::to_value<int>();
    const auto n_steps = ::NSA7::to_value<int>();
    const auto m1 = ::NSA7::to_value<int>();
    const auto m2 = ::NSA7::to_value<int>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    const auto& simp_rho_rho = simp_quad_set.get_rho_rho();
    const auto& simp_rho_K = simp_quad_set.get_rho_K();
    const auto& simp_K_rho = simp_quad_set.get_K_rho();

    std::cout << "simp_rho_rho(" << li << ", " << n_steps << ", " << m1 << ", "
	      << m2 << ") = " << simp_rho_rho.eval(li, n_steps, m1, m2)
	      << std::endl;

    std::cout << "simp_rho_K(" << li << ", " << n_steps << ", " << m1 << ", "
	      << m2 << ") = " << simp_rho_K.eval(li, n_steps, m1, m2)
	      << std::endl;

    std::cout << "simp_K_rho(" << li << ", " << n_steps << ", " << m1 << ", "
	      << m2 << ") = " << simp_K_rho.eval(li, n_steps, m1, m2)
	      << std::endl;
    
    return 0;
}
