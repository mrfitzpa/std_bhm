// std_bhm/src/parameters/read_spatial_params_off_sys_data_dir_name.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <string>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "parameters/read_spatial_params_off_sys_data_dir_name.h"
#include "hopping/spatial_params.h"



// Read-off spatial parameters (i.e. L and d) from the given directory name.
namespace NSA1 = std_bhm::parameters;
namespace NSA2 = NSA1::read_spatial_params_off_sys_data_dir_name_detail;
namespace NSA3 = std_bhm::hopping;

NSA3::spatial_params NSA2::read_spatial_params_off_sys_data_dir_name
                               (const std::string& abs_sys_data_set_dir_name)
{
    const auto index_1 = abs_sys_data_set_dir_name.find_last_of("/\\");
    
    const auto index_2 = abs_sys_data_set_dir_name.find("d_", index_1);
    const auto index_3 = abs_sys_data_set_dir_name.find(" ", index_2);
    const auto d_str = abs_sys_data_set_dir_name.substr(index_2 + 2,
							index_3 - index_2 - 2);
    const auto d = std::stoi(d_str);

    const auto index_4 = abs_sys_data_set_dir_name.find("L_", index_1);
    const auto index_5 = abs_sys_data_set_dir_name.find(" ", index_4);
    const auto L_str = abs_sys_data_set_dir_name.substr(index_4 + 2,
							index_5 - index_4 - 2);
    const auto L = std::stoi(L_str);

    return ::NSA3::spatial_params(L, d);
}
