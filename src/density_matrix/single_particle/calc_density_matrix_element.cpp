// std_bhm/src/density_matrix/single_particle/calc_density_matrix_element.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <cmath>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "density_matrix/single_particle/calc_density_matrix_element.h"
#include "k_map/gen_minimal_k_vec_set.h"
#include "n_k/calc_fourier_cos_sum.h"
#include "hopping/spatial_params.h"



// Calculate single-particle density matrix element.
namespace NSA1 = std_bhm::density_matrix::single_particle;
namespace NSA2 = NSA1::calc_density_matrix_element_detail;
namespace NSA3 = std_bhm::hopping;
namespace NSA4 = std_bhm::k_map;
namespace NSA5 = std_bhm::n_k;

using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

dbl_vec NSA2::calc_density_matrix_element(const int_vec& delta_r_ints,
					  const dbl_vec_2d& n_k_arrays,
					  int L)
{
    const auto d = delta_r_ints.size();
    const auto& sp_params = ::NSA3::spatial_params(L, d);

    const auto& k_vec_set = ::NSA4::gen_minimal_k_vec_set(sp_params);

    auto fourier_cos_sum_set = dbl_vec();
    for(const auto& k_vec : k_vec_set)
    {
	const auto fourier_cos_sum
	    = ::NSA5::calc_fourier_cos_sum(k_vec, delta_r_ints);
	fourier_cos_sum_set.push_back(fourier_cos_sum);
    }

    const auto Ns = n_k_arrays[0].size();

    auto density_matrix_element = dbl_vec();
    for(auto i=decltype(Ns){0}; i<Ns; i++)
    {
	auto sum = 0.0;
	
	const auto set_size = k_vec_set.size();
	for(auto k=decltype(set_size){0}; k<set_size; k++)
	    sum += fourier_cos_sum_set[k] * n_k_arrays[k][i];
	
	const auto num_of_sites = pow(L, d);
	density_matrix_element.push_back(sum / num_of_sites);
    }

    return density_matrix_element;
}
