// std_bhm/src/n_k/calc_fourier_cos_sum.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <cmath>
#include <algorithm>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "n_k/calc_fourier_cos_sum.h"


// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

void gen_negated_variants_inner_loop(int depth,
				     int_vec& zeros_and_ones,
				     const dbl_vec& k_vec,
				     dbl_vec_2d& negated_variants);
void negate_and_store_if_not_duplicate(const int_vec& zeros_and_ones,
				       const dbl_vec& k_vec,
				       dbl_vec_2d& negated_variants);

dbl_vec_2d gen_permuted_negated_variants(dbl_vec_2d& negated_variants);

double calc_sum(const int_vec& delta_r_ints,
		const dbl_vec_2d& permuted_negated_variants);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace




// Calculate the fourier "cos sum" necessary to calculate the single-particle
// density matrix from the quasi-momentum distribution "n_k".
namespace NSA1 = std_bhm::n_k::calc_fourier_cos_sum_detail;

using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

double NSA1::calc_fourier_cos_sum(const dbl_vec& k_vec,
				  const int_vec& delta_r_ints)
{
    const auto d = k_vec.size();
    auto negated_variants = dbl_vec_2d();
    auto zeros_and_ones = int_vec(d);
    ::unnamed::gen_negated_variants_inner_loop(d,
					       zeros_and_ones,
					       k_vec,
					       negated_variants);

    const auto& permuted_negated_variants
	= ::unnamed::gen_permuted_negated_variants(negated_variants);

    return ::unnamed::calc_sum(delta_r_ints, permuted_negated_variants);
}




// Generate all "related" k-vectors to the one passed. By relevant, we mean
// all k-vectors related to the one passed by reflections and permutations.
using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

void gen_negated_variants_inner_loop(int depth,
				     int_vec& zeros_and_ones,
				     const dbl_vec& k_vec,
				     dbl_vec_2d& negated_variants)
{
    if(depth > 0)
    {
	for(auto i=decltype(1){0}; i<=1; i++)
	{
	    const auto d = k_vec.size();
	    zeros_and_ones[d-depth] = i;
	    unnamed::gen_negated_variants_inner_loop(depth-1, zeros_and_ones,
						     k_vec, negated_variants);
	}
    }
    else
    {
	unnamed::negate_and_store_if_not_duplicate(zeros_and_ones,
						   k_vec,
						   negated_variants);
    }    
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Negate the k-vector based on the negation sequence specified by the
// vector-array 'zeros_and_ones'. If this negated variant is not a duplicate
// of one of the k-vectors in 'negated_variants' then append negated variant
// to 'negated_variants'.
using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

void negate_and_store_if_not_duplicate(const int_vec& zeros_and_ones,
				       const dbl_vec& k_vec,
				       dbl_vec_2d& negated_variants)
{
    const auto tol = 1.0e-15;
    
    const auto d = k_vec.size();
    auto negated_variant = dbl_vec();

    for(auto i=decltype(d){0}; i<d; i++)
    {
	const auto k_value = k_vec[i];
	const auto pi = atan(1.0) * 4.0;
	const auto temp_diff = std::abs(pi - k_value);
	if ( (k_value != 0.0) && (temp_diff > tol) )
	    negated_variant.push_back( (1 - 2 * zeros_and_ones[i]) * k_value );
	else
	    negated_variant.push_back(k_value);
    }

    const auto itr = std::find(negated_variants.begin(),
			       negated_variants.end(),
			       negated_variant);

    if ( itr == negated_variants.end() )
	negated_variants.push_back(negated_variant);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Iterate all the permutations of each vector-array in 'negated_variants'
// and store all these permutations (including the original negated variants)
// in 'permuted_negated_variants'.
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

dbl_vec_2d gen_permuted_negated_variants(dbl_vec_2d& negated_variants)
{
    auto permuted_negated_variants = dbl_vec_2d();
    for(auto& negated_variant : negated_variants)
    {
	std::sort( negated_variant.begin(), negated_variant.end() );
	const auto itr = std::find(permuted_negated_variants.begin(), 
				   permuted_negated_variants.end(),
				   negated_variant);
	if ( itr == permuted_negated_variants.end() )
	    permuted_negated_variants.push_back(negated_variant);

	while ( std::next_permutation(negated_variant.begin(), 
				      negated_variant.end() ) )
	{
	    const auto itr = std::find(permuted_negated_variants.begin(), 
				       permuted_negated_variants.end(),
				       negated_variant);
	    if ( itr == permuted_negated_variants.end() )
		permuted_negated_variants.push_back(negated_variant);
	}
    }

    return permuted_negated_variants;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the "cos sum" for a particular k-vector and all of its
// permuted+negated variants and then store this sum into 'fourier_cos_sums'.
using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

double calc_sum(const int_vec& delta_r_ints,
		const dbl_vec_2d& permuted_negated_variants)
{
    auto fourier_cos_sum = 0.0;
    for(const auto& variant : permuted_negated_variants)
    {
	auto cos_arg = 0.0;
	const auto d = variant.size();
	for(auto i=decltype(d){0}; i<d; i++)
	    cos_arg += variant[i] * delta_r_ints[i];
	fourier_cos_sum += std::cos(cos_arg);
    }

    return fourier_cos_sum;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
