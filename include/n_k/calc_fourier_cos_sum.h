// std_bhm/include/n_k/calc_fourier_cos_sum.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_N_K_CALC_FOURIER_COS_SUM_H
#define STD_BHM_N_K_CALC_FOURIER_COS_SUM_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */


namespace std_bhm
{
namespace n_k
{
namespace calc_fourier_cos_sum_detail
{

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

double calc_fourier_cos_sum(const dbl_vec& k_vec, const int_vec& delta_r_ints);

} // end of calc_fourier_cos_sum_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::n_k::calc_fourier_cos_sum_detail::calc_fourier_cos_sum;



} // end of n_k namespace
} // end of std_bhm namespace


#endif
