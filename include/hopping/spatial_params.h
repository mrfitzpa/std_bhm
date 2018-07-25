// /std_bhm/include/hopping/spatial_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_HOPPING_SPATIAL_PARAMS_H
#define STD_BHM_HOPPING_SPATIAL_PARAMS_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace hopping
{

class spatial_params
{
public:
    spatial_params(int L, int d);

    int get_L() const;
    int get_d() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of hopping namespace
} // end of std_bhm namespace


#endif
 
