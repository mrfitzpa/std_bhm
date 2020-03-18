// std_bhm/include/n_k/write_n_k_array_to_file.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


#ifndef STD_BHM_N_K_WRITE_N_K_ARRAY_TO_FILE_H
#define STD_BHM_N_K_WRITE_N_K_ARRAY_TO_FILE_H

/* Include standard libraries */
#include <vector>
#include <string>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace n_k
{
namespace write_n_k_array_to_file_detail
{

using dbl_vec = std::vector<double>;

void write_n_k_array_to_file(const std::string& abs_filename,
			     const dbl_vec& n_k_array,
			     double ds);

} // end of write_n_k_array_to_file_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::n_k::write_n_k_array_to_file_detail::\
write_n_k_array_to_file;



} // end of n_k namespace
} // end of std_bhm namespace

#endif
