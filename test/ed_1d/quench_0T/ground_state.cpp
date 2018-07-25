// /std_bhm/test/ed_1d/quench_0T/ground_state.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/ed_1d/quench_0T/ground_state.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "ed_1d/quench_0T/ground_state.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/fock_basis_params.h"
#include "ed_1d/bhm_params.h"
#include "ed_1d/local_params.h"
#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::ed_1d;
namespace NSA3 = NSA2::quench_0T;

using int_vec = std::vector<int>;

int main(int argc, char** argv)
{
    const auto total_number_of_particles = ::NSA1::to_value<int>();
    const auto number_of_lattice_sites = ::NSA1::to_value<int>();
    const auto fb_params = ::NSA2::fock_basis_params(total_number_of_particles,
						     number_of_lattice_sites);

    const auto J = ::NSA1::to_value<double>();

    const auto U = ::NSA1::to_value<double>();
    const auto mu = ::NSA1::to_value<double>();
    const auto l_params = ::NSA2::local_params(mu, U);

    const auto model_params = ::NSA2::bhm_params(J, l_params);
    const auto basis = ::NSA3::fock_basis(fb_params);

    auto ground_state_energy = double();
    auto ground_state_vec = arma::dvec();
    ::NSA3::ground_state(ground_state_energy,
			 ground_state_vec,
			 basis,
			 model_params);

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    std::cout << "Ground state vector for the following system parameters:"
	      << "\n  Total # of particles = " << total_number_of_particles
	      << "\n # of lattice sites = " << number_of_lattice_sites
	      << "\n J = " << J
	      << "\n U = " << U
	      << "\n mu = " << mu
	      << "\n" << std::endl;

    std::cout << "\nGround state energy: " << ground_state_energy << std::endl;
    ground_state_vec.raw_print(std::cout, "\nGround state vector:");

    return 0;
}

