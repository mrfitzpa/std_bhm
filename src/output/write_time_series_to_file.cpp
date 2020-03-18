// std_bhm/src/output/write_time_series_to_file.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>
#include <cmath>
#include <string>
#include <fstream>
#include <limits>

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "output/write_time_series_to_file.h"
#include "os/mkdir_p.h"



// Write time series to file from data array (containing 'y' values only) and
// the timestep 'ds'.
namespace NSA1 = std_bhm::output::write_time_series_to_file_detail;
namespace NSA2 = std_bhm::os;

template <class T>
using vec = std::vector<T>;

template <class T>
void NSA1::write_time_series_to_file(const std::string& abs_filename,
				     const vec<T>& data_array,
				     double ds,
				     const std::string& data_label)
{
    const auto substr_index = abs_filename.find_last_of("/\\");
    const auto abs_directory_name = abs_filename.substr(0, substr_index);

    ::NSA2::mkdir_p( abs_directory_name.c_str() );

    std::ofstream ofs(abs_filename);
    typedef std::numeric_limits<double> dbl_lim;
    ofs.precision(dbl_lim::max_digits10);

    ofs << "time" << "\t" << data_label << std::endl;
    ofs << std::scientific;

    auto s = 0.0;
    for(const auto& data_value : data_array)
    {
	ofs << s << "\t" << data_value << std::endl;
	s += ds;
    }

    ofs.close();
}



// Explicit instantiations of the free public functions

// --- Explicit instantions of write_time_series_to_file(...) ---
namespace NSA1 = std_bhm::output::write_time_series_to_file_detail;

template <class T>
using vec = std::vector<T>;

template void
NSA1::write_time_series_to_file(const std::string& abs_filename,
				const vec<double>& data_array,
				double ds,
				const std::string& data_label="output");
