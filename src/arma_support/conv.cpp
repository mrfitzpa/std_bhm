// std_bhm/src/arma_support/conv.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "arma_support/conv.h"



// Convert a std-style matrix to an arma-type matrix. Note that if the input
// argument does not have the shape of a matrix then the function will throw
// an exception.
namespace NSA1 = std_bhm::arma_support::conv_detail;

using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

arma::umat NSA1::std_int_vec_2d_to_arma_umat(const int_vec_2d& std_mat)
{
    const auto n_rows = std_mat.size();
    const auto n_cols = std_mat[0].size();

    auto arma_umat = arma::umat(n_rows, n_cols);

    for(auto i=decltype(n_rows){0}; i<n_rows; i++)
	for(auto j=decltype(n_cols){0}; j<n_cols; j++)
	    arma_umat(i, j) = std_mat[i][j];

    return arma_umat;
}



// Convert a set of coords originally stored as a 1D std::vector to a
// arma::umat format
namespace NSA1 = std_bhm::arma_support::conv_detail;

using int_vec = std::vector<int>;

arma::umat NSA1::locs_std_to_locs_arma(const int_vec& locs_std)
{
    const auto n_coords = locs_std.size() / 2;
    
    auto locs_arma = arma::umat(2, n_coords);

    for(auto i=decltype(n_coords){0}; i<n_coords; i++)
    {
	locs_arma(0, i) = locs_std[i * 2];
	locs_arma(1, i) = locs_std[i * 2 + 1];
    }

    return locs_arma;
}



// Convert dvec to cx_dvec.
namespace NSA1 = std_bhm::arma_support::conv_detail;

arma::cx_dvec NSA1::dvec_to_cx_dvec(const arma::dvec& vec)
{
    const auto zero_vec = arma::dvec(arma::size(vec), arma::fill::zeros);
    
    return arma::cx_dvec(vec, zero_vec);
}



// Convert sp_mat to sp_cx_mat.
namespace NSA1 = std_bhm::arma_support::conv_detail;

arma::sp_cx_mat NSA1::sp_mat_to_sp_cx_mat(const arma::sp_mat& mat)
{
    auto result = arma::sp_cx_mat( arma::size(mat) );
    result.set_real(mat);

    return result;
}
