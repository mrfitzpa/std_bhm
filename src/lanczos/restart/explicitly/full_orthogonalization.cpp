// /std_bhm/src/lanczos/restart/explicitly/full_orthogonalization.h

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
#include "lanczos/restart/explicitly/full_orthogonalization.h"
#include "lanczos/full_orthogonalization.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace unnamed
{
namespace
{

void set_new_x(arma::cx_dvec& x,
	       const arma::cx_mat& Chi,
	       const arma::cx_mat& isolated_eigvecs,
	       const arma::dvec& error_bounds,
	       arma::cx_mat& starting_candidate_vecs,
	       arma::dvec& starting_candidate_error_bounds);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Apply the Lanczos algorithm with full orthogonalization to calculate
// a maximum of 'p' eigen-pairs of the matrix A. 'q_0' is the starting vector
// and 'tol' is the convergence tolerance.
namespace NSA1 = std_bhm::lanczos;
namespace NSA2 = NSA1::restart::explicitly::full_orthogonalization_detail;

void NSA2::full_orthogonalization(const arma::sp_cx_mat& A,
				  arma::cx_dvec x,
				  int p,
				  arma::dvec& eigvals,
				  arma::cx_mat& eigvecs,
    				  double tol)
{
    auto Chi = arma::cx_mat(A.n_rows, 1, arma::fill::zeros);
    auto isolated_eigvals = arma::dvec();
    auto isolated_eigvecs = arma::cx_mat();
    auto error_bounds = arma::dvec();
    auto starting_candidate_vecs = arma::cx_mat();
    auto starting_candidate_error_bounds = arma::dvec();
    auto n_locked_eigpairs = 0;

    while(n_locked_eigpairs < p)
    {
	::NSA1::full_orthogonalization(A, Chi, x, isolated_eigvals,
				       isolated_eigvecs, error_bounds, tol);

	const auto n_isolated_eigpairs = isolated_eigvecs.n_cols;
	if (n_isolated_eigpairs >= 1)
	{
	    const auto locked_eigvec = isolated_eigvecs.col(0);
	    if (n_locked_eigpairs == 0)
		Chi.col(0) = locked_eigvec;
	    else
		Chi.insert_cols(n_locked_eigpairs, locked_eigvec);

	    eigvals.resize(n_locked_eigpairs + 1);
	    eigvals(n_locked_eigpairs) = isolated_eigvals(0);
	    n_locked_eigpairs += 1;
	}

	::unnamed::set_new_x(x,
			     Chi,
			     isolated_eigvecs,
			     error_bounds,
			     starting_candidate_vecs,
			     starting_candidate_error_bounds);
    }
    
    eigvecs = Chi;
}




// Set a new 'x' starting vector.
namespace unnamed
{
namespace
{

void set_new_x(arma::cx_dvec& x,
	       const arma::cx_mat& Chi,
	       const arma::cx_mat& isolated_eigvecs,
	       const arma::dvec& error_bounds,
	       arma::cx_mat& starting_candidate_vecs,
	       arma::dvec& starting_candidate_error_bounds)
{
    const auto n_isolated_eigpairs = isolated_eigvecs.n_cols;
    if (n_isolated_eigpairs == 2)
    {
	const auto end_index = starting_candidate_vecs.n_cols;
	starting_candidate_vecs.insert_cols( end_index,
					     isolated_eigvecs.col(1) );
	starting_candidate_error_bounds.resize(end_index + 1);
	starting_candidate_error_bounds(end_index) = error_bounds(1);
    }

    const auto n_starting_candidate_vecs = starting_candidate_vecs.n_cols;
    if (n_starting_candidate_vecs == 0)
    {
	x.randu();
    }
    else
    {
	const auto chosen_index
	    = starting_candidate_error_bounds.index_min();
	x = starting_candidate_vecs.col(chosen_index);
	starting_candidate_vecs.shed_col(chosen_index);
	starting_candidate_error_bounds.shed_row(chosen_index);
    }
	
    x -= Chi * (Chi.t() * x);
    x = arma::normalise(x);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
