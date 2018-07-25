// /std_bhm/src/ed_1d/quench_0T/H_bhm_mat_rep.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/H_bhm_mat_rep.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/bhm_params.h"
#include "ed_1d/local_params.h"
#include "ed_1d/quench_0T/nn_connectivity_mat_rep.h"
#include "ed_1d/quench_0T/local_hamiltonian_mat_rep.h"



// Calculate the ground state (vector) of the BHM given the model parameters.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::H_bhm_mat_rep_detail;

arma::sp_mat NSA3::H_bhm_mat_rep(const ::NSA2::fock_basis& basis,
				 const ::NSA1::bhm_params& model_params)
{
    const auto J = model_params.get_J();
    const auto l_params = model_params.get_local_params();
    
    const auto H_0 = ::NSA2::local_hamiltonian_mat_rep(basis, l_params);
    const auto nn_connectivity = ::NSA2::nn_connectivity_mat_rep(basis);

    return -J * nn_connectivity + H_0;
}
