// std_bhm/src/os/get_abs_path_of_exe.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <string>
#include <climits>
#include <unistd.h>
#include <stdexcept>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "os/get_abs_path_of_exe.h"



// Return absolute path of current program/executable.
namespace NSA1 = std_bhm::os;

std::string NSA1::get_abs_path_of_exe()
{
    try
    {
	char buff[PATH_MAX];
	const auto len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);

	if (len == -1)
	{
	    const auto message = ("Error occurred in a call to function "
				  "'std_bhm::os::get_abs_path_of_exe(...)': "
				  "an error occured upon calling the "
				  "'::readlink' function.\n\n");
	    throw std::runtime_error(message);
	}
	else
	    buff[len] = '\0';

	const auto abs_path = std::string{buff};

	return abs_path;
    }
    catch(std::runtime_error &ex) { throw; }

}
