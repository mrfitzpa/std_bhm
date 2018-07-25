// /std_bhm/src/ed_1d/step_evolve_mat_rep.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <complex>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/step_evolve_mat_rep.h"
#include "ed_1d/lanczos_alg_params.h"
#include "lanczos/restart/explicitly/full_orthogonalization.h"




// Calculate the sparse matrix representation of the step-evolution operator.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::step_evolve_mat_rep_detail;
namespace NSA3 = std_bhm::lanczos::restart::explicitly;

using cmplx_dbl = std::complex<double>;

arma::cx_mat NSA2::step_evolve_mat_rep(
                       const arma::sp_cx_mat& Ohm,
		       const arma::cx_dvec& current_state,
		       const ::NSA1::lanczos_alg_params& la_params)
{
    auto d_K = la_params.get_krylov_dimension();
    const auto tol = la_params.get_convergence_tolerance();

    auto eigvals = arma::dvec();
    auto eigvecs = arma::cx_mat();

    ::NSA3::full_orthogonalization(Ohm, current_state,
				   d_K, eigvals, eigvecs, tol);

    const auto I = cmplx_dbl(0.0, 1.0);
    d_K = eigvecs.n_cols;
    auto exp_term = arma::sp_cx_mat(d_K, d_K);
    exp_term.diag() = arma::exp(-I * eigvals);

    return eigvecs * ( exp_term * eigvecs.t() );
}



// Calculate the dense matrix representation of the step-evolution operator.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::step_evolve_mat_rep_detail;

using cmplx_dbl = std::complex<double>;

arma::cx_mat NSA2::step_evolve_mat_rep(const arma::cx_mat& Ohm,
				       const arma::cx_dvec& current_state)
{
    auto eigvals = arma::dvec();
    auto eigvecs = arma::cx_mat();

    ::arma::eig_sym(eigvals, eigvecs, Ohm);
    
    const auto I = cmplx_dbl(0.0, 1.0);
    const auto D = Ohm.n_cols;
    auto exp_term = arma::sp_cx_mat(D, D);
    exp_term.diag() = arma::exp(-I * eigvals);

    return eigvecs * ( exp_term * eigvecs.t() );
}
