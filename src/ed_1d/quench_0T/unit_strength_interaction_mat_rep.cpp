// /std_bhm/src/ed_1d/quench_0T/unit_strength_interaction_mat_rep.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include <limits>
#include <cstdlib>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/unit_strength_interaction_mat_rep.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "arma_support/conv.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;
using four_vec = std::array<int, 4>;
using four_vec_set = std::vector<four_vec>;

namespace unnamed
{
namespace
{

arma::sp_mat calc_eq_kk_tag_contribution(const ::NSA1::fock_basis& basis);
arma::sp_mat calc_neq_kk_tag_contribution(const ::NSA1::fock_basis& basis);

four_vec_set calc_eq_kk_tag_k_four_vec_set(int M);
four_vec_set calc_neq_kk_tag_k_four_vec_set(int M);

void calc_eq_kk_tag_col(int col, const ::NSA1::fock_basis& basis,
			int_vec& locs_std, dbl_vec& values_std,
			const four_vec_set& k_four_vec_set);
void calc_neq_kk_tag_col(int col, const ::NSA1::fock_basis& basis,
			 int_vec& locs_std, dbl_vec& values_std,
			 const four_vec_set& k_four_vec_set);

void scatter(const four_vec& k_four_vec,
	     double& scatter_coef,
	     int_vec& fock_state);

void update_neq_kk_tag_col_elems(dbl_vec& col_elems,
				 const four_vec& k_four_vec,
				 const ::NSA1::fock_basis& basis,
				 const int_vec& fock_state);

double symmetry_factor(const int_vec& state_before_scattering,
		       const int_vec& state_after_scattering);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate matrix representation of the interaction part of the BHM
// Hamiltonian where the interaction strength 'U' is set to unity.
namespace NSA1 = std_bhm::ed_1d::quench_0T;
namespace NSA2 = NSA1::unit_strength_interaction_mat_rep_detail;
namespace NSA3 = std_bhm::arma_support;

arma::sp_mat NSA2::unit_strength_interaction_mat_rep
                       (const ::NSA1::fock_basis& basis)
{
    auto mat_rep = unnamed::calc_eq_kk_tag_contribution(basis);
    mat_rep += unnamed::calc_neq_kk_tag_contribution(basis);

    return mat_rep;
}



// Calculate the 'equal kk tags' contribution to the total matrix
// representation.
namespace NSA1 = std_bhm::ed_1d::quench_0T;
namespace NSA3 = std_bhm::arma_support;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

arma::sp_mat calc_eq_kk_tag_contribution(const ::NSA1::fock_basis& basis)
{
    const auto M = basis.get_number_of_lattice_sites();
    const auto D = basis.get_hilbert_space_dimension();

    auto locs_std = int_vec();
    auto values_std = dbl_vec();

    const auto k_four_vec_set = ::unnamed::calc_eq_kk_tag_k_four_vec_set(M);

    locs_std.reserve(2 * D);
    values_std.reserve(D);
    
    for(auto col=decltype(D){0}; col<D; col++)
    {
	::unnamed::calc_eq_kk_tag_col(col, basis, locs_std,
				      values_std, k_four_vec_set);
    }

    auto locs_arma = ::NSA3::locs_std_to_locs_arma(locs_std);
    const auto values_arma = arma::conv_to<arma::dvec>::from(values_std);
    
    return arma::sp_mat(locs_arma, values_arma, D, D, true, false);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the k-four-vector set containing only those where
// (k1 k2) = (k3 k4) where (k1 k2) is a momentum pair tag.
using int_vec = std::vector<int>;
using four_vec = std::array<int, 4>;
using four_vec_set = std::vector<four_vec>;

namespace unnamed
{
namespace
{

four_vec_set calc_eq_kk_tag_k_four_vec_set(int M)
{
    const auto size = M * (M + 1) / 2;
    auto k_four_vec_set = four_vec_set();
    k_four_vec_set.reserve(size);
    
    for(auto k_1=decltype(M){0}; k_1<M; k_1++)
	for(auto k_2=decltype(k_1){0}; k_2<=k_1; k_2++)
	    k_four_vec_set.push_back( four_vec{k_1, k_2, k_1, k_2} );

    return k_four_vec_set;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate column of 'equal kk tag' matrix.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;
using four_vec = std::array<int, 4>;
using four_vec_set = std::vector<four_vec>;

namespace unnamed
{
namespace
{

void calc_eq_kk_tag_col(int col, const ::NSA1::fock_basis& basis,
			int_vec& locs_std, dbl_vec& values_std,
			const four_vec_set& k_four_vec_set)
{
    const auto M = basis.get_number_of_lattice_sites();
    
    auto fock_state = basis.get_fock_state(col);
    auto reflected_state = fock_state;
    std::reverse( reflected_state.begin()+1, reflected_state.end() );

    auto sum = 0.0;
    for(auto& k_four_vec : k_four_vec_set)
    {
	auto scatter_coef = double();
	::unnamed::scatter(k_four_vec, scatter_coef, fock_state);
	sum += scatter_coef;
	::unnamed::scatter(k_four_vec, scatter_coef, reflected_state);
	sum += scatter_coef;
    }

    const auto row = col;
    locs_std.push_back(row);
    locs_std.push_back(col);

    const auto mat_elem = sum / 4.0 / M;
    values_std.push_back(mat_elem);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the coefficient that comes from acting a B^{\dagger} B operator
// on a fock state.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

void scatter(const four_vec& k_four_vec,
	     double& scatter_coef,
	     int_vec& fock_state)
{
    const auto k_1 = k_four_vec[0];
    const auto k_2 = k_four_vec[1];
    const auto k_3 = k_four_vec[2];
    const auto k_4 = k_four_vec[3];

    auto& n_k_1 = fock_state.at(k_1);
    auto& n_k_2 = fock_state.at(k_2);
    auto& n_k_3 = fock_state.at(k_3);
    auto& n_k_4 = fock_state.at(k_4);

    scatter_coef = sqrt( double(n_k_4) );
    n_k_4 -= 1;
    scatter_coef *= sqrt( double( abs(n_k_3) ) );
    n_k_3 -= 1;
    scatter_coef *= sqrt( double( abs(n_k_2) ) + 1 );
    n_k_2 += 1;
    scatter_coef *= sqrt( double( abs(n_k_1) ) + 1 );
    n_k_1 += 1;

    if (k_1 != k_2)
	scatter_coef *= 2.0;
    if (k_3 != k_4)
	scatter_coef *= 2.0;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the 'non-equal kk tags' contribution to the total matrix
// representation.
namespace NSA1 = std_bhm::ed_1d::quench_0T;
namespace NSA3 = std_bhm::arma_support;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

arma::sp_mat calc_neq_kk_tag_contribution(const ::NSA1::fock_basis& basis)
{
    const auto M = basis.get_number_of_lattice_sites();
    const auto D = basis.get_hilbert_space_dimension();

    auto locs_std = int_vec();
    auto values_std = dbl_vec();
    
    const auto k_four_vec_set = ::unnamed::calc_neq_kk_tag_k_four_vec_set(M);

    const auto estimated_size = 2 * D * k_four_vec_set.size();
    locs_std.reserve(2 * estimated_size);
    values_std.reserve(estimated_size);
    
    for(auto col=decltype(D){0}; col<D; col++)
    {
	::unnamed::calc_neq_kk_tag_col(col, basis, locs_std,
				       values_std, k_four_vec_set);
    }

    auto locs_arma = ::NSA3::locs_std_to_locs_arma(locs_std);
    const auto values_arma = arma::conv_to<arma::dvec>::from(values_std);

    auto temp_mat = arma::sp_mat(locs_arma, values_arma, D, D, true, false);

    return temp_mat + temp_mat.t();
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the k-four-vector set containing only those where
// (k1 k2) != (k3 k4) where (k1 k2) is a momentum pair tag.
using int_vec = std::vector<int>;
using four_vec = std::array<int, 4>;
using four_vec_set = std::vector<four_vec>;

namespace unnamed
{
namespace
{

four_vec_set calc_neq_kk_tag_k_four_vec_set(int M)
{
    const auto num_of_kk_tags = M * M;
    const auto estimated_size = num_of_kk_tags * (num_of_kk_tags - 1) / 2;
    auto k_four_vec_set = four_vec_set();
    k_four_vec_set.reserve(estimated_size);
    
    for(auto tag_1=decltype(num_of_kk_tags){0}; tag_1<num_of_kk_tags; tag_1++)
    {
	for(auto tag_2=decltype(tag_1){0}; tag_2<tag_1; tag_2++)
	{
	    auto div_result = div(tag_1, M);
	    const auto k_1 = div_result.quot;
	    const auto k_2 = div_result.rem;

	    div_result = div(tag_2, M);
	    const auto k_3 = div_result.quot;
	    const auto k_4 = div_result.rem;

	    const auto delta_K = k_1 + k_2 - k_3 - k_4;
	    if ( (delta_K % M == 0) && (k_1 >= k_2) && (k_3 >= k_4) )
	    {
		k_four_vec_set.push_back( four_vec{k_1, k_2, k_3, k_4} );
	    }
	}
    }

    k_four_vec_set.shrink_to_fit();
    
    return k_four_vec_set;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate column of 'non-equal kk tag' matrix.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;
using four_vec = std::array<int, 4>;
using four_vec_set = std::vector<four_vec>;

namespace unnamed
{
namespace
{

void calc_neq_kk_tag_col(int col, const ::NSA1::fock_basis& basis,
			 int_vec& locs_std, dbl_vec& values_std,
			 const four_vec_set& k_four_vec_set)
{
    const auto M = basis.get_number_of_lattice_sites();
    const auto D = basis.get_hilbert_space_dimension();

    auto col_elems = dbl_vec(D, 0.0);
    
    auto fock_state = basis.get_fock_state(col);
    auto reflected_state = fock_state;
    std::reverse( reflected_state.begin()+1, reflected_state.end() );

    for(auto& k_four_vec : k_four_vec_set)
    {
	::unnamed::update_neq_kk_tag_col_elems(col_elems, k_four_vec,
					       basis, fock_state);
	::unnamed::update_neq_kk_tag_col_elems(col_elems, k_four_vec,
					       basis, reflected_state);
    }

    for(auto row=decltype(D){0}; row<D; row++)
    {
	const auto mat_elem = col_elems[row] / 4.0 / M;
	
	const auto tol = std::numeric_limits<double>::epsilon() * 10.0;
	if (std::fabs(mat_elem) > tol)
	{
	    locs_std.push_back(row);
	    locs_std.push_back(col);
	    values_std.push_back(mat_elem);
	}
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Update the elements in the current column.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

void update_neq_kk_tag_col_elems(dbl_vec& col_elems,
				 const four_vec& k_four_vec,
				 const ::NSA1::fock_basis& basis,
				 const int_vec& fock_state)
{
    auto scatter_coef = double();
    auto scattered_state = fock_state;
    ::unnamed::scatter(k_four_vec, scatter_coef, scattered_state);
    
    const auto tol = std::numeric_limits<double>::epsilon() * 10.0;
    if (std::fabs(scatter_coef) < tol)
	return;
	
    const auto row = basis.find_fock_state(scattered_state);
    const auto sym_factor = ::unnamed::symmetry_factor(fock_state,
						       scattered_state);
    
    col_elems[row] += sym_factor * scatter_coef;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Compute the 'symmetry' factor used to determine the matrix elements.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

double symmetry_factor(const int_vec& state_before_scattering,
		       const int_vec& state_after_scattering)
{
    auto reflected_state = state_before_scattering;
    std::reverse( reflected_state.begin()+1, reflected_state.end() );

    auto is_symmetric_before_scattering = false;
    if (state_before_scattering == reflected_state)
	is_symmetric_before_scattering = true;

    reflected_state = state_after_scattering;
    std::reverse( reflected_state.begin()+1, reflected_state.end() );

    auto is_symmetric_after_scattering = false;
    if (state_after_scattering == reflected_state)
	is_symmetric_after_scattering = true;

    if (is_symmetric_after_scattering == is_symmetric_before_scattering)
	return 1.0;
    else if (is_symmetric_before_scattering == true)
	return 1.0 / sqrt(2.0);
    else
	return sqrt(2.0);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
