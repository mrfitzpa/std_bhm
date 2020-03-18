// std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/u1.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /zero_temperature/u1.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <iostream>

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/u1.h"

int main(int argc, char** argv)
{
    namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
    namespace NSA2 = NSA1::zero_temperature;

    std::cout << "Testing the function "
	      << "'std_bhm::bhm_2hs_2pi::konstantinov_and_perel::"
	      << "zero_temperature::u1(...)': \n" 
	      << std::endl;

    std::cout << "u1(-0.4) = " << NSA2::u1(-0.4) << std::endl;
    std::cout << "u1(0.25) = " << NSA2::u1(0.25) << std::endl;
    std::cout << "u1(1.53) = " << NSA2::u1(1.53) << std::endl;
    std::cout << "u1(2.11) = " << NSA2::u1(2.11) << std::endl;
    std::cout << "u1(3.97) = " << NSA2::u1(3.97) << std::endl;

    return 0;
}
