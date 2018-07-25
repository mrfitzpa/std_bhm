// /std_bhm/src/lanczos/full_orthogonalization.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <complex>
#include <limits>
#include <cmath>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "lanczos/full_orthogonalization.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace unnamed
{
namespace
{

void update_T(int j, double alpha_j, double beta_jM1, arma::mat& T);

void check_convergence(double beta_j,
		       const arma::mat& S,
		       double tol,
		       arma::uvec& sorted_eigpair_indices,
		       int& n_converged_eigpairs);

void orthogonalize_vec(arma::cx_dvec& r,
		       const arma::cx_mat& Q);
void orthogonalize_vec(arma::cx_dvec& r,
		       const arma::cx_mat& Q,
		       const arma::cx_mat& Chi);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Apply the Lanczos algorithm with full orthogonalization to calculate
// a maximum of 'p' eigen-pairs of the matrix A. 'q_0' is the starting vector
// and 'tol' is the convergence tolerance.
namespace NSA1 = std_bhm::lanczos::full_orthogonalization_detail;

void NSA1::full_orthogonalization(const arma::sp_cx_mat& A,
				  const arma::cx_dvec& x,
				  int p,
				  arma::dvec& eigvals,
				  arma::cx_mat& eigvecs,
    				  double tol)
{    
    auto beta_jM1 = 1.0;
    auto Q = arma::cx_mat();
    auto q_j = arma::cx_dvec( arma::normalise(x) );
    auto q_jM1 = arma::cx_dvec(arma::size(x), arma::fill::zeros);

    auto T = arma::mat();
    auto theta = arma::dvec();
    auto S = arma::mat();
    auto n_converged_eigpairs = int();
    auto sorted_eigpair_indices = arma::uvec();

    const auto j_max = A.n_rows;
    for(auto j=decltype(j_max){0}; j<j_max; j++)
    {
	Q.insert_cols(j, q_j);
	auto r = arma::cx_dvec(A * q_j - beta_jM1 * q_jM1);
	const auto alpha_j = std::real( arma::cdot(q_j, r) );
	r -= alpha_j * q_j;
	::unnamed::orthogonalize_vec(r, Q);
	const auto beta_j = double( arma::norm(r) );

	::unnamed::update_T(j, alpha_j, beta_jM1, T);
	
	arma::eig_sym(theta, S, T);

	::unnamed::check_convergence(beta_j,
				     S,
				     tol,
				     sorted_eigpair_indices,
				     n_converged_eigpairs);

	if (n_converged_eigpairs >= p)
	{
	    n_converged_eigpairs = p;
	    break;
	}

	const auto epsilon = std::numeric_limits<double>::epsilon();
	if ( beta_j < epsilon * 10 ) { break; }
	
	q_j = r / beta_j;
	beta_jM1 = beta_j;
    }
    
    eigvals.set_size(n_converged_eigpairs);
    eigvecs.set_size(A.n_rows, n_converged_eigpairs);
    for(auto k=decltype(n_converged_eigpairs){0}; k<n_converged_eigpairs; k++)
    {
	const auto i = sorted_eigpair_indices(k);
	eigvals(k) = theta(i);
	eigvecs.col(k) = Q * S.col(i);
    }
}



// Apply the Lanczos algorithm with full orthogonalization to calculate
// a single converged eigen-pair of the matrix 'A' along with the next best
// approximation to another eigen-pair of 'A'. 'q_0' is the starting vector
// and 'tol' is the convergence tolerance. 'Chi' is the subspace spanned
// by locked in converged Ritz vectors. Note that two eigenpairs are returned
// (stored in eigvals and eigvecs) where the first pair is the converged pair.
namespace NSA1 = std_bhm::lanczos::full_orthogonalization_detail;

void NSA1::full_orthogonalization(const arma::sp_cx_mat& A,
				  const arma::cx_mat& Chi,
				  const arma::cx_dvec& x,
				  arma::dvec& eigvals,
				  arma::cx_mat& eigvecs,
				  arma::dvec& error_bounds,
    				  double tol)
{
    auto beta_j = double();
    auto beta_jM1 = 1.0;
    auto Q = arma::cx_mat();
    auto q_j = arma::cx_dvec( arma::normalise(x) );
    auto q_jM1 = arma::cx_dvec(arma::size(x), arma::fill::zeros);

    auto T = arma::mat();
    auto theta = arma::dvec();
    auto S = arma::mat();
    auto n_converged_eigpairs = int();
    auto sorted_eigpair_indices = arma::uvec();
    auto n_eigpairs_to_return = 0;

    const auto j_max = A.n_rows;
    for(auto j=decltype(j_max){0}; j<j_max; j++)
    {
	Q.insert_cols(j, q_j);
	auto r = arma::cx_dvec(A * q_j - beta_jM1 * q_jM1);
	const auto alpha_j = std::real( arma::cdot(q_j, r) );
	r -= alpha_j * q_j;
	::unnamed::orthogonalize_vec(r, Q, Chi);
	beta_j = double( arma::norm(r) );

	::unnamed::update_T(j, alpha_j, beta_jM1, T);
	
	arma::eig_sym(theta, S, T);

	::unnamed::check_convergence(beta_j,
				     S,
				     tol,
				     sorted_eigpair_indices,
				     n_converged_eigpairs);

	if (n_converged_eigpairs >= 1 && j > 0)
	{
	    n_eigpairs_to_return = 2;
	    break;
	}

	const auto epsilon = std::numeric_limits<double>::epsilon();
	if ( beta_j < epsilon * 10.0 )
	{
	    n_eigpairs_to_return = 1;
	    break;
	}
	
	q_j = r / beta_j;
	beta_jM1 = beta_j;
    }

    eigvals.set_size(n_eigpairs_to_return);
    eigvecs.set_size(A.n_rows, n_eigpairs_to_return);
    error_bounds.set_size(n_eigpairs_to_return);
    for(auto k=decltype(n_eigpairs_to_return){0}; k<n_eigpairs_to_return; k++)
    {
	const auto i = sorted_eigpair_indices(k);
	const auto j = S.n_rows - 1;
	eigvals(k) = theta(i);
	eigvecs.col(k) = Q * S.col(i);
	error_bounds(k) = beta_j * std::fabs( S(j, i) );
    }
}



// Update the T-matrix.
namespace unnamed
{
namespace
{

void update_T(int j, double alpha_j, double beta_jM1, arma::mat& T)
{
    T.resize(j+1, j+1);
    
    T(j, j) = alpha_j;
    
    if (j != 0)
    {
	T(j-1, j) = beta_jM1;
	T(j, j-1) = beta_jM1;
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Check for converged eigpairs; return respective indices.
namespace unnamed
{
namespace
{

void check_convergence(double beta_j,
		       const arma::mat& S,
		       double tol,
		       arma::uvec& sorted_eigpair_indices,
		       int& n_converged_eigpairs)
{
    const auto j = S.n_rows - 1;
    const auto error_bounds = arma::drowvec( beta_j * arma::abs( S.row(j) ) );
    sorted_eigpair_indices = arma::uvec( arma::sort_index(error_bounds) );
    
    for(auto k=decltype(j){0}; k<=j; k++)
    {
	const auto i = sorted_eigpair_indices(k);
	if (error_bounds(i) < tol)
	{
	    n_converged_eigpairs = (j + 1) - k;
	    break;
	}
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Orthonormalize vector 'q_jP1' with respect to the orthonormal basis 'Q'.
namespace unnamed
{
namespace
{

void orthogonalize_vec(arma::cx_dvec& r, const arma::cx_mat& Q)
{
    r -= Q * (Q.t() * r); // Full reorthogonalization
    r -= Q * (Q.t() * r); // Do it twice to ensure orthgonality
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Orthonormalize vector 'q_jP1' with respect to the orthonormal basis 'Q'
// and the subspace 'Chi' which is spanned by the locked-in converged
// Ritz vectors of previous iterations.
namespace unnamed
{
namespace
{

void orthogonalize_vec(arma::cx_dvec& r,
		       const arma::cx_mat& Q,
		       const arma::cx_mat& Chi)
{
    r -= Q * (Q.t() * r) + Chi * (Chi.t() * r); // Full reorthogonalization
    r -= Q * (Q.t() * r) + Chi * (Chi.t() * r); // Repeat for better results
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
