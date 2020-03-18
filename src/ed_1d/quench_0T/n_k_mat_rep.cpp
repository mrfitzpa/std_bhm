// /std_bhm/src/ed_1d/quench_0T/n_k_mat_rep.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <cmath>
#include <limits>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/n_k_mat_rep.h"
#include "ed_1d/quench_0T/fock_basis.h"



// Calculate matrix representation of the nearest-neighbour connectivity
// operator.
namespace NSA1 = std_bhm::ed_1d::quench_0T;
namespace NSA2 = NSA1::n_k_mat_rep_detail;

arma::sp_mat NSA2::n_k_mat_rep(int k, const ::NSA1::fock_basis& basis)
{
    const auto D = basis.get_hilbert_space_dimension();

    auto locs = arma::umat(2, D);
    auto values = arma::dvec(D);
    
    for(auto col=decltype(D){0}; col<D; col++)
    {
	const auto fock_state = basis.get_fock_state(col);
	auto reflected_state = fock_state;
	std::reverse( reflected_state.begin()+1, reflected_state.end() );

	const auto mat_elem = (fock_state[k] + reflected_state[k]) / 2.0;
	
	values(col) = mat_elem;
	locs(0, col) = col;
	locs(1, col) = col;
    }

    return arma::sp_mat(locs, values, D, D, false, false);
}
