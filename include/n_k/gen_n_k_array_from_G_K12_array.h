// std_bhm/include/n_k/gen_n_k_array_from_G_K12_array.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


#ifndef STD_BHM_N_K_WRITE_TO_FILE_FROM_G_K12_ARRAY_H
#define STD_BHM_N_K_WRITE_TO_FILE_FROM_G_K12_ARRAY_H

/* Include standard libraries */
#include <vector>
#include <complex>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace n_k
{
namespace gen_n_k_array_from_G_K12_array_detail
{

using dbl_vec = std::vector<double>;
using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

dbl_vec gen_n_k_array_from_G_K12_array(const cmplx_vec& G_K12_array);

} // end of gen_n_k_array_from_G_K12_array_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::n_k::gen_n_k_array_from_G_K12_array_detail::\
gen_n_k_array_from_G_K12_array;



} // end of n_k namespace
} // end of std_bhm namespace

#endif
