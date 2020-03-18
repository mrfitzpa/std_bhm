// std_bhm/include/output/vector_to_string.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


#ifndef STD_BHM_OUTPUT_VECTOR_TO_STRING_H
#define STD_BHM_OUTPUT_VECTOR_TO_STRING_H

/* Include standard libraries */
#include <vector>
#include <string>
#include <complex>

/* Non-standard third-party libraries */

/* Include user-defined header files */


namespace std_bhm
{
namespace output
{
namespace vector_to_string_detail
{

template <class T>
using vector_1d = std::vector<T>;

template <class T>
std::string vector_1d_to_string(vector_1d<T> vec_1d);
template <class T>
std::string vector_1d_to_string(vector_1d< std::complex<T> > vec_1d);



template <class T>
using vector_2d = std::vector< std::vector<T> >;

template <class T>
std::string vector_2d_to_string(vector_2d<T> vec_2d);

} // end of vector_to_string_detail namespace

// lift relevant classes and functions up one namespace
using std_bhm::output::vector_to_string_detail::vector_1d_to_string;
using std_bhm::output::vector_to_string_detail::vector_2d_to_string;

} // end of output namespace
} // end of std_bhm namespace

#endif
