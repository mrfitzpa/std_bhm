// std_bhm/src/os/mkdir_p.cpp

// -----------------------------------------------------------------------

// The function mkdir_p(...) was taken from https://gist.github.com/
// JonathonReinhart/8c0d90191c38af2dcadb102c4e202950.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <cstddef>
#include <cstring>
#include <climits>
#include <cerrno>
#include <sys/stat.h>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "os/mkdir_p.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::os;

namespace unnamed
{
namespace
{

int check_pathname_length(const char *path);
int make_parent_directories(char *path);
int make_lowest_subdirectory(const char *path);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Create directory with pathname path and create any parent any directories
// if necessary.
namespace NSA1 = std_bhm::os;

int NSA1::mkdir_p(const char *path)
{
    if (::unnamed::check_pathname_length(path) == -1) { return -1; }

    char path_copy[PATH_MAX];
    strcpy(path_copy, path);
    
    if (::unnamed::make_parent_directories(path_copy) == -1) { return -1; }
    if (::unnamed::make_lowest_subdirectory(path_copy) == -1) { return -1; }
    
    return 0;

}



// Check to see if pathname length is does not go beyond the maximum allowable
// length (i.e. PATH_MAX).

namespace unnamed
{
namespace
{

int check_pathname_length(const char *path)
{
    const size_t len = std::strlen(path);
    char copy_of_original[PATH_MAX];
    
    if (len > sizeof(copy_of_original)-1) 
    {
        errno = ENAMETOOLONG;
        return -1; 
    }   

    return 0;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Make parent directories for pathname 'path'.

namespace unnamed
{
namespace
{

int make_parent_directories(char *path)
{
    char *char_ptr;
    for(char_ptr=path+1; *char_ptr; char_ptr++) 
    {
        if (*char_ptr == '/') 
	{
            *char_ptr = '\0'; // Temporarily truncate path
	    /* S_IRWXU = Read, write, execute/search by owner */
            if (mkdir(path, S_IRWXU) != 0)
	    {
                if (errno != EEXIST) // EEXIST = File exists
                    return -1; 
            }

            *char_ptr = '/';
        }
    }

    return 0;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Make lowest subdirectory specified in pathname 'path'.

namespace unnamed
{
namespace
{

int make_lowest_subdirectory(const char *path)
{
    /* S_IRWXU = Read, write, execute/search by owner */
    if (mkdir(path, S_IRWXU) != 0) 
    {
        if (errno != EEXIST) // EEXIST = File exists
            return -1; 
    }

    return 0;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
