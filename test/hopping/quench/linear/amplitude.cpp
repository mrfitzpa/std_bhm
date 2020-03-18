// /std_bhm/test/hopping/quench/linear/amplitude.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/hopping/quench/linear/amplitude.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "hopping/quench/linear/amplitude.h"
#include "hopping/quench/linear/quench_params.h"
#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::hopping::quench::linear;

int main(int argc, char** argv)
{
    const auto ji = ::NSA1::to_value<double>();
    const auto jf = ::NSA1::to_value<double>();
    const auto tc = ::NSA1::to_value<double>();
    const auto tau_Q = ::NSA1::to_value<double>();
    const auto& q_params = ::NSA2::quench_params(ji, jf, tc, tau_Q);
    const auto J = ::NSA2::amplitude(q_params);

    const auto s = ::NSA1::to_value<double>();
    
    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);
    
    std::cout << "J(" << s << ") = " << J.eval(s) << std::endl;
    
    return 0;
}

