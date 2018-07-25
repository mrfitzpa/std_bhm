// /std_bhm/src/ed_1d/quench_0T/total_particle_number_mat_rep.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/total_particle_number_mat_rep.h"
#include "ed_1d/quench_0T/fock_basis.h"



// Generate matrix representation of the interaction part of the BHM
// Hamiltonian where the interaction strength 'U' is set to unity.
namespace NSA1 = std_bhm::ed_1d::quench_0T;
namespace NSA2 = NSA1::total_particle_number_mat_rep_detail;

arma::sp_mat NSA2::total_particle_number_mat_rep
                       (const ::NSA1::fock_basis& basis)
{
    const auto D = basis.get_hilbert_space_dimension();
    const auto N = basis.get_total_number_of_particles();

    auto locs = arma::umat(2, D);
    auto values = arma::dvec(D, arma::fill::ones);
    values *= N;
    
    for(auto col=decltype(D){0}; col<D; col++)
    {
	locs(0, col) = col;
	locs(1, col) = col;
    }

    return arma::sp_mat(locs, values, D, D, false, false);
}
