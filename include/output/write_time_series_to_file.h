// std_bhm/include/output/write_time_series_to_file.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


#ifndef STD_BHM_OUTPUT_WRITE_TIME_SERIES_TO_FILE_H
#define STD_BHM_OUTPUT_WRITE_TIME_SERIES_TO_FILE_H

/* Include standard libraries */
#include <vector>
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace output
{
namespace write_time_series_to_file_detail
{

template <class T>
using vec = std::vector<T>;

template <class T>
void write_time_series_to_file(const std::string& abs_filename,
			       const vec<T>& data_array,
			       double ds,
			       const std::string& data_label="output");

} // end of write_time_series_to_file_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::output::write_time_series_to_file_detail::\
write_time_series_to_file;



} // end of output namespace
} // end of std_bhm namespace

#endif
