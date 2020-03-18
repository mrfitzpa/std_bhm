// std_bhm/src/k_map/gen_minimal_k_ints_set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "k_map/gen_minimal_k_ints_set.h"
#include "hopping/spatial_params.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

namespace unnamed
{
namespace
{

void gen_minimal_k_ints_set_inner_loop(int depth,
				       std::vector<int>& k_ints, 
				       int max,
				       const int L,
				       int_vec_2d& k_ints_set);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace




// Generate a minimal array of the k-vectors.
namespace NSA1 = std_bhm::k_map::gen_minimal_k_ints_set_detail;
namespace NSA2 = std_bhm::hopping;

using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

int_vec_2d NSA1::gen_minimal_k_ints_set(const ::NSA2::spatial_params& sp_params)
{
    const auto L = sp_params.get_L();
    const auto d = sp_params.get_d();
    
    auto k_ints_set = int_vec_2d();
    auto k_ints = int_vec(d);
    
    ::unnamed::gen_minimal_k_ints_set_inner_loop(d, k_ints, L/2, L, k_ints_set);

    return k_ints_set;
}



// A recursive for-loop to generate a minimal array of k-vectors
using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

namespace unnamed
{
namespace
{

void gen_minimal_k_ints_set_inner_loop(int depth,
				      std::vector<int>& k_ints, 
				      int max,
				      const int L,
				      int_vec_2d& k_ints_set)
{
    if(depth > 0)
    {
	for(int i=0; i<=max; i++)
	{
	    int d = k_ints.size();
	    k_ints[d-depth] = i;
	    unnamed::gen_minimal_k_ints_set_inner_loop(depth-1, k_ints,
						       i, L, k_ints_set);
	}
    }
    else
    {
	k_ints_set.push_back(k_ints);
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
