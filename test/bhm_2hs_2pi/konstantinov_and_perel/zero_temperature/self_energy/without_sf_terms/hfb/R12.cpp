// std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/zero_temperature
// /self_energy/without_sf_terms/hfb/R12.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /zero_temperature/self_energy/without_sf_terms/hfb/R12.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/\
self_energy/without_sf_terms/hfb/R12.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/\
self_energy/without_sf_terms/hfb/R12_params.h"
#include "output/vector_to_string.h"

int main(int argc, char** argv)
{
    namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
    namespace NSA2 = NSA1::zero_temperature;
    namespace NSA3 = std_bhm::output;
    using self_energy_R12 = NSA2::self_energy::without_sf_terms::hfb::R12;
    using self_energy_params 
	= NSA2::self_energy::without_sf_terms::hfb::R12_params;

    std::cout << "The class to be tested below exist at the namespace "
	      << "scope level 'std_bhm::bhm_2hs_2pi::konstantinov_and_perel::"
	      << "zero_temperature::self_energy::without_sf_terms::hfb: \n"
	      << std::endl;

    std::cout << "Testing the class 'R12': \n" 
	      << std::endl;

    auto mu = 0.25;
    auto k_vector = std::vector<double>{0.123, -0.321};
    auto param_set_1 = self_energy_params{mu, k_vector};

    std::cout << "Using parameters:\n"
	      << "mu = " << param_set_1.mu << "\n"
	      << "k-vector = " 
	      << NSA3::vector_1d_to_string(param_set_1.k_vector) << "\n"
	      << "J = " << param_set_1.J << "\n"
	      << "n = " << param_set_1.n << "\n"
	      << std::endl;

    auto Sigma_R12_test_1 = self_energy_R12{param_set_1};

    std::cout << "Checking whether output is correct: \n" 
	      << std::endl;

    std::cout << "Self-energy-R12 = " << Sigma_R12_test_1.eval() << "\n\n\n"
	      << std::endl;



    auto J = 0.03;
    auto n = 1.08;
    auto param_set_2 = self_energy_params{mu, k_vector, J, n};

    std::cout << "Using parameters:\n"
	      << "mu = " << param_set_2.mu << "\n"
	      << "k-vector = " 
	      << NSA3::vector_1d_to_string(param_set_2.k_vector) << "\n"
	      << "J = " << param_set_2.J << "\n"
	      << "n = " << param_set_2.n << "\n"
	      << std::endl;

    auto Sigma_R12_test_2 = self_energy_R12{param_set_2};

    std::cout << "Checking whether output is correct: \n" 
	      << std::endl;

    std::cout << "Self-energy-R12 = " << Sigma_R12_test_2.eval() << "\n\n\n"
	      << std::endl;



    mu = 1.53;
    J = 0.03;
    n = 2.3;
    auto param_set_3 = self_energy_params{mu, k_vector, J, n};

    std::cout << "Using parameters:\n"
	      << "mu = " << param_set_3.mu << "\n"
	      << "k-vector = " 
	      << NSA3::vector_1d_to_string(param_set_3.k_vector) << "\n"
	      << "J = " << param_set_3.J << "\n"
	      << "n = " << param_set_3.n << "\n"
	      << std::endl;

    auto Sigma_R12_test_3 = self_energy_R12{param_set_3};

    std::cout << "Checking whether output is correct: \n" 
	      << std::endl;

    std::cout << "Self-energy-R12 = " << Sigma_R12_test_3.eval() << "\n\n\n"
	      << std::endl;



    J = 0.04;
    n = 2.4;
    Sigma_R12_test_3.set_hopping_amplitude(J);
    Sigma_R12_test_3.set_avg_particle_density(n);

    std::cout << "Using parameters:\n"
	      << "mu = " << param_set_3.mu << "\n"
	      << "k-vector = " 
	      << NSA3::vector_1d_to_string(param_set_3.k_vector) << "\n"
	      << "J = " << J << "\n"
	      << "n = " << n << "\n"
	      << std::endl;

    std::cout << "Checking whether output is correct: \n" 
	      << std::endl;

    std::cout << "Self-energy-R12 = " << Sigma_R12_test_3.eval() << "\n\n\n"
	      << std::endl;

    return 0;
}
