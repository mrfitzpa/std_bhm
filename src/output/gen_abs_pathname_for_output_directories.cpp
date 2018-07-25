// std_bhm/src/output/gen_abs_pathname_for_output_directories.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <string>

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "output/gen_abs_pathname_for_output_directories.h"
#include "os/get_abs_path_of_exe.h"
#include "str_ops/replace.h"



// Gen_Abserate pathname for output directories.
namespace NSA1 = std_bhm::output;
namespace NSA2 = std_bhm::os;
namespace NSA3 = std_bhm::str_ops;

std::string NSA1::gen_abs_pathname_for_output_directories()
{
    const auto abs_path_of_exe = ::NSA2::get_abs_path_of_exe();
    const auto substr_index = abs_path_of_exe.find_last_of("/\\");
    auto abs_pathname_for_output_directories
	= abs_path_of_exe.substr(0, substr_index);
    ::NSA3::replace(abs_pathname_for_output_directories, "/bin/", "/data/");

    return abs_pathname_for_output_directories;
}
