// /std_bhm/test/n_k/calc_fourier_cos_sum.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/n_k/calc_fourier_cos_sum.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "n_k/calc_fourier_cos_sum.h"
#include "output/vector_to_string.h"
#include "parameters/from_std_cin.h"
#include "k_map/k_ints_to_k_vec.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

void print_fourier_cos_sums_inner_loop(int depth,
				       int_vec& k_ints,
				       int max,
				       int L,
				       const int_vec& delta_r_ints);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Main function.
namespace NSA1 = std_bhm::n_k;
namespace NSA2 = std_bhm::parameters::from_std_cin;
namespace NSA3 = std_bhm::output;

using int_vec = std::vector<int>;

int main(int argc, char** argv)
{
    const auto L = ::NSA2::to_value<int>();
    const auto d = ::NSA2::to_value<int>();
    
    auto delta_r_ints = int_vec();
    for(auto i=decltype(d){0}; i<d; i++)
	delta_r_ints.push_back( ::NSA2::to_value<int>() );

    auto k_ints = int_vec(d);

    std::cout << "Testing the function "
	      << "'std_bhm::n_k::calc_fourier_cos_sum(...)': \n"
	      << std::endl;

    std::cout << "Results are for L = " << L << ",\tdelta_r_ints = "
	      << ::NSA3::vector_1d_to_string(delta_r_ints) << ":\n"
	      << std::endl;
    
    ::unnamed::print_fourier_cos_sums_inner_loop(d, k_ints,
						 L/2, L, delta_r_ints);
}



// Print all fourier cos sums associated with the given delta_r_ints.
namespace NSA1 = std_bhm::n_k;
namespace NSA3 = std_bhm::output;
namespace NSA4 = std_bhm::k_map;

using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

void print_fourier_cos_sums_inner_loop(int depth,
				       int_vec& k_ints,
				       int max,
				       int L,
				       const int_vec& delta_r_ints)
{
    if(depth > 0)
    {
	for(auto i=decltype(max){0}; i<=max; i++)
	{
	    const auto d = k_ints.size();
	    k_ints[d-depth] = i;
	    unnamed::print_fourier_cos_sums_inner_loop(depth-1, k_ints,
						       i, L, delta_r_ints);
	}
    }
    else
    {
	const auto k_vec = ::NSA4::k_ints_to_k_vec(k_ints, L);
	const auto fourier_cos_sum
	    = ::NSA1::calc_fourier_cos_sum(k_vec, delta_r_ints);
	
	typedef std::numeric_limits<double> dbl_lim;
	std::cout.precision(dbl_lim::max_digits10);
	std::cout << "k-ints = " << ::NSA3::vector_1d_to_string(k_ints)
		  << ", fourier-cos-sum = " << fourier_cos_sum << std::endl;
    }    
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
