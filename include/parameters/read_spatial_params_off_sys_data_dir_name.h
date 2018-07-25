// std_bhm/include/parameters/read_spatial_params_off_sys_data_dir_name.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_PARAMETERS_READ_SPATIAL_PARAMS_OFF_SYS_DATA_DIR_NAME_H
#define STD_BHM_PARAMETERS_READ_SPATIAL_PARAMS_OFF_SYS_DATA_DIR_NAME_H

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{



namespace hopping
{
class spatial_params; // forward declaration
}



namespace parameters
{
namespace read_spatial_params_off_sys_data_dir_name_detail
{

namespace NSA1 = std_bhm::hopping;

NSA1::spatial_params read_spatial_params_off_sys_data_dir_name
                         (const std::string& abs_sys_data_set_dir_name);

} // end of read_spatial_params_off_sys_data_dir_name_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::parameters::read_spatial_params_off_sys_data_dir_name_detail::\
read_spatial_params_off_sys_data_dir_name;



} // end of parameters namespace
} // end of std_bhm namespace


#endif
 
