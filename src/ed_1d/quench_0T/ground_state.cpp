// /std_bhm/src/ed_1d/quench_0T/ground_state.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */

#include <limits>
#include <iostream>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/ground_state.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/bhm_params.h"
#include "ed_1d/quench_0T/H_bhm_mat_rep.h"



// Calculate the ground state (vector) of the BHM given the model parameters.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::ground_state_detail;

void NSA3::ground_state(arma::dvec& ground_state_vec,
			const ::NSA2::fock_basis& basis,
			const ::NSA1::bhm_params& model_params)
{
    const auto H_bhm = ::NSA2::H_bhm_mat_rep(basis, model_params);
    
    auto eigvals = arma::dvec();
    auto eigvecs = arma::dmat();
    arma::eigs_sym(eigvals, eigvecs, H_bhm, 1, "sa");

    ground_state_vec = eigvecs.col(0);
}

void NSA3::ground_state(double& ground_state_energy,
			const ::NSA2::fock_basis& basis,
			const ::NSA1::bhm_params& model_params)
{
    const auto H_bhm = ::NSA2::H_bhm_mat_rep(basis, model_params);
    
    auto eigvals = arma::dvec();
    auto eigvecs = arma::dmat();
    arma::eigs_sym(eigvals, eigvecs, H_bhm, 1, "sa");

    ground_state_energy = eigvals(0);
}

void NSA3::ground_state(double& ground_state_energy,
			arma::dvec& ground_state_vec,
			const ::NSA2::fock_basis& basis,
			const ::NSA1::bhm_params& model_params)
{
    const auto H_bhm = ::NSA2::H_bhm_mat_rep(basis, model_params);
    
    auto eigvals = arma::dvec();
    auto eigvecs = arma::dmat();
    arma::eigs_sym(eigvals, eigvecs, H_bhm, 1, "sa");

    ground_state_energy = eigvals(0);
    ground_state_vec = eigvecs.col(0);
}
