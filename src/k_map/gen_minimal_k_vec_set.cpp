// std_bhm/src/k_map/gen_minimal_k_vec_set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <cmath>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "k_map/gen_minimal_k_vec_set.h"
#include "k_map/gen_minimal_k_ints_set.h"
#include "k_map/k_ints_to_k_vec.h"
#include "hopping/spatial_params.h"



// Generate a minimal array of the k-vectors.
namespace NSA1 = std_bhm::k_map::gen_minimal_k_vec_set_detail;
namespace NSA2 = std_bhm::hopping;
namespace NSA3 = std_bhm::k_map;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

dbl_vec_2d NSA1::gen_minimal_k_vec_set(const ::NSA2::spatial_params& sp_params)
{
    const auto k_ints_set = ::NSA3::gen_minimal_k_ints_set(sp_params);

    auto k_vec_set = dbl_vec_2d();
    for(auto k_ints : k_ints_set)
    {
	const auto L = sp_params.get_L();
	const auto k_vec = ::NSA3::k_ints_to_k_vec(k_ints, L);
	k_vec_set.push_back(k_vec);
    }

    return k_vec_set;
}
