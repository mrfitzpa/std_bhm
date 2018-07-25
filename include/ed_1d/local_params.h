// /std_bhm/include/ed_1d/local_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_LOCAL_PARAMS_H
#define STD_BHM_ED_1D_LOCAL_PARAMS_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{

class local_params
{
public:
    local_params(double mu, double U);

    double get_mu() const;
    double get_U() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
