// /std_bhm/test/ed_1d/quench_0T/n_k.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the classes defined in the 
// .cpp file 'std_bhm/test/ed_1d/quench_0T/n_k.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "ed_1d/quench_0T/n_k.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/fock_basis_params.h"
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

    const auto basis = ::NSA3::fock_basis(fb_params);
    const auto n_k = ::NSA3::n_k(basis);

    const auto D = basis.get_hilbert_space_dimension();
    const auto M = basis.get_number_of_lattice_sites();
    
    const auto seed = ::NSA1::to_value<double>();
    arma::arma_rng::set_seed(seed);
    auto state_vec = arma::cx_dvec(D, arma::fill::randu);
    state_vec = state_vec / arma::norm(state_vec);

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);
    
    state_vec.raw_print(std::cout, "State vector:");
    std::cout << '\n' << std::endl;

    auto N = 0.0;
    
    for(auto k=decltype(M){0}; k<M; k++)
    {
	const auto avg_n_k = n_k.expectation_value(k, state_vec);
	std::cout << "k=" << k << ", <n_k>=" << avg_n_k << std::endl;
	N += avg_n_k;
    }

    std::cout << "\n\nTotal # of particles = " << N << std::endl;
    
    return 0;
}

