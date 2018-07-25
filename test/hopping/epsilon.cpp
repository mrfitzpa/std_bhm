// /std_bhm/test/hopping/epsilon.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/hopping/epsilon.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "hopping/epsilon.h"
#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::hopping;

using dbl_vec = std::vector<double>;

int main(int argc, char** argv)
{
    const auto J = ::NSA1::to_value<double>();
    const auto kx = ::NSA1::to_value<double>();
    const auto ky = ::NSA1::to_value<double>();
    const auto& k_vec = dbl_vec{kx, ky};
    const auto epsilon_result = ::NSA2::epsilon(J, k_vec);
    
    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);
    
    std::cout << "epsilon = " << epsilon_result << std::endl;
    
    return 0;
}

